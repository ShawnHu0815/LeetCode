//
// Created by Shawn Hu on 2025/8/3.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class BairimengQ1 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        cout << solve("1101", "1100") << endl; // 示例调用
    }

private:
    string solve(string str1, string str2) {
        int cur = 0;
        int carry = 0;
        string result;
        while(cur < str1.size() || cur < str2.size() || carry) {
            int sum = carry;
            if (cur < str1.size()) {
                sum += str1[str1.size() - 1 - cur] - '0';
            }
            if (cur < str2.size()) {
                sum += str2[str2.size() - 1 - cur] - '0';
            }
            result.push_back(sum % 2 + '0');
            carry = sum / 2;
            cur++;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};