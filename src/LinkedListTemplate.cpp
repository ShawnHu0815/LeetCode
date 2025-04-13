//
// Created by Shawn Hu on 2025/4/13.
//

#include "../include/ILeetCodeQuestion.h"
#include <limits>
#include <iostream>
#include <sstream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode* prev;

    explicit ListNode(int val): val(val), next(nullptr), prev(nullptr){}
};

class LinkedList{
private:
    ListNode* dummyHead;
    ListNode* dummyTail;

public:
    LinkedList() {
        dummyHead = new ListNode(std::numeric_limits<int>::min());
        dummyTail = new ListNode(std::numeric_limits<int>::min());
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    ~LinkedList() {  // 析构函数释放所有节点
        ListNode* cur = dummyHead->next;
        while (cur != dummyTail) {
            ListNode* temp = cur;
            cur = cur->next;
            delete temp;  // 释放每个节点
        }
        delete dummyHead;  // 释放哨兵节点
        delete dummyTail;
    }

    void insert(int x, int y){
        auto cur = dummyHead->next;
        while (cur != dummyTail && cur->val != x){
            cur = cur->next;
        }

        auto newNode = new ListNode(y);
        newNode->prev = cur->prev;
        newNode->next = cur;

        cur->prev->next = newNode;
        cur->prev = newNode;
    }

    void deleteNode(int x){
        auto cur = dummyHead->next;
        while (cur != dummyTail && cur->val != x){
            cur = cur->next;
        }
        if (cur != dummyTail){
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            delete cur;  // 释放目标节点
        }
    }

    void print(){
        auto cur = dummyHead->next;
        if(cur == dummyTail){
            cout << "NULL" << endl;
            return;
        }
        while (cur != dummyTail){
            cout << cur->val << " ";
            cur = cur->next;
        }
    }
};


class LinkedListTemplate: public ILeetCodeQuestion{
public:
    void run() override {
        int n;
        cin >> n;
        cin.ignore(); // 清除换行符

        LinkedList list; // 使用栈对象自动管理内存

        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin, line);
            istringstream iss(line);
            string command;
            iss >> command;

            if (command == "insert") {
                int x, y;
                if (iss >> x >> y) {
                    list.insert(x, y);
                }
            } else if (command == "delete") {
                int x;
                if (iss >> x) {
                    list.deleteNode(x);
                }
            }
        }
        list.print();
    }
};