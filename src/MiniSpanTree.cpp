//
// Created by Shawn Hu on 2025/5/2.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class MiniSpanTree : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行最小生成树算法：" << std::endl;
        freopen("input.txt", "r", stdin);

        string input;
        getline(cin, input);

        // 解析输入
        int n, m;
        vector<vector<int>> cost;
        parseInput(input, n, m, cost);

        cout << "村庄数量: " << n << endl;
        cout << "道路数量: " << m << endl;
        cout << "道路信息:" << endl;

        int result = miniSpanningTree(n, m, cost);
        cout << "最小修路成本: " << result << endl;
    }

private:
    vector<int> parent;

    void parseInput(const string& input, int& n, int& m, vector<vector<int>>& cost) {
        // 分割字符串
        size_t pos1 = input.find(',');
        size_t pos2 = input.find(',', pos1 + 1);

        // 获取n和m
        n = stoi(input.substr(0, pos1));
        m = stoi(input.substr(pos1 + 1, pos2 - pos1 - 1));

        // 解析cost数组
        string costStr = input.substr(pos2 + 1);
        size_t start = costStr.find('[') + 1;
        size_t end = costStr.rfind(']');
        string content = costStr.substr(start, end - start);

        // 解析每条路径信息
        size_t pos = 0;
        while (pos < content.length()) {
            size_t bracketStart = content.find('[', pos);
            if (bracketStart == string::npos) break;

            size_t bracketEnd = content.find(']', bracketStart);
            string roadStr = content.substr(bracketStart + 1, bracketEnd - bracketStart - 1);

            // 解析一个道路信息 [a,b,c]
            vector<int> road;
            size_t commaPos1 = roadStr.find(',');
            size_t commaPos2 = roadStr.find(',', commaPos1 + 1);

            road.push_back(stoi(roadStr.substr(0, commaPos1)));
            road.push_back(stoi(roadStr.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1)));
            road.push_back(stoi(roadStr.substr(commaPos2 + 1)));

            cost.push_back(road);
            pos = bracketEnd + 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionNode(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            parent[rooty] = rootx;
        }
    }

    int miniSpanningTree(int n, int m, vector<vector<int>>& cost) {
        // 初始化并查集
        parent.resize(n + 1);  // 注意：村庄编号可能从1开始
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // 使用优先队列实现 Kruskal 算法
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2]; // 按成本升序排序
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        // 将所有道路加入优先队列
        for (int i = 0; i < m; i++) {
            pq.push(cost[i]);
        }

        long long ans = 0;
        int build = 0;

        // 贪心构建最小生成树
        while (build < n - 1) {
            auto road = pq.top();
            pq.pop();

            if (find(road[0]) != find(road[1])) {
                ans += road[2];
                unionNode(road[0], road[1]);
                build++;
            }
        }

        return ans;
    }
};