//
// Created by Shawn Hu on 2025/4/26.
//

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <queue>
#include <string>
#include <vector>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // 构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // 打印树（层序遍历）
    static void printTree(TreeNode* root) {
        if (!root) {
            std::cout << "[]" << std::endl;
            return;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<std::string> result;

        while (!q.empty()) {
            int size = q.size();
            bool hasNodes = false;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    result.push_back(std::to_string(node->val));
                    q.push(node->left);
                    q.push(node->right);

                    // 检查是否还有非空节点
                    if (node->left || node->right) {
                        hasNodes = true;
                    }
                } else {
                    result.push_back("null");
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }

            // 如果这一层及以下都没有实际节点了，就停止
            if (!hasNodes) {
                break;
            }
        }

        // 移除末尾的null
        while (!result.empty() && result.back() == "null") {
            result.pop_back();
        }

        // 打印结果
        std::cout << "[";
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i];
            if (i < result.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]" << std::endl;
    }

    // 根据数组构建二叉树
    static TreeNode* fromArray(const std::vector<std::string>& nodes) {
        if (nodes.empty() || nodes[0] == "null") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(std::stoi(nodes[0]));
        std::queue<TreeNode*> q;
        q.push(root);

        size_t i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* current = q.front();
            q.pop();

            // 设置左子节点
            if (i < nodes.size() && nodes[i] != "null") {
                current->left = new TreeNode(std::stoi(nodes[i]));
                q.push(current->left);
            }
            i++;

            // 设置右子节点
            if (i < nodes.size() && nodes[i] != "null") {
                current->right = new TreeNode(std::stoi(nodes[i]));
                q.push(current->right);
            }
            i++;
        }

        return root;
    }

    // 释放树的内存
    static void deleteTree(TreeNode* root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

#endif // TREENODE_H