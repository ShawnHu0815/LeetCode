#include "include/ILeetCodeQuestion.h"
#include "src/Q1Template.cpp"
#include "src/LinkedListTemplate.cpp"
#include <memory>

int main() {
    std::unique_ptr<ILeetCodeQuestion> question;
    
    // 通过注释来切换不同的题目
    // 未来添加新题目时，取消注释对应的行即可
//    question = std::make_unique<Q1Template>();
    question = std::make_unique<LinkedListTemplate>();
    
    if (question) {
        question->run();
    }
    
    return 0;
}
