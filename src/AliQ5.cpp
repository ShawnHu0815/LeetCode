//
// Created by Shawn Hu on 2025/4/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

class AliQ5 : public ILeetCodeQuestion {
public:
    void run() override {
        std::cout << "Running Template..." << std::endl;
        // 在这里实现具体的题目逻辑
        int result = solution();
        std::cout << "Result: " << result << std::endl;
    }

private:

    bool canTransform(string& a, string& b){
        int i = 0, j =0;
        int n = a.size(), m = b.size();
        char curLower = '0';
        int lowerCount = 0;
        while(i < n && j <m){
            if(islower(a[i])){
                if(a[i] != curLower){
                    curLower = a[i];
                    lowerCount = 1;
                }else{
                    lowerCount++;
                }
            }
            if(toupper(a[i]) == toupper(b[j])){
                i++; j++;
            }
            else if(islower(a[i])){
                i++;
            } else if(isupper(a[i]) && tolower(a[i]) == curLower){
                i++;
            }
            else {
                return false;
            }
        }
        while (i < n && islower(a[i])) {
            i++;
        }
        return (i == n && j == m);
    }

    int solution() {
        int q;
        cin >> q;
        for(int i=0;i<q;i++){
            string a;
            string b;
            cin >> a >> b;
            if(canTransform(a, b))cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        return 0;
    }
};