//
// Created by Shawn Hu on 2025/4/20.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class W446Q3 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行 W446Q3: 求出数组的 X 值 I" << endl;

        // 样例1
        vector<int> nums1 = {1, 2, 3, 4, 5};
        int k1 = 3;
        cout << "样例1: nums = [1,2,3,4,5], k = 3" << endl;
        vector<int> result1 = countXValues(nums1, k1);
        cout << "输出: [";
        for (int i = 0; i < result1.size(); ++i) {
            cout << result1[i];
            if (i < result1.size() - 1) cout << ",";
        }
        cout << "]" << endl << endl;

        // 样例2
        vector<int> nums2 = {1, 2, 4, 8, 16, 32};
        int k2 = 4;
        cout << "样例2: nums = [1,2,4,8,16,32], k = 4" << endl;
        vector<int> result2 = countXValues(nums2, k2);
        cout << "输出: [";
        for (int i = 0; i < result2.size(); ++i) {
            cout << result2[i];
            if (i < result2.size() - 1) cout << ",";
        }
        cout << "]" << endl << endl;

        // 样例3
        vector<int> nums3 = {1, 1, 2, 1, 1};
        int k3 = 2;
        cout << "样例3: nums = [1,1,2,1,1], k = 2" << endl;
        vector<int> result3 = countXValues(nums3, k3);
        cout << "输出: [";
        for (int i = 0; i < result3.size(); ++i) {
            cout << result3[i];
            if (i < result3.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }

private:
    vector<int> countXValues(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> ans(k);
        for(int i=0;i<n;i++){
            for(int len = 1;i+len<=n;len++){
                vector<int> newVec(nums.begin()+i,nums.begin()+i+len);
                ll mul = 1;
                for(int ele : newVec){
                    mul *= ele;
                    mul %= k;
                }
                ans[mul]++;
            }
        }
        return ans;
    }
};