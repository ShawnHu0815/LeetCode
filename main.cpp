#include "include/ILeetCodeQuestion.h"
#include "src/Template.cpp"
#include "src/LinkedListTemplate.cpp"
#include "src/W445Q1.cpp"
#include "src/W445Q2.cpp"
#include "src/W451Q2.cpp"
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
#include "src/BoleQ2.cpp"
#include "src/BoleQ4.cpp"
#include "src/LilithQ1.cpp"
#include "src/LilithQ2.cpp"
#include "src/LilithQ3.cpp"
#include "src/WangyiInteviewQ1.cpp"
#include "src/WangyiInteviewQ2.cpp"
#include "src/LeetCodeQ134.cpp"
#include "src/LeetCodeQ6.cpp"
#include "src/ByteDanceInterview.cpp"
#include "src/YotaQ1.cpp"
#include "src/YotaQ2.cpp"
#include "src/YotaQ3.cpp"
#include "src/W460Q1.cpp"

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
//    question = std::make_unique<MiniSpanTree>();
//    question = std::make_unique<BoleQ2>();
//    question = std::make_unique<BoleQ2>();
//    question = std::make_unique<LilithQ2>();
//    question = std::make_unique<LilithQ3>();
//    question = std::make_unique<LilithQ1>();
//    question = std::make_unique<WangyiInteviewQ2>();
//    question = std::make_unique<WangyiInteviewQ1>();
//    question = std::make_unique<ByteInterview>();
//    question = std::make_unique<W451Q2>();
//    question = make_unique<LeetCodeQ134>();
//    question = make_unique<LeetCodeQ6>();
//    question = make_unique<YotaQ1>();
//    question = make_unique<YotaQ2>();
//    question = make_unique<YotaQ3>();
//    question = make_unique<W460Q1>();
#include "src/W460Q3.cpp"
//    question = make_unique<W460Q3>();
#include "src/DiandianQ2.cpp"
//    question = make_unique<DiandianQ2>();
#include "src/FengkuangQ1.cpp"
//    question = make_unique<FengkuangQ1>();
#include "src/FengkuangQ2.cpp";
//    question = make_unique<FengkuangQ2>();
#include "src/BairimengQ1.cpp";
//    question = make_unique<BairimengQ1>();
#include "src/BairimengQ2.cpp";
#include "src/W462Q3.cpp";
    question = make_unique<W462Q3>();

    question->run();
    return 0;
}
