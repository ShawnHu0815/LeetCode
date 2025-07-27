//
// Created by Shawn Hu on 2025/7/27.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class W460Q3 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        vector<int> nums{2,3,4,7,9};
        cout << minJumps(nums);
    }

private:
    int minJumps(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        while(i<nums.size()){
            if(isPrime(nums[i])){
                bool flag = false;
                for(int j = nums.size()-1;j>i;j--){
                    if(nums[j] % nums[i] == 0){
                        i = j;
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    i++;ans++;
                }
            }
            else{
                i++;ans++;
            }
        }
        return ans;
    }
    bool isPrime(int n) {
        if (n <= 1) return false; // 小于等于1的数不是质数
        if (n <= 3) return true;  // 2和3是质数
        if (n % 2 == 0 || n % 3 == 0) return false; // 排除2和3的倍数

        // 只需要检查到sqrt(n)
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
};