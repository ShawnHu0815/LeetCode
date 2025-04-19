//
// Created by Shawn Hu on 2025/4/19.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
using namespace std;

class WYQ3 : public ILeetCodeQuestion {
public:
    void run() override {
        std::cout << "Running Template..." << std::endl;
        // 在这里实现具体的题目逻辑
        int result = solution();
        std::cout << "Result: " << result << std::endl;
    }

private:
    struct Point{
        int x,y;
        Point(int x=0,int y=0):x(x),y(y){}
    };

    struct Runner{
        Point pos;
        int E_i,K_i; // 记录逃脱所需能量值和携带初始能量值
        int escape_time; // 逃脱时间
        vector<int> path_lengths; // 记录到每个出口的路径长度
    };

    vector<vector<int>> BFS(vector<string>& maze, int n, int m, Point start){
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<Point> q;
        dist[start.y][start.x] = 0;
        q.push(start);
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            Point curr = q.front();q.pop();
            for(int i=0;i<4;i++){
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];
                // 判断是否越界，并且是否是墙壁，并且是否未访问过
                if(nx >= 0 && nx < m && ny >= 0 && ny<n && maze[ny][nx] != '#' && dist[ny][nx] == INT_MAX){
                    dist[ny][nx] = dist[curr.y][curr.x] +1;
                    q.push(Point(nx,ny));
                }
            }
        }
        return dist;
    }

    int solution() {
        int P;
        cin >> P;
        while(P--){
            int N,M,X,Y,E;
            cin >> N >> M >> X >> Y >> E;
            vector<Runner> runners(X);
            for(int i=0;i<X;i++){
                cin >> runners[i].pos.y >> runners[i].pos.x;
                cin >> runners[i].E_i >> runners[i].K_i;
                runners[i].pos.x--;
                runners[i].pos.y--;
            }
            vector<Point> exits(Y);
            for(int i=0;i<Y;i++){
                cin >> exits[i].x >> exits[i].y;
                exits[i].x--;
                exits[i].y--;
            }
            vector<string> maze(N);
            for(int i=0;i<N;i++){
                cin >> maze[i];
            }
            for(auto& runner : runners){
                // 计算每个逃生者到达每个出口的最短路径
                vector<vector<int>> dist = BFS(maze,N,M,runner.pos);
                runner.path_lengths.resize(Y);
                for(int i=0;i<Y;i++){
                    // 记录到达每个出口的路径长度
                    runner.path_lengths[i] = dist[exits[i].y][exits[i].x];
                }
            }
            // 按照逃生者的能量值进行排序
            sort(runners.begin(),runners.end(),[](Runner& a, Runner& b){
                return a.E_i < b.E_i;
            });
            int total_time = 0;
            int cur_energy = E;
            bool possible = true;
            for (auto& runner: runners) {
                int min_path = INT_MAX;
                // 遍历每个逃生者的路径长度，寻找距离出口最短路径
                for(int len: runner.path_lengths){
                    if(len != INT_MAX && len <= runner.K_i){
                        min_path = min(min_path, len);
                    }
                }
                // 如果没有可行的路径，无法逃出
                if(min_path == INT_MAX ){
                    possible = false;
                    break;
                }
                // 如果当前能量不足以到达出口，等待时间为逃生者的能量值减去当前能量值
                int wait_time = max(0,runner.E_i - cur_energy);
                total_time += wait_time + min_path;
                cur_energy += runner.K_i - min_path;
            }
            cout << (possible? total_time: -1) << endl;
        }
        return 0;
    }
};