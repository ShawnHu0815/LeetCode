//
// Created by Shawn Hu on 2025/7/26.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class YotaQ2 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    string s;
    void solution() {
        cin >> s;
        vector<string> temp;
        backtrack(temp,0);
    }

    bool isValid(const string& str) {
        if (str.empty() || str.size() > 3 || (str[0] == '0' && str.size() > 1)) return false;
        int num = stoi(str);
        return num >= 0 && num <= 255;
    }

    void backtrack(vector<string>& temp, int index){
        if(temp.size() == 4){
            if(index == s.size()){
                for(int i =0;i<4;i++){
                    if(i != 3)cout << temp[i] <<".";
                    else cout << temp[i] << endl;
                }
                return;
            }
            return;
        }
        for(int i=1;i<=3;i++){
            if(index + i > s.size())return;
            string newFraction = s.substr(index,i);
            if(isValid(newFraction)){
                temp.push_back(newFraction);
                backtrack(temp,index+i);
                temp.pop_back();
            }
        }
        return;
    }


};