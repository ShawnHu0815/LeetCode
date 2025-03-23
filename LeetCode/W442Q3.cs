using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Properties
{
    /// <summary>
    /// 周赛442 - 第3题：巫师酿造药水的最短时间
    /// 
    /// 题目描述：
    /// 给你两个长度分别为 n 和 m 的整数数组 skill 和 mana。
    /// 在一个实验室里，有 n 个巫师，他们必须按顺序酿造 m 个药水。
    /// 每个药水的法力值为 mana[j]，并且每个药水必须依次通过所有巫师处理，才能完成酿造。
    /// 第 i 个巫师在第 j 个药水上处理需要的时间为 timeij = skill[i] * mana[j]。
    /// 由于酿造过程非常精细，药水在当前巫师完成工作后必须立即传递给下一个巫师并开始处理。
    /// 这意味着时间必须保持同步，确保每个巫师在药水到达时马上开始工作。
    /// 返回酿造所有药水所需的最短总时间。
    /// </summary>
    internal class W442Q3 : ILeetCodeQuestion
    {
        public void Run()
        {
            // 测试用例1
            int[] skill1 = { 1, 5, 2, 4 };
            int[] mana1 = { 5, 1, 4, 2 };
            Console.WriteLine($"Example 1: {MinTimeToCompleteAllPotions(skill1, mana1)}"); // 预期输出: 110

            // 测试用例2
            int[] skill2 = { 1, 1, 1 };
            int[] mana2 = { 1, 1, 1 };
            Console.WriteLine($"Example 2: {MinTimeToCompleteAllPotions(skill2, mana2)}"); // 预期输出: 5

            // 测试用例3
            int[] skill3 = { 1, 2, 3, 4 };
            int[] mana3 = { 1, 2 };
            Console.WriteLine($"Example 3: {MinTimeToCompleteAllPotions(skill3, mana3)}"); // 预期输出: 21
        }

        /// <summary>
        /// 计算酿造所有药水所需的最短总时间
        /// </summary>
        /// <param name="skill">n个巫师的技能值</param>
        /// <param name="mana">m个药水的法力值</param>
        /// <returns>酿造所有药水所需的最短总时间</returns>
        public long MinTimeToCompleteAllPotions(int[] skill, int[] mana)
        {
            int n = skill.Length;
            int m = mana.Length;
            var lastFinish = new long[n]; // 记录巫师上次完成的时间
            for (int medicineIdx = 0; medicineIdx < m; medicineIdx++)
            {
                long sumTime = 0;
                for (int peopleIdx = 0; peopleIdx < n; peopleIdx++)
                {
                    // 正向计算第一次完成最后需要的总时间
                    // 巫师完成的时间 = Max(前一个巫师完成的时间，上次自己完成的时间) + 本次需要的时间
                    sumTime = Math.Max(sumTime, lastFinish[peopleIdx]) + skill[peopleIdx] * mana[medicineIdx];
                }
                
                // 从最终完成的时间反推实际每个巫师的完成时间是多少
                lastFinish[n - 1] = sumTime;
                for (int peopleIdx = n-2; peopleIdx >= 0; peopleIdx--)
                {
                    sumTime -= skill[peopleIdx + 1] * mana[medicineIdx];
                    lastFinish[peopleIdx] = sumTime;
                }
            }
            // 返回最后的完成时间
            return lastFinish[n-1]; // 返回你的答案
        }
    }
}