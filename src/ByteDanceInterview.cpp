//
// Created by Shawn Hu on 2025/5/24.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class ByteInterview : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
//        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    void quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left >= right) return; // 终止条件

        int pivotIndex = left;
        int pivot = nums[pivotIndex];
        int i = left;

        for (int j = left + 1; j <= right; ++j) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[pivotIndex], nums[i]);

        int targetPos = nums.size() - k; // 第k大元素的正确位置
        if (i == targetPos) {
            return; // 找到目标位置
        } else if (i < targetPos) {
            quickSelect(nums, i + 1, right, k); // 处理右半部分
        } else {
            quickSelect(nums, left, i - 1, k); // 处理左半部分
        }
    }

    void solution() {
        vector<int> nums = {10, 7, 2, 4, 8, 3, 9, 1, 5, 6};
        int n = nums.size();
        int k = 4; // 前5大的元素
        quickSelect(nums, 0, n - 1, k);

        // 输出后k个元素（前k大）
        for (int i = n - k; i < n; ++i) {
            cout << nums[i] << " ";
        }
    }
};