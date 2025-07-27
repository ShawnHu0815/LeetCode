//
// Created by Shawn Hu on 2025/7/27.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;


class DiandianQ2 : public ILeetCodeQuestion {
public:
    struct Point {
        int x;
        int y;
        Point(int xx, int yy) : x(xx), y(yy) {}
    };

    void run() override {
        cout << "开始运行模板：" << std::endl;
//        freopen("input.txt", "r", stdin);
        vector<Point> pos{
                Point(4, 3),
                Point(5, 5),
                Point(2, 9),
        };

        cout << minEnergy(10, pos);
    }

private:
    long long minEnergy(int n, vector<Point>& pos) {
        num = pos.size();
        visited.resize(num);
        minAns = LLONG_MAX;
        int getNum = 0;
        Point cur(0, 0); // 起点坐标
        backtrack(getNum, pos, 0, cur);
        return minAns;
    }

    vector<bool> visited;
    int num;
    long long minAns;

    void backtrack(int getNum, vector<Point>& pos, long long costEnergy,Point cur){
        if(getNum == num) {
            minAns = min(minAns, costEnergy);
            return;
        }
        for(int i = 0; i < num; ++i) {
            if(visited[i]) continue;
            visited[i] = true;
            long long newCost = costEnergy + abs(pos[i].x - cur.x) + abs(pos[i].y - cur.y);
            backtrack(getNum + 1, pos, newCost, pos[i]);
            visited[i] = false;
        }
    }
};