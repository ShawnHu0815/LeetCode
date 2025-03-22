using System;
using System.Collections.Generic;
using LeetCode.Properties;

namespace LeetCode
{
    public class MihoyoQ1 : ILeetCodeQuestion
    {
        // 定义邻接表、子节点列表、进入时间、离开时间和时间戳
        static List<int>[] adj;       // 邻接表，存储每个节点的相邻节点
        static List<int>[] children;  // 子节点列表，存储每个节点的子节点
        static int[] inTime;          // 记录每个节点的进入时间
        static int[] outTime;         // 记录每个节点的离开时间
        static int time;              // 全局时间戳，用于DFS中记录时间

        public void Run()
        {
            // 读取输入的第一行，获取节点数n和根节点x
            string[] firstLine = Console.ReadLine().Split();
            int n = int.Parse(firstLine[0]);
            int x = int.Parse(firstLine[1]);

            // 初始化邻接表
            adj = new List<int>[n + 1];
            for (int i = 1; i <= n; i++)
                adj[i] = new List<int>();

            // 读取n-1条边，构建邻接表
            for (int i = 0; i < n - 1; i++)
            {
                string[] line = Console.ReadLine().Split();
                int u = int.Parse(line[0]);
                int v = int.Parse(line[1]);
                adj[u].Add(v);
                adj[v].Add(u);
            }

            // —————————————— 初始化数据结构部分 ——————————————
            
            // 初始化子节点列表
            children = new List<int>[n + 1];
            for (int i = 1; i <= n; i++)
                children[i] = new List<int>();

            // 初始化父节点数组，并设置根节点的父节点为-1
            int[] parent = new int[n + 1];
            Array.Fill(parent, 0);  // 初始化为0
            parent[x] = -1;          // 根节点的父节点标记为-1

            // 使用BFS遍历树，构建子节点和父节点的关系
            Queue<int> q = new Queue<int>();
            q.Enqueue(x);

            while (q.Count > 0)
            {
                int u = q.Dequeue();
                foreach (int v in adj[u])
                {
                    // 如果v不是u的父节点且v的父节点未被访问过
                    if (v != parent[u] && parent[v] == 0)
                    {
                        parent[v] = u;         // 设置v的父节点为u
                        children[u].Add(v);    // 将v添加到u的子节点列表中
                        q.Enqueue(v);          // 将v加入队列，继续BFS
                    }
                }
            }

            // 初始化进入时间和离开时间数组
            inTime = new int[n + 1];
            outTime = new int[n + 1];
            time = 0;

            // 从根节点x开始DFS，记录每个节点的进入和离开时间
            DFS(x);

            // 计算满足条件的节点对数量
            int sum = 0;
            for (int u = 1; u <= n; u++)
            {
                // 获取u的所有因子
                var factors = GetFactors(u, n);
                foreach (var v in factors) // 遍历 u 的所有因子，看因子对应的节点 v 是不是 u 的子孙
                {
                    // 如果v不在有效范围内，跳过
                    if (v < 1 || v > n)
                        continue;

                    // 如果v的进入时间在u的进入和离开时间之间，说明v是u的子孙节点
                    if (inTime[v] >= inTime[u] && inTime[v] <= outTime[u])
                    {
                        sum++;  // 满足条件，计数加1
                    }
                }
            }

            // 输出结果
            Console.WriteLine(sum);
        }

        // DFS函数，用于记录每个节点的进入和离开时间
        static void DFS(int u)
        {
            inTime[u] = ++time;  // 记录进入时间
            foreach (var v in children[u])
            {
                DFS(v);  // 递归遍历子节点
            }
            outTime[u] = time;  // 记录离开时间
        }

        // 获取u的所有因子，且因子不超过n
        static List<int> GetFactors(int u, int n)
        {
            HashSet<int> factors = new HashSet<int>();
            for (int i = 1; i * i <= u; i++)
            {
                if (u % i == 0)
                {
                    if (i <= n)
                        factors.Add(i);  // 添加因子i
                    int other = u / i;
                    if (other <= n)
                        factors.Add(other);  // 添加因子u/i
                }
            }
            return new List<int>(factors);  // 返回因子列表
        }  
    }
}