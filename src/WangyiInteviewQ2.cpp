//
// Created by Shawn Hu on 2025/5/20.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class WangyiInteviewQ2 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        freopen("input.txt", "r", stdin);
        solution();
    }

private:
    vector<int> help(vector<int>& preoder, vector<int>& inorder) {
        if (preoder.empty() || inorder.empty()) {
            return {};
        }
        // 先序遍历的第一个元素是根节点
        int root = preoder[0];
        int inorderRootIndex = -1;
        // 在中序遍历中找到根节点的位置
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==root){
                inorderRootIndex = i;
                break;
            }
        }
        // 分别构建左子树和右子树
        vector<int> leftPreorder, rightPreorder;
        vector<int> leftInorder, rightInorder;
        // 左子树的中序遍历是中序遍历中根节点左边的部分
        for (int i = 0; i < inorder.size() ; ++i) {
            if(i == inorderRootIndex) {
                continue;
            }
            else if (i < inorderRootIndex) {
                leftInorder.push_back(inorder[i]);
            } else {
                rightInorder.push_back(inorder[i]);
            }
        }
        // 左子树的先序遍历是先序遍历中根节点后面的部分
        for (int i = 1; i < preoder.size(); ++i) {
            if (i < leftInorder.size() + 1) {
                leftPreorder.push_back(preoder[i]);
            } else {
                rightPreorder.push_back(preoder[i]);
            }
        }
        // 递归构建左子树和右子树
        vector<int> result;
        auto leftResult = help(leftPreorder, leftInorder);
        auto rightResult = help(rightPreorder, rightInorder);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.insert(result.end(), rightResult.begin(), rightResult.end());
        result.push_back(root);
        return result;
    }

    void solution() {
        int n = 5;
        vector<int> preorder(n);
        for (int i = 0; i < n; ++i) {
            cin >> preorder[i];
        }
        vector<int> inorder(n);
        for (int i = 0; i < n; ++i) {
            cin >> inorder[i];
        }
        vector<int> result = help(preorder, inorder);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
    }
};