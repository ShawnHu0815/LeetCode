//
// Created by Shawn Hu on 2025/4/22.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class LemonQ4 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        solution();
    }

private:
    void solution() {
        int n;
        cin >> n;
        vector<int> nums(n);
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            s.insert(nums[i]);
        }

        for (int i = 0; i < n - 1; ++i) {
            int num = nums[i];
            auto it = s.upper_bound(num);
            int minNum = it == s.end() ? -1 : *it;
            printf("%d ", minNum);
            s.erase(s.find(num));
        }
        printf("%d\n", -1);
    }
};