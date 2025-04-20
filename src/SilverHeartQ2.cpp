//
// Created by Shawn Hu on 2025/4/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
using namespace std;

class SilverHeartQ2 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        solution();
    }

private:
    void solution() {
        // 题目的具体实现
        int n;
        cin >> n;
        deque<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        vector<int> B(n);
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        int ans = 0;
        for (int i = 0; i < n-1; ++i) {
            int left = A.front();
            int right = A.back();
            int bi = B[i];
            if(bi <= B[i+1]){
                if(left < right){
                    ans += left * bi;
                    A.pop_front();
                }else{
                    ans += right * bi;
                    A.pop_back();
                }
            } else {
                if(left > right){
                    ans += left * bi;
                    A.pop_front();
                }else{
                    ans += right * bi;
                    A.pop_back();
                }
            }
        }
        ans += A.front() * B.back();
        cout << ans << endl;
    }
};