using System;
using System.Collections.Generic;
using LeetCode.Properties;

namespace LeetCode
{
    public class W441Q1 : ILeetCodeQuestion
    {
        /// <summary>
        /// 计算删除后的最大子数组元素和
        /// </summary>
        /// <param name="nums">整数数组</param>
        /// <returns>最大子数组元素和</returns>
        public int MaximumSubarraySumAfterDeletion(int[] nums)
        {
            // TODO: 实现算法，寻找删除任意数量元素后的最大子数组元素和
            int ans = 0;
            Array.Sort(nums);
            var set = new HashSet<int>();
            foreach (var num in nums)
            {
                if (num > 0) set.Add(num);
            }
            if (set.Count > 0)
            {
                foreach (var num in set)
                {
                    ans += num;
                }
                return ans;
            }
            else
            {
                foreach (var num in nums)
                {
                    if (num == 0) return 0;
                }

                return nums[nums.Length - 1];
            }
            return -1;
        }

        public void Run()
        {
            Console.WriteLine("运行 W441Q1: 删除后的最大子数组元素和");
            
            // 测试用例
            int[][] testCases = new int[][]
            {
                new int[] {1, 2, 3, 4, 5},
                new int[] {1, 1, 0, 1, 1},
                new int[] {1, 2, -1, -2, 1, 0, -1},
                new int[] {-100}
            };
            
            int[] expectedOutputs = new int[] {15, 1, 3, -100};
            
            for (int i = 0; i < testCases.Length; i++)
            {
                int[] nums = testCases[i];
                int expected = expectedOutputs[i];
                int result = MaximumSubarraySumAfterDeletion(nums);
                
                Console.Write($"输入: [");
                Console.Write(string.Join(", ", nums));
                Console.WriteLine($"]");
                Console.WriteLine($"输出: {result}");
                Console.WriteLine($"预期: {expected}");
                Console.WriteLine();
            }
        }
    }
}