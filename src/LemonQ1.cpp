//
// Created by Shawn Hu on 2025/4/22.
//
#include "../include/ILeetCodeQuestion.h"
#include <iostream>
using namespace std;

class LemonQ1 : public ILeetCodeQuestion {
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

    Node* reverse(Node* head) {
        Node* dummy = new Node(-1);
        auto cur = dummy;
        cur->next = head;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            Node* node1 = cur->next;
            Node* node2 = node1->next;
            node1->next = node2->next;
            node2->next = node1;
            cur -> next = node2;
            cur = node1;
        }
        return dummy->next;
    }

    void solution() {
        string line;
        // 从终端读入行，再按照空格切分
        getline(cin, line);
        istringstream iss(line);
        int num;
        Node* dummy = new Node(-1);
        Node* cur = dummy;
        while (iss >> num) {
            if(num == -1) {
                break;
            }
            Node * node = new Node(num);
            cur->next = node;
            cur = node;
        }
        dummy = reverse(dummy->next);
        while (dummy != nullptr) {
            cout << dummy->value << " ";
            dummy = dummy->next;
        }
    }
};