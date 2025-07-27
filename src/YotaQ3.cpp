//
// Created by Shawn Hu on 2025/7/26.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class YotaQ3 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    vector<int> fight;
    vector<int> cost;
    vector<float> rate;

    void solution() {
        int n;
        cin >> n;
        fight.resize(n);
        int maxFight = -1;
        int maxFightIndex = -1;
        for(int i=0; i < n; i++) {
            cin >> fight[i];
            if(fight[i] > maxFight) {
                maxFight = fight[i];
                maxFightIndex = i;
            }
        }
        cost.resize(n);
        for(int i=0; i < n; i++) {
            cin >> cost[i];
        }
        rate.resize(n);
        for(int i=0; i < n; i++) {
            rate[i] = (float)fight[i] / cost[i];
        }

        cout << beforeMaxFight(maxFightIndex, maxFight);
    }

    int beforeMaxFight(int maxFightIndex, int maxFight) {
        if(maxFightIndex < 0) {
            return 0;
        }
        vector<int> isBuy(maxFightIndex, 0);
        int curFight = 0;
        int curCost = 0;

        for(int i=0;i<maxFightIndex;i++){
            if(rate[i] >= rate[maxFightIndex] && isBuy[i] == 0) {
                curFight += fight[i];
                curCost += cost[i];
                isBuy[i] = 1;
            }
        }

        int nextMaxFight = -1;
        int nextMaxIndex = -1;
        for(int i=0;i<=maxFightIndex-1;i++){
            if(fight[i] > nextMaxFight) {
                nextMaxFight = fight[i];
                nextMaxIndex = i;
            }
        }

        if(curFight < maxFight){
            return beforeMaxFight(nextMaxIndex, nextMaxFight) + cost[maxFightIndex];
        }else{
            if(curCost <= cost[maxFightIndex]) {
                return curCost;
            } else {
                return beforeMaxFight(nextMaxIndex, nextMaxFight) + cost[maxFightIndex];
            }
        }
    }


};