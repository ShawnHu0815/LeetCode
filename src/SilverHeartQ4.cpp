//
// Created by Shawn Hu on 2025/4/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <map>
using namespace std;

class SilverHeartQ4 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        solution();
    }

private:
    // 判断是否是回文串
    bool isPalindrome(const string& str) {
        int left = 0;
        int right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    void solution() {
        string S;
        string T;
        cin >> S >> T;
        int n = S.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            string newStr = S.substr(0, i) + T + S.substr(i);
            if (isPalindrome(newStr)) {
                ans++;
            }
        }
        string newStr = S + T;
        if(isPalindrome(newStr)) {
            ans++;
        }
        cout << ans << endl;
    }
};