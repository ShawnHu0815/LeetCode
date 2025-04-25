//
// Created by Shawn Hu on 2025/4/25.
//

#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <vector>
#define int long long

using namespace std;

class TwoDimensionDifference: public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    void solution() {
        int n,m,q;
        cin >> n >> m >> q;
        vector<vector<int>> vec(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> vec[i][j];
            }
        }
        vector<vector<int>> diff(n+2,vector<int>(m+2,0));
        while(q--){
            int x1,y1,x2,y2,k;
            cin >> x1 >> y1 >> x2 >> y2 >> k;
            diff[x1][y1] += k;
            diff[x2+1][y2+1] += k;
            diff[x1][y2+1] -= k;
            diff[x2+1][y1] -= k;
        }
        for(int i=1;i<=n;i++){
            int curRow = 0;
            for(int j=1;j<=m;j++){
                curRow += diff[i][j];
                diff[i][j] = diff[i-1][j] + curRow;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << vec[i-1][j-1] + diff[i][j] << " ";
            }
            cout << endl;
        }
    }
};