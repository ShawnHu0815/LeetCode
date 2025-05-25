//
// Created by Shawn Hu on 2025/5/25.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class WangyiInteviewQ1: public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
//        freopen("input.txt", "r", stdin);
        vector<int> vec = {1,2,3};
        solution(vec);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    vector<vector<int>> ans;
    void backtrack(vector<int>& vec, vector<int>& path, stack<int> stk ,int i){
        if(vec.size()-1 == path.size() + stk.size()){
            vector<int> temp(path.begin(), path.end());
            temp.push_back(vec[i]);
            while(!stk.empty()){
                temp.push_back(stk.top());
                stk.pop();
            }
            ans.push_back(temp);
            return;
        }
        // 1.当前元素放入 path 中，即弹出
        path.push_back(vec[i]);
        backtrack(vec,path,stk,i + 1);
        path.erase(path.end()-1);

        // 2. 当前元素放入 stack 中，即不弹出
        stk.push(vec[i]);
        backtrack(vec,path,stk,i + 1);
        stk.pop();
    }

    void solution(vector<int>& vec) {
        vector<int> path;
        stack<int> stk;
        backtrack(vec,path,stk,0);
    }
};