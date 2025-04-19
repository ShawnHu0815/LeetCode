#include "../include/ILeetCodeQuestion.h"
#include <iostream>
using namespace std;

class Template : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        solution();
    }

private:
    void solution() {
        // 题目的具体实现

        return;
    }
};