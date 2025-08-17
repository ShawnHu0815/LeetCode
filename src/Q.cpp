//
// Created by Shawn Hu on 2025/8/13.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
using namespace std;

class Q:public ILeetCodeQuestion  {
public:
    virtual int add(int a,int b){
        return a + b;
    }
    Q(){
    }
    void solution(){
        Q* C1 = new Q();
        int ans = C1->add(2,3);
        cout << ans << endl;
    };

private:
    int m,n;

};

class C2:public Q{
    int add(int c, int d){
        return c * d;
    }
    C2();
};