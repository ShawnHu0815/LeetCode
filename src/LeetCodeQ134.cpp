//
// Created by Shawn Hu on 2025/5/26.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class LeetCodeQ134 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
//        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    void solution() {
        vector<int> gas = {3,1,1};
        vector<int> cost = {1,2,2};
        int ans = canCompleteCircuit(gas,cost);
        cout << ans;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int start = 0; start < n; start++){
            int curPos = start;
            int gasVol = gas[start];
            while(curPos +1 != start && (curPos + 1) % n != start){
                gasVol -= cost[curPos];
                if(gasVol < 0)break;
                curPos = (curPos + 1) % n;
                gasVol += gas[curPos];
            }
            if((curPos + 1 == start || (curPos + 1) % n == start)
               && cost[curPos] <= gasVol) return start;
        }
        return -1;
    }
};