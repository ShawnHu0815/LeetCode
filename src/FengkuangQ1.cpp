//
// Created by Shawn Hu on 2025/8/3.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <set>

using namespace std;

class FengkuangQ1 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        cout << kInArray(1,2) << endl;
    }

private:
    bool kInArray(int k, int target){
        set<int> nums;
        queue<int> q;
        q.push(k);
        while(q.back() < target){
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int cur = q.front();
                q.pop();
                nums.insert(2*cur+1);
                nums.insert(3*cur+1);
                q.push(2*cur+1);
                q.push(3*cur+1);
            }
        }
        return nums.find(target) != nums.end();
    }
};