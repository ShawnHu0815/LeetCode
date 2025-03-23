using System;
using System.Collections.Generic;
using LeetCode.Properties;

namespace LeetCode;

public class W442Q2 : ILeetCodeQuestion
{
    /*
     * 给你一个二维整数数组 properties，其维度为 n x m，以及一个整数 k。
     *
     * 定义一个函数 intersect(a, b)，它返回数组 a 和 b 中 共有的不同整数的数量 。
     *
     * 构造一个 无向图，其中每个索引 i 对应 properties[i]。如果且仅当 
     * intersect(properties[i], properties[j]) >= k（其中 i 和 j 的范围为 [0, n - 1] 且 i != j），
     * 节点 i 和节点 j 之间有一条边。
     *
     * 返回结果图中 连通分量 的数量。
     */
    
    private int[] parent;
    private int[] rank;
    
    public void Run()
    {
        // 测试用例1
        int[][] properties1 = new int[][]
        {
            new int[] {1, 2},
            new int[] {1, 1},
            new int[] {3, 4},
            new int[] {4, 5},
            new int[] {5, 6},
            new int[] {7, 7}
        };
        int k1 = 1;
        Console.WriteLine($"测试用例1结果: {CountComponents(properties1, k1)}"); // 预期输出: 3
        
        // 测试用例2
        int[][] properties2 = new int[][]
        {
            new int[] {1, 2, 3},
            new int[] {2, 3, 4},
            new int[] {4, 3, 5}
        };
        int k2 = 2;
        Console.WriteLine($"测试用例2结果: {CountComponents(properties2, k2)}"); // 预期输出: 1
        
        // 测试用例3
        int[][] properties3 = new int[][]
        {
            new int[] {1, 1},
            new int[] {1, 1}
        };
        int k3 = 2;
        Console.WriteLine($"测试用例3结果: {CountComponents(properties3, k3)}"); // 预期输出: 2
    }
    
    public int CountComponents(int[][] properties, int k)
    {   
        // 1. 计算每对数组之间的交集大小
        // 2. 构建无向图
        // 3. 计算连通分量的数量

        int n = properties.Length;
        int m = properties[0].Length;
        
        UnionFind(n);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (Intersect(properties[i], properties[j]) >= k)
                {
                    Union(i,j);
                }
            }
        }
        
        return GetConnectedComponentCount(); // 返回占位符，等待实现
    }
    
    private int Intersect(int[] a, int[] b)
    {
        var setA = new HashSet<int>(a);
        var setB = new HashSet<int>(b);
        int ans = 0;
        foreach (var num in setB)
        {
            if (setA.Contains(num)) ans++;
        }
        return ans;
    }
    
    public void UnionFind(int size)
    {
        parent = new int[size];
        rank = new int[size];

        // 初始化每个元素的父节点为自己，秩为1
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    // 查找元素的根节点
    public int Find(int x)
    {
        if (parent[x] != x)
        {
            // 路径压缩
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    // 合并两个集合
    public void Union(int x, int y)
    {
        int rootX = Find(x);
        int rootY = Find(y);

        if (rootX != rootY)
        {
            // 按秩合并
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    // 判断两个元素是否在同一个集合中
    public bool IsConnected(int x, int y)
    {
        return Find(x) == Find(y);
    }
    
    // 查询连通分量的数量
    public int GetConnectedComponentCount()
    {
        HashSet<int> uniqueRoots = new HashSet<int>();
        for (int i = 0; i < parent.Length; i++)
        {
            int root = Find(i); // 找到每个元素的根节点
            uniqueRoots.Add(root); // 将根节点添加到 HashSet 中
        }
        return uniqueRoots.Count; // 返回唯一根节点的数量
    }
    
}
