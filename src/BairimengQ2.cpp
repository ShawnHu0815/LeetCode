//
// Created by Shawn Hu on 2025/8/3.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class BairimengQ2 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        // [[3,3,1],[3,2,1]],[[4,3]],2
        vector<vector<int>> dolls = {{3,3,1},{3,2,1}};
        vector<vector<int>> circles = {{4,3}};
        cout << CircleDoll(dolls,circles,2) << endl; // 示例调用
        // [[1,3,2],[4,3,1],[7,1,2]],[[1,0],[3,3]],4
        dolls = {{1,3,2},{4,3,1},{7,1,2}};
        circles = {{1,0},{3,3}};
        cout << CircleDoll(dolls,circles,4) << endl; // 示例
    }

private:
    int CircleDoll(vector<vector<int> >& dolls, vector<vector<int> >& circles, int r) {
        int circleNum = circles.size();
        int dollsNum = dolls.size();
        int ans = 0;
        vector<bool> got(dollsNum, false);
        for(int i=0;i<dollsNum;i++){
            if(got[i]) continue;
            vector<int> doll = dolls[i];
            for(int j=0;j<circleNum;j++){
                vector<int> circle = circles[j];
                if(distance(doll, circle)+ doll[2] <= r){
                    ans++;
                    got[i] = true;
                    break; // 找到一个圆圈就跳出循环
                }
            }
        }
        return ans;
    }

    float distance(const vector<int>& a, const vector<int>& b) {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }
};