//
// Created by Shawn Hu on 2025/8/10.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <map>

using namespace std;

class W462Q3 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
//        freopen("input.txt", "r", stdin);
        vector<int> value = {32873,46747,35007,42385,16468,43825,6946,8178,86095};
        vector<int> limit = {8,2,2,3,2,1,3,2,1};
        maxTotal(value, limit);
        cout << "最大总价值：" << maxTotal(value, limit) << endl;
    }

private:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        long long ans = 0;
        map<int, priority_queue<int>> ValueMap;
        map<int, int> NumMap;
        int n = value.size();
        for(int i=0;i<n;i++){
            ValueMap[limit[i]].push(value[i]);
            NumMap[limit[i]]++;
        }

        int activeNum = 0;
        for(auto& pair : ValueMap){
            while(activeNum < pair.first && !pair.second.empty()){
                activeNum ++;
                int preActiveNum = activeNum-1;
                if(preActiveNum != pair.first && NumMap.find(preActiveNum) != NumMap.end()) {
                    activeNum -= NumMap[preActiveNum] - ValueMap[preActiveNum].size();
                    NumMap.erase(preActiveNum);
                }
                ans += pair.second.top();
                pair.second.pop();
            }
        }
        return ans;
    }
};