//
// Created by Shawn Hu on 2025/4/16.
//

#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int v;
    vector<vector<int>> adjlist;
public:
    vector<int> visited;
    Graph(int v) : v(v) {
        adjlist.resize(v + 1);
        visited.resize(v + 1, 0);
    }

    void addEdge(int u, int v) {
        adjlist[u].push_back(v);
    }

    void dfs(vector<int>& ans, int u) {
        if (visited[u]) return;
        ans.push_back(u);
        visited[u] = 1;
        for (auto v : adjlist[u]) {
            dfs(ans, v);
        }
    }

    void dfsNonRecursive(vector<int>& ans, int u) {
        if (visited[u]) return;
        stack<int> s;
        s.push(u);
        visited[u] = 1;
        ans.push_back(u);
        while (!s.empty()) {
            int current = s.top();
            s.pop();
            for (auto v : adjlist[current]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    ans.push_back(v);
                    s.push(current);
                    s.push(v);
                    break;
                }
            }
        }
    }
};

class GraphTemplate : public ILeetCodeQuestion {
public:
    void run() override {
        std::cout << "Running Template..." << std::endl;

        // 样例输入
        istringstream input("5 4\n1 2\n2 3\n3 4\n4 5\n");
        cin.rdbuf(input.rdbuf());

        int n, m;
        cin >> n >> m;
        cin.ignore();

        Graph graph(n);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph.addEdge(u, v);
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (!graph.visited[i]) {
                graph.dfsNonRecursive(ans, i);
            }
        }

        for (int i=1;i<n;i++) {
            if (!graph.visited[i]) {
                cout << "-1" << endl;
                return;
            }
        }

        for (auto v : ans) {
            cout << v << " ";
        }
        cout << endl;
    }
};
