//
// Created by Shawn Hu on 2025/5/7.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class BoleQ4 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
//        freopen("input.txt", "r", stdin);
        vector<vector<string> > map = {{"a","b","c"},
                                       {"f","e","d"},
                                       {"g","n","m"}};
        vector<string> strArr = {"fed","fam","bca"};
        solution(map, strArr);
    }

private:
    bool DFS(vector<vector<string>>& map, vector<vector<bool>> visited, string str, int x, int y, int index) {
        if (visited[x][y] || map[x][y][0] != str[index]) {
            return false;
        }
        if (index == str.size() - 1) {
            return true;
        }
        visited[x][y] = true;
        vector<int> deltaX = {0, 1, 0, -1};
        vector<int> deltaY = {1, 0, -1, 0};
        for (int k = 0; k < 4; ++k) {
            int newX = x + deltaX[k];
            int newY = y + deltaY[k];
            if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map[0].size()) {
                if (DFS(map, visited, str, newX, newY, index + 1)){
                    return true;
                }
            }
        }
        visited[x][y] = false;
        return false;
    }

    vector<bool> solution(vector<vector<string> >& map, vector<string>& strArr) {
        int len = strArr.size();
        int n = map.size();
        int m = map[0].size();
        vector<bool> ans(len);
        for (int k=0; k<len; k++) {
            vector<vector<bool>> visited (n, vector<bool>(m, false));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j){
                    if(DFS(map, visited, strArr[k], i, j, 0)) {
                        ans[k] = true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};