using System;
using System.Collections.Generic;
using LeetCode.Properties;

namespace LeetCode
{
    public class W152Q2 : ILeetCodeQuestion
    {
        /// <summary>
        /// 计算可以形成的不同三位偶数的数量
        /// </summary>
        /// <param name="digits">输入的数字数组</param>
        /// <returns>可以形成的不同三位偶数的数量</returns>
        public int CountEvenThreeDigitNumbers(int[] digits)
        {
            HashSet<int> validNumbers = new HashSet<int>();
            int n = digits.Length;
            
            for (int i = 0; i < n; i++)
            {
                if (digits[i] == 0) continue;
                
                for (int j = 0; j < n; j++)
                {
                    if (j == i) continue;
                    
                    for (int k = 0; k < n; k++)
                    {
                        if (k == i || k == j) continue;
                        
                        if (digits[k] % 2 == 0)
                        {
                            int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                            validNumbers.Add(number);
                        }
                    }
                }
            }
            
            return validNumbers.Count;
        }

        public void Run()
        {
            Console.WriteLine("运行 W152Q2: 计算可以形成的不同三位偶数的数量");
            
            // 测试用例
            int[][] testCases = new int[][]
            {
                new int[] {1, 2, 3, 4},
                new int[] {0, 2, 2},
                new int[] {6, 6, 6},
                new int[] {1, 3, 5},
                new int[] {1,2,3,0,0},
                new int[] {1,3,3,0,0},
                new int[] {1,2,3,4,0},
                new int[] {1,2,3,3,0}
            };
            
            int[] expectedOutputs = new int[] {12, 2, 1, 0,3,2,30,12};
            
            for (int i = 0; i < testCases.Length; i++)
            {
                int[] digits = testCases[i];
                int expected = expectedOutputs[i];
                int result = CountEvenThreeDigitNumbers(digits);
                
                Console.Write($"输入: [");
                Console.Write(string.Join(", ", digits));
                Console.WriteLine($"]");
                Console.WriteLine($"输出: {result}");
                Console.WriteLine($"预期: {expected}");
                Console.WriteLine();
            }
        }
    }
}