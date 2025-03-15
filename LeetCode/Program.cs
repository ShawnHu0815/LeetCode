using LeetCode.Properties;

namespace LeetCode
{
    internal class Program
    {
       public static void Main(string[] args)
       {
           // 通过注释切换要运行的题目
           // ILeetCodeQuestion q142 = new Q142();
           // q142.Run();
           
           // ILeetCodeQuestion w152q2 = new W152Q2();
           // w152q2.Run();
           
           ILeetCodeQuestion w152q3 = new W152Q3();
           w152q3.Run();
       }
    }
}