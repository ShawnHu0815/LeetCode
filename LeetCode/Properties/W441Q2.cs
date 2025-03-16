using System;
using LeetCode.Properties;

namespace LeetCode
{
    public class W441Q2 : ILeetCodeQuestion
    {
        /// <summary>
        /// 计算每个查询点到相同值的最小距离（考虑循环数组）
        /// </summary>
        /// <param name="nums">循环数组</param>
        /// <param name="queries">查询的索引</param>
        /// <returns>每个查询的结果数组</returns>
        public int[] MinimumDistanceQueries(int[] nums, int[] queries)
        {
            // TODO: 实现算法，计算每个查询点到相同值的最小距离
            int n = nums.Length;
            int m = queries.Length;
            int[] answer = new int[m];
            for (int i = 0; i < m; i++)
            {
                int index = queries[i];
                int num = nums[index];
                bool isFound = false;
                for (int j = 1; j < n; j++)
                {
                    if (nums[(index + j) % n] == num || nums[(index - j + n) % n] == num)
                    {
                        isFound = true;
                        answer[i] = j;
                        break;
                    }
                }
                if(isFound == false) answer[i] = -1;
            }
            
            return answer;
        }

        public void Run()
        {
            Console.WriteLine("运行 W441Q2: 距离最小相等元素查询");
            
            // 测试用例
            int[][] testNums = new int[][]
            {
                new int[] {1, 3, 1, 4, 1, 3, 2},
                new int[] {1, 2, 3, 4}
            };
            
            int[][] testQueries = new int[][]
            {
                new int[] {0, 3, 5},
                new int[] {0, 1, 2, 3}
            };
            
            int[][] expectedOutputs = new int[][]
            {
                new int[] {2, -1, 3},
                new int[] {-1, -1, -1, -1}
            };
            
            for (int i = 0; i < testNums.Length; i++)
            {
                int[] nums = testNums[i];
                int[] queries = testQueries[i];
                int[] expected = expectedOutputs[i];
                int[] result = MinimumDistanceQueries(nums, queries);
                
                Console.Write($"nums: [");
                Console.Write(string.Join(", ", nums));
                Console.WriteLine($"]");
                
                Console.Write($"queries: [");
                Console.Write(string.Join(", ", queries));
                Console.WriteLine($"]");
                
                Console.Write($"输出: [");
                Console.Write(string.Join(", ", result));
                Console.WriteLine($"]");
                
                Console.Write($"预期: [");
                Console.Write(string.Join(", ", expected));
                Console.WriteLine($"]");
                Console.WriteLine();
            }
        }
    }
}