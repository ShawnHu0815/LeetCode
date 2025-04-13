//
// Created by Shawn Hu on 2025/4/13.
//

#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <string>
using namespace std;

class W445Q2 : public ILeetCodeQuestion {
public:
    void run() override {
        // 示例 1
        string s1 = "z";
        cout << "输入: " << s1 << endl;
        cout << "输出: " << getLexicographicallySmallestPalindrome(s1) << endl;

        // 示例 2
        string s2 = "babab";
        cout << "输入: " << s2 << endl;
        cout << "输出: " << getLexicographicallySmallestPalindrome(s2) << endl;

        // 示例 3
        string s3 = "daccad";
        cout << "输入: " << s3 << endl;
        cout << "输出: " << getLexicographicallySmallestPalindrome(s3) << endl;
    }

private:
    static string getLexicographicallySmallestPalindrome(const string& s) {
        int dic[26] = {0};
        int n = s.length();
        // 统计出现的字符数量
        for (int i = 0; i < n; ++i) {
            dic[s.at(i) - 'a']++;
        }
        char mid = '\0'; // 用于记录中间字符，仅奇数字符串时启用
        string result;
        string first;
        // 遍历所有字符
        for (int i = 0; i < 26; ++i) {
            if (dic[i] %2 == 1)mid = (char)('a' + i); // 如果是奇数，记录中间字符
            int num = dic[i] / 2; // 偶数个字符
            for (int j = 0; j < num; ++j) { // 添加到前半部分
                first += (char)('a' + i);
            }
        }
        // 逆转前半部分，得到后半部分
        string second = {first.rbegin(), first.rend()};

        // 拼接结果，如果是偶数个字符，直接拼接前后两部分
        if(mid == '\0')result = first + second;
        // 如果是奇数个字符，拼接前半部分+中间字符+后半部分
        else result = first + mid + second;

        return result;
    }
};