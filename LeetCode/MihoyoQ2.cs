using System;
using System.Collections.Generic;
using LeetCode.Properties;

namespace LeetCode
{
    public class MihoyoQ2 : ILeetCodeQuestion
    {
        /// <summary>
        /// 计算每秒没有史莱姆的格子数量
        /// </summary>
        /// <param name="n">格子数量</param>
        /// <param name="directions">每只史莱姆的跳跃方向</param>
        /// <returns>每秒没有史莱姆的格子数量数组</returns>
        public int[] CalculateEmptyCells(int n, int[] directions)
        {
            int[] result = new int[n];
            List<ulong> left = new List<ulong>();  // 使用 ulong 存储位掩码
            List<ulong> right = new List<ulong>();

            for (int i = 0; i < n; i++)
            {
                if (directions[i] == 1)
                {
                    right.Add(1UL << (n - i - 1));  // 使用 UL 后缀确保 64 位存储
                }
                else
                {
                    left.Add(1UL << (n - i - 1));
                }
            }

            for (int i = 0; i < n; i++)
            {
                ulong temp = 0;  // 使用 ulong 保存所有位
                for (int j = 0; j < left.Count; j++)
                {
                    left[j] = (left[j] << 1) % (1UL << n);  // 确保模运算的正确性
                    temp |= left[j];
                }

                for (int j = 0; j < right.Count; j++)
                {
                    right[j] >>= 1;
                    temp |= right[j];
                }

                int cur = 0;
                // 检查每一位对应的实际格子
                for (int j = 0; j < n; j++)
                {
                    // 注意位顺序与实际格子的对应关系：
                    // 第 j 位对应格子 (n - j)
                    if ((temp & (1UL << (n - j - 1))) == 0)
                    {
                        cur++;
                    }
                }
                result[i] = cur;
            }
            return result;
        }

        public void Run()
        {
            Console.WriteLine("运行 MihoyoQ2: 米小游和蹦蹦史莱姆");

            // 测试用例
            int[] sizes = new int[] { 3 };
            int[][] directionsArray = new int[][]
            {
                new int[] { 1, 0, 1 }
            };

            int[][] expectedOutputs = new int[][]
            {
                new int[] { 1, 2, 3 }
            };

            for (int i = 0; i < sizes.Length; i++)
            {
                int n = sizes[i];
                int[] directions = directionsArray[i];
                int[] expected = expectedOutputs[i];
                int[] result = CalculateEmptyCells(n, directions);

                Console.WriteLine($"格子数量: {n}");
                
                Console.Write($"跳跃方向: ");
                Console.WriteLine(string.Join(" ", directions));
                
                Console.Write($"计算结果: ");
                Console.WriteLine(string.Join(" ", result));
                
                Console.Write($"期望结果: ");
                Console.WriteLine(string.Join(" ", expected));
                
                Console.WriteLine();
            }
        }
    }
}