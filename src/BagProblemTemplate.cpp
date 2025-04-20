//
// Created by Shawn Hu on 2025/4/20.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;

class BagProblemTemplate : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        solution();
    }

private:
    void solution() {
        int n, m;
        cin >> n >> m;

        vector<int> v(n + 1);  // 体积 volume
        vector<int> w(n + 1);  // 价值 worth

        for (int i = 1; i <= n; i++) {
            cin >> v[i] >> w[i];
        }

        // 标准01背包（不需要恰好装满）
        vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp1[i][j] = dp1[i - 1][j];
                if (j >= v[i]) {
                    dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - v[i]] + w[i]);
                }
            }
        }
        cout << dp1[n][m] << endl;

        // 恰好装满的01背包
        vector<vector<int>> dp2(n + 1, vector<int>(m + 1, -INF));
        dp2[0][0] = 0;  // 初始状态：容量0时价值0

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp2[i][j] = dp2[i - 1][j];  // 不选第i件物品
                if (j >= v[i] && dp2[i - 1][j - v[i]] != -INF) {
                    dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - v[i]] + w[i]);
                }
            }
        }

        // 输出结果，如果不能恰好装满则输出0
        cout << (dp2[n][m] < 0 ? 0 : dp2[n][m]) << endl;

    }
};