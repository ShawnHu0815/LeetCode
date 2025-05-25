#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class W451Q2 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
//        freopen("input.txt", "r", stdin);
        string s = "opnmoqprs";
        string ans = resultingString(s);
        cout << ans << endl;
    }

private:
    static constexpr auto comp = [](const string& a, const string& b) {
        if(a.size() == 0)return false;
        if(b.size() == 0)return true;
        int n = a.size();
        int m = b.size();
        int len = min(n, m);
        for(int i=0;i<len;i++){
            if(a[i] != b[i]){
                return a[i] > b[i];
            }
        }
        return n > m;
    };

    void removeAdjacent(string s, priority_queue<string, vector<string>, decltype(comp)>& pq, vector<bool>& visited) {
        int i = 0;
        while(i < s.size()){
            char a = s[i];
            char b = s[i+1];
            if(!visited[i] && (a == b+1 || a == b-1 || a == 'a' && b == 'z' || a == 'z' && b == 'a')){
                s.erase(i, 2);
                pq.push(s);
                i = max(0, i-1);
            } else {
                i++;
            }
        }
        return;
    }

    string resultingString(string s) {
        priority_queue<string,vector<string>, decltype(comp)> pq(comp);
        pq.push(s);
        int n = s.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if(!visited[i]){
                visited[i] = true;
                removeAdjacent(s, pq, visited);
                visited[i] = false;
            }
        }
        return pq.top();
    }
};