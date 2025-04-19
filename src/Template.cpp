#include "../include/ILeetCodeQuestion.h"
#include <iostream>
using namespace std;

class Template : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        // 在这里实现具体的题目逻辑
        int result = solution();
    }

private:
    int solution() {
        // 这里是题目的具体实现

        for (int i = 0; i < 10; ++i) {
            std::cout << "Processing: " << i << std::endl;
        }
        // 这只是一个示例，返回一个固定值
        return 42;
    }
};