//
// Created by Shawn Hu on 2025/4/13.
//

#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <cmath> // 用于计算绝对值
using namespace std;

class W445Q1 : public ILeetCodeQuestion {
public:
    void run() override {
        int x, y, z;
        cout << "请输入 x, y, z 的值：" << endl;
        cin >> x >> y >> z;

        // 调用未实现的逻辑函数
        int result = whoWillReachFirst(x, y, z);

        if (result == 1) {
            cout << "第 1 个人先到达" << endl;
        } else if (result == 2) {
            cout << "第 2 个人先到达" << endl;
        } else if (result == 0) {
            cout << "两个人同时到达" << endl;
        }
    }

private:
    int whoWillReachFirst(int x, int y, int z) {
        // 在这里实现逻辑
        return 0; // 占位返回值
    }
};