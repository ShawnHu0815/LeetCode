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
#include "src/SilverHeartQ1.cpp"
#include "src/SilverHeartQ2.cpp"
#include "src/SilverHeartQ3.cpp"
#include "src/SilverHeartQ4.cpp"
#include "src/W446Q3.cpp"
#include "src/BagProblemTemplate.cpp"
#include "src/LemonQ1.cpp"
#include "src/LemonQ3.cpp"
#include "src/LemonQ4.cpp"
#include "src/TwoDimentionDifference.cpp"
#include "src/CreateBinaryTree.cpp"
#include "src/MiniSpanTree.cpp"
#include <memory>
using namespace std;

signed main() {
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
//    question = std::make_unique<WYQ3>();
//    question = std::make_unique<SilverHeartQ1>();
//    question = std::make_unique<SilverHeartQ2>();
//    question = std::make_unique<SilverHeartQ3>();
//    question = std::make_unique<SilverHeartQ4>();
//    question = std::make_unique<BagProblemTemplate>();
//    question = std::make_unique<W446Q3>();
//    question = std::make_unique<LemonQ1>();
//    question = std::make_unique<LemonQ3>();
//    question = std::make_unique<LemonQ4>();
//    question = std::make_unique<TwoDimensionDifference>();
//    question = std::make_unique<CreateBinaryTree>();
    question = std::make_unique<MiniSpanTree>();
    if (question) {
        question->run();
    }
    
    return 0;
}
