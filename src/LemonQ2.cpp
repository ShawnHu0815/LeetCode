//
// Created by Shawn Hu on 2025/4/22.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
#include <sstream>

using namespace std;

class Template : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
        solution();
    }

private:
    struct Node {
        int value;
        Node* next;
        Node(int v): value(v), next(nullptr) {}
    };

    Node* sortList(Node* pHead){
       vector<int> nums;
        while (pHead!=nullptr) {
            nums.push_back(pHead->value);
            pHead = pHead->next;
        }
        sort(&nums);
        Node* dummy = new Node(-1);
        Node* cur = dummy;
        for (int i = 0; i < nums.size(); ++i) {
            Node* node = new Node(nums[i]);
            cur->next = node;
            cur = node;
        }
        return dummy->next;
    }

    void sort(vector<int>* nums){
        for(int i=0;i<nums->size();i++){
            for(int j=i+1;j<nums->size();j++){
                if ((*nums)[i] > (*nums)[j]){
                    int temp = (*nums)[i];
                    (*nums)[i] = (*nums)[j];
                    (*nums)[j] = temp;
                }
            }
        }
    }

    void solution() {
        string line;
        getline(cin, line);
        istringstream iss(line);
        int num;
        Node* dummy = new Node(-1);
        Node* cur = dummy;
        while (iss >> num) {
            Node * node = new Node(num);
            cur->next = node;
            cur = node;
        }
        dummy->next = sortList(dummy->next);
        dummy = dummy->next;
        while (dummy != nullptr) {
            cout << dummy->value << " ";
            dummy = dummy->next;
        }

    }
};