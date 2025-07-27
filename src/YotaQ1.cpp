//
// Created by Shawn Hu on 2025/7/26.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class YotaQ1: public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    void solution() {
        string s;
        cin >> s;
        stack<char> stk;
        for(char c:s){
            if(stk.empty())stk.push(c);
            else if(stk.top() == c) stk.pop();
            else stk.push(c);
        }
        if(stk.empty()){
            cout << "Null" << endl;
        }else{
            string result;
            while(!stk.empty()){
                result += stk.top();
                stk.pop();
            }
            reverse(result.begin(), result.end());
            cout << result << endl;
        }
    }
};