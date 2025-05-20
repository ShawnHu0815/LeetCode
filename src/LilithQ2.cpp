//
// Created by Shawn Hu on 2025/5/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class LilithQ2 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    void solution() {
        int n;
        cin >> n;
        vector<vector<int>> persons(n+1);
        for ( int i = 0; i < n; ++i) {
            int favorite;
            cin >> favorite;
            persons[favorite].push_back(i+1);
        }
        vector<int> prizes(n);
        for ( int i = 0; i < n; ++i) {
            cin >> prizes[i];
        }
        vector<int> ans;
        int prizePtr = 0;
        int personPtr = 0;
        while(prizePtr < n){
            int prize = prizes[prizePtr];
            auto it = lower_bound(persons[prize].begin()+personPtr, persons[prize].end(), prize);
            if(it == persons[prize].end()){
                ans.push_back(persons[prize][0]);
                persons[prize].erase(persons[prize].begin());
                personPtr = 0;
            } else {
                ans.push_back(*it);
                personPtr = *it;
                persons[prize].erase(it);
            }
            prizePtr++;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
    }
};