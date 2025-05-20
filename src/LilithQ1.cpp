//
// Created by Shawn Hu on 2025/5/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <unordered_set>
#include <iostream>

using namespace std;

class LilithQ1 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    void solution() {
        int n;
        cin >> n;
        int multi = 0;
        unordered_set<int> set;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if(set.contains(num))multi++;
            set.insert(num);
        }
        int count = set.size();
        if (count < 3) {
            cout << 0 << endl;
            return;
        }else{
            int ans = count * (count - 1) * (count - 2) / 6;
            cout << ans * multi << endl;
        }
    }
};