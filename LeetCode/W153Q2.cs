using System;
using System.Collections.Generic;
using System.Text;
using LeetCode.Properties;

namespace LeetCode
{
    public class W153Q2 : ILeetCodeQuestion
    {
        /// <summary>
        /// 计算执行最优操作后，二进制字符串中的最大活跃区段数
        /// </summary>
        /// <param name="s">二进制字符串</param>
        /// <returns>最大活跃区段数</returns>
        public int MaxActiveSegments(string s)
        {
            // 在字符串首尾分别添加'1'，题目要求
            var sb = new StringBuilder(s);
            sb = sb.Insert(0, "1");
            sb.Append('1');
            s = sb.ToString();
            int n = s.Length;

            // 用于统计连续的'1'和'0'的差值
            int count = 0;
            // 用于存储每个区间的差值
            var list = new List<int>();

            // 遍历字符串，统计每个区间的差值
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == '1') count++;
                else {
                    count--;
                }
                // 当前字符和下一个字符不同，表示一个区间的结束
                if (s[i] != s[i + 1]) {
                    list.Add(count); // 将当前区间的差值加入列表
                    count = 0; // 重置差值计数器
                }
            }

            // 寻找满足特定条件的区间，计算最大贡献
            int max = 0;
            for (int i = 1; i < list.Count - 1; i++) {
                // 当前区间为正，且前后区间为负
                if (list[i] > 0 && list[i - 1] < 0 && list[i + 1] < 0) {
                    int cur = Math.Abs(list[i - 1] + list[i + 1]); // 使用滑动窗口计算当前区间的最大贡献
                    max = Math.Max(max, cur); // 贪心的更新最大贡献
                }
            }

            // 计算字符串中'1'的总数
            int ans = 0;
            foreach (var c in s) {
                if (c == '1') ans++;
            }

            // 返回最终结果：'1'的总数 + 最大贡献 - 2（因为首尾添加的'1'需要减去）
            return ans + max - 2;
        }

        public void Run()
        {
            Console.WriteLine("运行 W153Q2: 操作后最大活跃区段数 I");

            // 测试用例
            string[] testCases = new string[]
            {
                "01",
                "0100",
                "1000100",
                "01010",
                "10110"
            };

            int[] expectedOutputs = new int[] { 1, 4, 7, 4, 5};

            for (int i = 0; i < testCases.Length; i++)
            {
                string s = testCases[i];
                int expected = expectedOutputs[i];
                int result = MaxActiveSegments(s);

                Console.WriteLine($"输入: \"{s}\"");
                Console.WriteLine($"输出: {result}");
                Console.WriteLine($"预期: {expected}");
                Console.WriteLine();
            }
        }
    }
}