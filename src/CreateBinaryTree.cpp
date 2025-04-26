//
// Created by Shawn Hu on 2025/4/26.
//
#include "../include/ILeetCodeQuestion.h"
#include "../include/TreeNode.h"
#include <iostream>

using namespace std;

class CreateBinaryTree
: public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行二叉树构建：" << std::endl;

        // 从 input.txt 读取输入
        freopen("input.txt", "r", stdin);

        string input;
        getline(cin, input);

        // 解析输入
        vector<int> inorder, postorder;
        parseInput(input, inorder, postorder);

        cout << "中序遍历: [";
        for (size_t i = 0; i < inorder.size(); ++i) {
            cout << inorder[i];
            if (i < inorder.size() - 1) cout << ",";
        }
        cout << "]" << endl;

        cout << "后序遍历: [";
        for (size_t i = 0; i < postorder.size(); ++i) {
            cout << postorder[i];
            if (i < postorder.size() - 1) cout << ",";
        }
        cout << "]" << endl;

        // 构建二叉树并打印结果
        TreeNode* root = buildTree(inorder, postorder);
        cout << "构建的二叉树: ";
        TreeNode::printTree(root);

        // 释放内存
        TreeNode::deleteTree(root);
    }

private:
    // 解析输入字符串成两个数组
    void parseInput(const string& input, vector<int>& inorder, vector<int>& postorder) {
        bool isInorder = true;
        string num;

        for (char c : input) {
            if (c == '[') {
                continue;
            } else if (c == ']') {
                if (!num.empty()) {
                    if (isInorder) {
                        inorder.push_back(stoi(num));
                    } else {
                        postorder.push_back(stoi(num));
                    }
                    num.clear();
                }
            } else if (c == ',') {
                if (!num.empty()) {
                    if (isInorder) {
                        inorder.push_back(stoi(num));
                    } else {
                        postorder.push_back(stoi(num));
                    }
                    num.clear();
                } else if (!inorder.empty() && postorder.empty()) {
                    // 如果逗号前面是 ']'，且已处理完中序遍历，则切换到后序遍历
                    isInorder = false;
                }
            } else if (isdigit(c)) {
                num += c;
            }
        }
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return help(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }

    TreeNode* help(vector<int>& inorder, vector<int>& postorder,int inLeft, int inRight, int postLeft,int postRight){
        if(postLeft > postRight)return nullptr;
        int rootVal = postorder[postRight];
        TreeNode* root = new TreeNode(rootVal);
        int index = -1;
        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i] == rootVal){
                index = i;
                break;
            }
        }
        int leftLen = index - inLeft;

        root->left = help(inorder, postorder, inLeft, inLeft + leftLen-1, postLeft, postLeft+leftLen-1);
        root->right = help(inorder, postorder, index +1, inRight, postLeft +leftLen, postRight-1);
        return root;
    }
};