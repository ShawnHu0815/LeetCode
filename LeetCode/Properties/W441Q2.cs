using System;
using System.Collections.Generic;
using System.Linq;
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
            var map = new Dictionary<int, int>();
            for (int i = 0; i < n; i++)
            {
                map.Add(i,nums[i]); // 存储下标-数字对
            }
            int m = queries.Length;
            int[] answer = new int[m];
            for (int i = 0; i < m; i++)
            {
                int index = queries[i];
                int num = nums[index];
                var keysWithSameValue = map
                    .Where(pair => pair.Value == num)
                    .Select(pair => pair.Key)
                    .ToList();
                if (keysWithSameValue.Count == 1)
                {
                    answer[i] = -1;
                    continue;
                }
                
                int min = Int32.MaxValue;
                foreach (var sameValueIndex in keysWithSameValue)
                {
                    if(sameValueIndex == index )continue;
                    int minIndex = Math.Min(Math.Abs(sameValueIndex - index), sameValueIndex + n - index);
                    minIndex = Math.Min(index + n - sameValueIndex, minIndex);
                    min = Math.Min(min, minIndex);
                }
                answer[i] = min;
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
                new int[] {1, 2, 3, 4},
                new int[] {6,12,17,9,16,7,6}
                
            };
            
            int[][] testQueries = new int[][]
            {
                new int[] {0, 3, 5},
                new int[] {0, 1, 2, 3},
                new int[] {5,6,0,4}
            };
            
            int[][] expectedOutputs = new int[][]
            {
                new int[] {2, -1, 3},
                new int[] {-1, -1, -1, -1},
                new int[] {-1,1,1,-1}
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