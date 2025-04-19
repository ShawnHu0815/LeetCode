//
// Created by Shawn Hu on 2025/4/17.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class HuffmanTemplate : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "哈夫曼编码问题" << endl;
        cout << "描述：给出一个有n种字符组成的字符串，其中第i种字符出现的次数为ai。" << endl;
        cout << "请你对该字符串应用哈夫曼编码，使得该字符串的长度尽可能短，求编码后的字符串的最短长度。" << endl;

        // 示例输入
        int n = 3;
        vector<long long> freq = {1, 2, 3};

        cout << "\n示例：" << endl;
        cout << "输入：" << endl;
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << freq[i] << " ";
        }
        cout << endl;

        long long result = calculateMinLength(n, freq);

        cout << "输出：" << endl;
        cout << result << endl;

        cout << "\n说明：三种字符的哈夫曼编码分别为[\"00\",\"01\",\"1\"]时，长度最短，最短长度为9。" << endl;
    }

private:
    long long sum = 0;
    struct tree{
        long long val;
        tree* left;
        tree* right;
    };

    void getSum(tree* root, int depth){
        // 只有叶节点才计算加入值
        if(root->left== NULL && root->right == NULL){
            sum += depth * root->val;
            return;
        }
        if(root->left){
            getSum(root->left,depth+1);
        }
        if (root->right){
            getSum(root->right, depth+1);
        }
    }

    struct cmp{
        bool operator()(const tree* a, const tree* b)const{
            return a->val > b->val;
        }
    };

    long long calculateMinLength(int n, vector<long long>& freq) {
        priority_queue<tree*, vector<tree*>,cmp> pq;

        for (int i = 0; i < n; ++i) {
            tree* t = new tree;
            t->val = freq[i];
            pq.emplace(t);
        }

        while(pq.size()>1){
            tree* combinedTree = new tree;
            tree* a = pq.top();
            pq.pop();
            tree* b = pq.top();
            pq.pop();
            combinedTree->val = a->val+b->val;
            combinedTree->left = a;
            combinedTree->right = b;
            pq.push(combinedTree);
        }
        getSum(pq.top(),0);
        cout << sum << endl;
        return 0;
    }
};