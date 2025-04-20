//
// Created by Shawn Hu on 2025/4/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

class SilverHeartQ3 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        solution();
    }

private:
    void solution() {
        string S;
        string T;
        cin >> S >> T;
        int n = S.size();
        vector<int> countA(26);
        vector<int> countB(26);
        for(char c : S) {
            countA[c - 'a']++;
        }
        for(char c : T) {
            countB[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (countA[i] != countB[i]) {
                cout << -1 << endl;
                return;
            }
        }
        map<char, priority_queue<int, vector<int>, greater<>>> mapA;
        for (int i = 0; i < n; ++i) {
            mapA[S[i]].push(i);
        }
        int lastIndex = -1;
        int cur = 0;
        int maxVal = INT_MIN;
        for (int i = 0; i < n; ++i) {
            char c = T[i];
            int curIndex = mapA[c].top();mapA[c].pop();
            if(curIndex > lastIndex){
                cur++;
            }else{
                maxVal = max(maxVal, cur);
                break;
            }
            lastIndex = curIndex;
        }

        cout << n - maxVal << endl;
    }
};