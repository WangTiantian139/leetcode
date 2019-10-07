#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *  Example:
 *  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *  Output: 7 -> 0 -> 8
 *  Explanation: 342 + 465 = 807.
 */
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int num1 = 0;
        int num2 = 0;
        int sum = 0;
        int over = 0;
        ListNode *header = new ListNode(0);
        ListNode *itr = header;
        while (l1 != NULL || l2 != NULL)
        {
            
            // if (l1 == NULL)
            // {
            //     num1 = 0;
            //     num2 = l2->val;
            //     l2 = l2->next;
            // }
            // else if (l2 == NULL)
            // {
            //     num1 = l1->val;
            //     num2 = 0;
            //     l1 = l1->next;
            // }
            // else
            // {
            //     num1 = l1->val;
            //     num2 = l2->val;
            //     l1 = l1->next;
            //     l2 = l2->next;
            // }
            num1 = (l1 == NULL) ? 0 : l1->val;
            num2 = (l2 == NULL) ? 0 : l2->val;
            l1 = (l1 == NULL) ? NULL : l1->next;
            l2 = (l2 == NULL) ? NULL : l2->next;
            
            sum = (num1 + num2 + over) % 10;
            over = (num1 + num2 + over) / 10;
            itr->next = new ListNode(sum);
            itr = itr->next;
            std::cout << itr->val << "(" << sum << "+" << over << ") ";
        }
        if (over > 0)
        {
            itr->next = new ListNode(over);
            itr = itr->next;
            std::cout << itr->val << " ";
        }
        std::cout << std::endl;
        return header->next;
    }
};

class List
{
  private:
    ListNode *header;

  public:
    List()
    {
        this->header = new ListNode(0);
        header->next = NULL;
    }
    ListNode *first() const { return this->header->next; }
    ListNode *last() const
    {
        ListNode *itr = this->header;
        while (itr->next != NULL)
        {
            itr = itr->next;
        }
        return itr;
    }
};

using namespace std;

ostream& PrintList(ostream &os,List &lst)
{
    ListNode *itr = lst.first();
    while (itr != NULL)
    {
        os << itr->val << " ";
        itr = itr->next;
    }
    return os;
}

int main()
{
    Solution solu;
    ListNode *l1;
    ListNode *l2;
    int target;
    int n = -1;
    List lst1;
    List lst2;
    ListNode *ptr_t;

    cout << "Input integer numbers as l1, type -1 as the end:" << endl;
    while (true)
    {
        cin >> n;
        if (n > 0)
        {
            ptr_t = new ListNode(n);
            lst1.last()->next = ptr_t;
        }
        else
        {
            break;
        }
    }
    cout << "List: ";
    PrintList(cout, lst1) << endl;

    cout << "Input integer numbers as l2, type -1 as the end:" << endl;
    while (true)
    {
        cin >> n;
        if (n > 0)
        {
            ptr_t = new ListNode(n);
            lst2.last()->next = ptr_t;
        }
        else
        {
            break;
        }
    }
    cout << "List: ";
    PrintList(cout, lst2) << endl;

    l1 = lst1.first();
    l2 = lst2.first();

    ListNode *ans = solu.addTwoNumbers(l1, l2);
    cout << "ans is :" << endl;
    ListNode *itr = ans;
    while (itr != NULL)
    {
        cout << itr->val << " ";
        itr = itr->next;
    }
    cout << endl;
    return 0;
}