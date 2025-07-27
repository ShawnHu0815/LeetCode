//
// Created by Shawn Hu on 2025/7/27.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class W460Q1 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        vector<int> nums{2,1,3,2,1,3};
        cout << solution(nums);

    }

private:
    long long solution(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = n-1;
        long long ans = 0;
        while(left < right){
            ans += nums[right-1];
            right --;
            right --;
            left++;
        }
        return ans;
    }
};