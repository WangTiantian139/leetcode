
/*

  Author: Mcdragon

  Date: 16-07-11 00:15

  Description: 求一个字符串中出现次数最多的子串(并不是连续的).



  问题描述：

	求一个字符串中连续出现次数最多的子串，子串的长度可以是 1 。



  分析问题：

	简单的穷举效率太低，随着输入的文本增长，时间复杂度和空间复杂度就会火箭般窜升至无法接受的地步。



	我们需要寻找规律。



	假设存在一个长度为 N 的子串 S 出现的次数最多。那么它具有哪些特点呢？



	S 的任一子串的出现次数不少于 S 的出现次数

	S 中不会出现重复的子串字符

	S 中不会出现重复的字符

	组成 S 的每一个字符、每一个子串的出现次数都和 S 一样

	“S 中不会出现重复的字符”，“组成 S 的每一个字符、每一个子串的出现次数都和 S 一样”！

	有了这个结论，问题就简单了。

  算法描述：

	找到文本中的出现次数最高的单个字符组成的子串，放入一个队列中，

	从队列的头部开始，对结果集中的每一个子串 S 进行处理

	找到文本中该子串出现的任意一个位置 P，

	判断文本中紧随 S 之后的字符 C 是否的出现次数是最多的，

	如果 C 的出现次数不是最多的，结束。



	如果 C 的出现次数是最多的，搜索文本中的每一个 S 并判断紧随其后的字符是否是 C，

	如果文本中的每一个 S 之后都存在字符 C ，将 S + C 生成的子串放入结果集中，

	如果文本中出现 S 之后的字符不是 C ，结束。

	如此，直至到达队列尾。

*/

#include <iostream>
#include <string>
#include <cstring>
#include <deque>
using namespace std;
typedef deque<string> strlist;
const int npos = -1;
const string ignoreChars(" /t/n/r");
inline bool IgnoreChar(char c)
{
    return (ignoreChars.find(c) != npos);
}

/*
 * 统计字符出现次数
 */

unsigned CharSummary(const string &text, unsigned usecount[], int tbllen)
{
    unsigned count, i;
    memset(usecount, 0, tbllen * sizeof(unsigned));
    for (i = 0; i < text.length(); usecount[unsigned(text[i++])]++)
        ;
    for (count = i = 0; i < 256; i++)
    {
        if (IgnoreChar(i))
            continue;
        if (usecount[i] > count)
            count = usecount[i];
    }
    return count;
}

int main()
{
    unsigned usecount[256];
    unsigned count, i;
    string text = "aba";
    strlist result;
    /*
    * 统计字符出现次数
    */
    cin >> text;
    count = CharSummary(text, usecount, sizeof(usecount) / sizeof(*usecount));
    cout << count << endl;
    return 0;
}
