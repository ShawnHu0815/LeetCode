# LeetCode 学习仓库 (C++)

这是我的个人 LeetCode 刷题学习仓库，使用 C++ 语言实现各种算法题解。

## 项目结构

```
├── include/
│   └── ILeetCodeQuestion.h    # 题目实现的接口定义
├── src/
│   ├── LinkedListTemplate.cpp  # 链表相关题目模板
│   └── Q1Template.cpp          # 基础题目模板
├── main.cpp                    # 程序入口
└── CMakeLists.txt             # CMake构建配置
```

## 代码组织

- 所有题解都实现了 `ILeetCodeQuestion` 接口
- 每个题解都是一个独立的类，包含完整的解题逻辑
- 通过修改 `main.cpp` 中的代码来切换不同的题目

## 添加新题目

1. 在 `src/` 目录下创建新的 .cpp 文件
2. 实现 `ILeetCodeQuestion` 接口
3. 在 `main.cpp` 中包含新文件并创建对应的实例