//
// Created by Shawn Hu on 2025/4/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
using namespace std;

class WYQ2 : public ILeetCodeQuestion {
public:
    void run() override {
        std::cout << "Running Template..." << std::endl;
        // 在这里实现具体的题目逻辑
        int result = solution();
        std::cout << "Result: " << result << std::endl;
    }

private:

    struct Point{
        double x,y;
        Point(double x =0, double y=0):x(x), y(y){}
    };

    // 计算向量叉积
    double crossProduct(Point& a,Point& b, Point& c){
        return (b.x - a.x) * (c.y - a.y) - (b.y-a.y) * (c.x-a.x);
    }

    // 判断点p是否在三角形abc内
    bool isPointInTriangle(Point& a,Point& b, Point& c, Point& p){
        double d1 = crossProduct(p, a, b);
        double d2 = crossProduct(p, b, c);
        double d3 = crossProduct(p, c, a);
        bool hasNeg = (d1 < 0) || (d2 < 0) || (d3<0);
        bool hasPos = (d1 > 0) || (d2 > 0) || (d3>0);
        // 如果有一个点在三角形的边上，返回false
        return !(hasNeg && hasPos);
    }

    int solution() {
        int N,M,S;
        cin >> N >> M >> S;
        Point a,b,c;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;
        vector<int> count(S*S+1,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                int covered = 0;
                for(int s1 =0;s1 < S;s1++){
                    for(int s2=0;s2<S ;s2++){
                        // 计算每个小方格的中心点
                        double x = i+(s1+0.5)/S;
                        double y = j+(s2+0.5)/S;
                        Point p(x,y);
                        // 判断点p是否在三角形abc内
                        if(isPointInTriangle(a, b, c, p)){
                            // 计算覆盖的点的数量
                            ++covered;
                        }
                    }
                }
                // 统计覆盖的点的数量
                count[covered]++;
            }
        }
        for(int i=0;i<S*S;i++){
            cout << count[i] << (i==S*S? "\n" : " ");
        }
        return 0;
    }
};