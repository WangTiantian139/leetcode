/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int lo1 = 0, lo2 = 0, n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
        {
            auto t = nums1;
            nums1 = nums2;
            nums2 = t;
        }
        while (n2 >= 6)
        {
            if (2 * n1 < n2)
            {
                lo2 = lo2 + (n2 - n1 -1) / 2;
                n2 = n1 + 2 - (n2 - n1) % 2;
            }

            int mi1 = lo1 + n1 / 2;
            int mi2a = lo2 + (n1 - 1) / 2;
            int mi2b = lo2 + n2 - 1 - n1 / 2;
            if (nums1[mi1] > nums2[mi2b])
            {
                lo1 = lo1;
                n1 = n1 / 2 + 1;
                lo2 = mi2a;
                n2 = n2 - (n1 - 1) / 2;
            } else if (nums1[mi1] < nums2[mi2a])
            {
                lo1 = mi1;
                n1 = (n1 + 1) / 2;
                lo2 = lo2;
                n2 = n2 - n1 / 2;
            } else
            {
                lo2 = mi2a;
                n2 = n2 - (n1 - 1) / 2 * 2;
            }

            if (n1 > n2)
            {
                auto t = nums1;
                nums1 = nums2;
                nums2 = t;
            }
        }

        return trivialMedian(nums1, lo1, n1, nums2, lo2, n2);
    }

private:
    double trivialMedian(vector<int> &nums1, int lo1, int n1, 
                            vector<int> &nums2, int lo2, int n2)
    {
        int hi1 = lo1 + n1;
        int hi2 = lo2 + n2;
        vector<int> nums;
        while ((lo1 < hi1) && (lo2 < hi2))
        {
            while ((lo1 < hi1) && nums1[lo1] <= nums2[lo2]) 
            {
                nums.push_back(nums1[lo1]);
                lo1++;
            }
            while ((lo2 < hi2) && nums2[lo2] <= nums1[lo1])
            {
                nums.push_back(nums2[lo2]);
                lo2++;
            }
        }
        while (lo1 < hi1)
        {
            nums.push_back(nums1[lo1++]);
        }
        while (lo2 < hi2)
        {
            nums.push_back(nums2[lo2++]);
        }
        return (n1 + n2) % 2 == 0 ? 
            (0.5 * nums[(n1 + n2) / 2] + 0.5 * nums[(n1 + n2) / 2 - 1]) 
            : nums[(n1 + n2) / 2];
    }
    
    double median(vector<int> &nums1, int lo1, int n1, 
                            vector<int> &nums2, int lo2, int n2)
    {
        if (n1 > n2) 
        {
            return median(nums2, lo2, n2, nums1, lo1, n1);
        }
        if (n2 < 6)
        {
            return trivialMedian(nums1, 0, nums1.size(), nums2, 0, nums2.size());
        }
        if (2 * n1 < n2)
        {
            lo2 = lo2 + (n2 - n1 -1) / 2;
            n2 = n1 + 2 - (n2 - n1) % 2;
        }
        int mi1 = lo1 + n1 / 2;
        int mi2a = lo2 + (n1 - 1) / 2;
        int mi2b = lo2 + n2 - 1 - n1 / 2;
        if (nums1[mi1] > nums2[mi2b])
        {
            return median(nums1, lo1, n1 / 2 + 1, nums2, mi2a, n2 - (n1 - 1) / 2);
        } else if (nums1[mi1] < nums2[mi2a])
        {
            return median(nums1, mi1, (n1 + 1) / 2, nums2, lo2, n2 - n1 / 2);
        } else
        {
            return median(nums1, lo1, n1, nums2, mi2a, n2 - (n1 - 1) / 2 * 2);
        }
    }

};


int main()
{
    vector<int> nums1({1, 2, 5, 6, 9, 10, 11});
    vector<int> nums2({3, 4, 7, 8});
    Solution solu;
    cout << solu.findMedianSortedArrays(nums1, nums2);
}