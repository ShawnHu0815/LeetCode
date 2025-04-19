//
// Created by Shawn Hu on 2025/4/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
using namespace std;

class WYQ1 : public ILeetCodeQuestion {
public:
    void run() override {
        std::cout << "Running Template..." << std::endl;
        // 在这里实现具体的题目逻辑
        int result = solution();
        std::cout << "Result: " << result << std::endl;
    }

private:
    int solution() {
        int P;
        cin >> P;
        while (P--) {
            int T, C, N, M;
            cin >> T >> C >> N >> M;
            vector<int> releases(N);
            for (int i = 0; i < N; i++) {
                cin >> releases[i];
            }
            vector<int> kills(M);
            for (int i = 0; i < M; i++) {
                cin >> kills[i];
            }
            int max_kills = 0;
            // 记录上次释放的时间
            int last_release = -1 -T - C;
            // 遍历每个释放的时间
            for (int i : releases) {
                // 如果当前释放的时间距离上次释放的时间大于等于冷却时间C
                if (i -T - last_release >= C) {
                    int start = i;
                    int end = i + T;
                    // 计算左闭右开区间内的杀戮数量
                    auto left = lower_bound(kills.begin(), kills.end(), start);
                    auto right = upper_bound(kills.begin(), kills.end(), end - 1);
                    int count = right - left;
                    // 记录最大的杀戮数量
                    max_kills = max(max_kills, count);
                    last_release = i;
                }

            }
            cout << max_kills << endl;
        }
        return 0;
    }
};