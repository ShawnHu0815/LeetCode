//
// Created by Shawn Hu on 2025/4/22.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <string>

using namespace std;

class LemonQ3 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        solution();
    }

private:
    int findGreaterNum(int N) {
        string numStr = to_string(N);
        int n = numStr.size();
        int isIncresing = -1;
        int isDecreasing = -1;
        for (int i = 1; i < numStr.size(); ++i) {
            if (numStr[i-1] < numStr[i]){
                isIncresing = i;
            }
            if (numStr[i-1] > numStr[i]){
                isDecreasing = i;
            }
        }
        if(isIncresing == -1)return -1;
        else if(isDecreasing == -1){
            swap(numStr[n-1], numStr[n-2]);
        }else if(isDecreasing != n-1 ){
            reverse(numStr.begin() + isDecreasing, numStr.end());
        }
        return stoi(numStr);
    }

    void solution() {
        cout << findGreaterNum(1324) << endl;
    }
};