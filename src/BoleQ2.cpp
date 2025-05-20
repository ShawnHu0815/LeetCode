//
// Created by Shawn Hu on 2025/5/7.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class BoleQ2 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
//        freopen("input.txt", "r", stdin);
        vector<int> numlist = {5,6,1,4};
        vector<int> gaplist = {1};
        solution(numlist, gaplist);
    }

private:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

    int solution(vector<int>& numlist, vector<int>& gaplist) {
        int ans = 0;
        int round = 0;
        while (!isSorted(numlist)) {
            if(gaplist[round] == 1){

            }
            else{
                for(int i=0;i + gaplist[round] < numlist.size();i++){
                    if(numlist[i] > numlist[i + gaplist[round]]){
                        swap(numlist[i], numlist[i + gaplist[round]]);
                        ans++;
                    }
                }
                round++;
            }
        }
        cout << ans;
        return ans;
    }
};