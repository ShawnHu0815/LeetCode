//
// Created by Shawn Hu on 2025/4/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

class AliQ4 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "Running Template..." << endl;
        // 在这里实现具体的题目逻辑
        int result = solution();
        cout << "Result: " << result << endl;
    }

private:
    bool canForm(vector<ull>& arr, int l, int r){
        if(r - l + 1 <3){
            return false;
        }
        vector<ull> subArr(arr.begin()+l-1,arr.begin()+r);
        sort(subArr.begin(), subArr.end());
        for (int i=0; i<subArr.size()-2; i++) {
            if(subArr[i] + subArr[i+1] > subArr[i+2]){
                return true;
            }
        }
        return false;
    }

    int solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n, m;
        cin >> n >> m;
        vector<ull> F(n);
        for (int i=0; i<n; i++) {
            cin >> F[i];
        }
        string res;
        for(int i=0;i<m;i++){
            int l,r;
            cin >> l >> r;
            if(canForm(F, l, r)){
                res += 'Y';
            }
            else{
                res += 'N';
            }
        }
        cout << res << endl;
    }
};