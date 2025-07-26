//
// Created by Shawn Hu on 2025/5/27.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class LeetCodeQ6 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
//        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    void solution() {
        string s = "AB";
        int numRows = 1;
        cout << convert(s,3);
    }

    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        int n = s.size();
        string ans = "";
        vector<vector<char>> matrix(1005,vector<char>(1005,'!'));
        int i = 0, j = 0, cnt = 0;
        bool vFlag = true;
        bool zFlag = false;
        while(cnt < n){
            matrix[i][j] = s[cnt];
            if(vFlag){
                if(i == numRows-1){
                    zFlag = true;
                    vFlag = false;
                    j++;
                    i--;
                }else{
                    i++;
                }
            }else if(zFlag){
                if(i == 0){
                    zFlag = false;
                    vFlag = true;
                    i++;
                }else{
                    j++;
                    i--;
                }
            }
            cnt++;
        }
        for(int i=0;i<1000;i++){
            for(int j=0;j<1000;j++){
                if(matrix[i][j] != '!'){
                    ans += matrix[i][j];
                }
            }
        }
        return ans;
    }
};