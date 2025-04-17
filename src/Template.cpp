#include "../include/ILeetCodeQuestion.h"
#include <iostream>

class Template : public ILeetCodeQuestion {
public:
    void run() override {
        std::cout << "Running Template..." << std::endl;
        // 在这里实现具体的题目逻辑
        int result = solution();
        std::cout << "Result: " << result << std::endl;
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