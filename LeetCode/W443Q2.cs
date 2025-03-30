using System;
using LeetCode.Properties;

namespace LeetCode
{
    public class W443Q2 : ILeetCodeQuestion
    {
        /// <summary>
        /// 计算通过拼接两个字符串的子串所能构造的最长回文串长度
        /// </summary>
        /// <param name="s">第一个字符串</param>
        /// <param name="t">第二个字符串</param>
        /// <returns>最长回文串长度</returns>
        public int LongestPalindrome(string s, string t)
        {
            // 计算字符串 s 中最长的回文子串长度
            int maxLenS = LongestPalindromeInString(s);
            // 计算字符串 t 中最长的回文子串长度
            int maxLenT = LongestPalindromeInString(t);
            // 初始化答案为 s 和 t 中最长回文子串的较大值
            int ans = Math.Max(maxLenS, maxLenT);

            // 遍历字符串 s 的所有子串
            for (int i = 0; i < s.Length; i++)
            {
                for (int j = i; j < s.Length; j++)
                {
                    // 遍历字符串 t 的所有子串
                    for (int k = 0; k < t.Length; k++)
                    {
                        for (int l = k; l < t.Length; l++)
                        {
                            // 拼接 s 的子串和 t 的子串
                            string combined = s.Substring(i, j - i + 1) + t.Substring(k, l - k + 1);
                            // 检查拼接后的字符串是否是回文
                            if (IsPalindrome(combined))
                            {
                                // 更新答案为当前最长的回文长度
                                ans = Math.Max(ans, combined.Length);
                            }
                        }
                    }
                }
            }

            // 返回最终的最长回文长度
            return ans;
        }

        // 中心扩展法辅助函数：从中心向两边扩展，找到最长的回文子串长度
        private int ExpandAroundCenter(string s, int left, int right)
        {
            int n = s.Length;
            // 当左右指针合法且字符相等时，继续扩展
            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }

            // 返回回文子串的长度
            return right - left - 1;
        }

        // 计算单个字符串中最长的回文子串长度
        private int LongestPalindromeInString(string s)
        {
            int n = s.Length;
            int max = 0;
            // 遍历每个字符，分别考虑奇数长度和偶数长度的回文
            for (int i = 0; i < n; i++)
            {
                // 奇数长度的回文
                int len1 = ExpandAroundCenter(s, i, i);
                // 偶数长度的回文
                int len2 = ExpandAroundCenter(s, i, i + 1);
                // 更新最长回文子串的长度
                max = Math.Max(max, Math.Max(len1, len2));
            }

            return max;
        }

// 检查一个字符串是否是回文
        private bool IsPalindrome(string str)
        {
            int left = 0, right = str.Length - 1;
            // 使用双指针从两端向中间检查
            while (left < right)
            {
                if (str[left] != str[right])
                {
                    return false; // 如果有不相等的字符，则不是回文
                }

                left++;
                right--;
            }

            return true; // 所有字符都相等，是回文
        }

        public void Run()
        {
            Console.WriteLine("运行 W443Q2: 拼接构造最长回文串");

            // 测试用例
            string[][] testCases = new string[][]
            {
                new string[] { "a", "a" },
                new string[] { "abc", "def" },
                new string[] { "b", "aaaa" },
                new string[] { "abcde", "ecdba" }
            };

            int[] expectedOutputs = new int[] { 2, 1, 4, 5 };

            for (int i = 0; i < testCases.Length; i++)
            {
                string s = testCases[i][0];
                string t = testCases[i][1];
                int expected = expectedOutputs[i];
                int result = LongestPalindrome(s, t);

                Console.WriteLine($"输入: s = \"{s}\", t = \"{t}\"");
                Console.WriteLine($"输出: {result}");
                Console.WriteLine($"预期: {expected}");
                Console.WriteLine();
            }
        }
    }
}