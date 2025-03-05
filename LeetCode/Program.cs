using LeetCode.Properties;

namespace LeetCode
{
    internal class Program
    {
       public static void Main(string[] args)
        {
            // 通过注释切换要运行的题目
            ILeetCodeQuestion q142 = new Q142();
            q142.Run();
        }
        
        // 删除原来的 RunQ142 方法，因为已经移动到 Q142 类中
        
    }
}