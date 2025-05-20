#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#define int long long

using namespace std;

class LilithQ3 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    // 计算最大公约数
    static int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void solution() {
        int n, x, y;
        cin >> n >> x >> y;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(gcd(i,x) == 1 && gcd(i,y) == 1){
               ans++;
            }
        }
        cout << ans << endl;
    }
};