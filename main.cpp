#include "include/ILeetCodeQuestion.h"
#include "src/Template.cpp"
#include "src/LinkedListTemplate.cpp"
#include "src/W445Q1.cpp"
#include "src/W445Q2.cpp"
#include "src/GraphTemplate.cpp"
#include "src/HuffmanTemplate.cpp"
#include "src/WYQ1.cpp"
#include "src/WYQ2.cpp"
#include "src/WYQ3.cpp"
#include <memory>
using namespace std;

int main() {
    std::unique_ptr<ILeetCodeQuestion> question;
    
    // 通过注释来切换不同的题目
    // 未来添加新题目时，取消注释对应的行即可
//    question = std::make_unique<Q1Template>();
//    question = std::make_unique<LinkedListTemplate>();
//    question = std::make_unique<W445Q2>();
//    question = make_unique<GraphTemplate>();
//    question = make_unique<HuffmanTemplate>();
//    question = make_unique<Q1>();
//    question = make_unique<Q4>();
//    question = make_unique<Q5>();
//    question = std::make_unique<WYQ1>();
//    question = std::make_unique<WYQ2>();
    question = std::make_unique<WYQ3>();

    if (question) {
        question->run();
    }
    
    return 0;
}
