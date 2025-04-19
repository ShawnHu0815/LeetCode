//
// Created by Shawn Hu on 2025/4/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

class AliQ1 : public ILeetCodeQuestion {
public:
    void run() override {
        std::cout << "Running Template..." << std::endl;
        // 在这里实现具体的题目逻辑
        int result = solution();
        std::cout << "Result: " << result << std::endl;
    }

private:
    int solution() {
        int n;
        cin >> n;
        vector<vector<char>> map(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> map[i][j];
            }
        }

        for (int i = 1; i < n-1; ++i) {
            for (int j = 1; j < n-1; ++j) {
                char depth = map[i][j];
                if(map[i-1][j] < depth && map[i+1][j] < depth && map[i][j-1] < depth && map[i][j+1] < depth) {
                    map[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << map[i][j];
            }
            cout << endl;
        }
    }
};