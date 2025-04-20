//
// Created by Shawn Hu on 2025/4/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
using namespace std;

class SilverHeartQ1 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        solution();
    }

private:
    int findMiddle(vector<int> vec){
        sort(vec.begin(), vec.end());
        int n = vec.size();
        if(n%2 == 1)return vec[n/2];
        else return vec[n/2 -1];
    }

    void solution() {
        // 题目的具体实现
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for(int len = 1; len <= n - i; ++len){
                vector<int> subVec(vec.begin() + i, vec.begin() + i + len);
                int mid = findMiddle(subVec);
                ans += mid;
            }
        }
        cout << ans << endl;
    }
};