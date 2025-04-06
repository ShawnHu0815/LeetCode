using System;
using System.Collections.Generic;
using LeetCode.Properties;

namespace LeetCode
{
    /// <summary>
    /// 数据包类，存储数据包的属性
    /// </summary>
    public class Packet
    {
        public int Source { get; set; }
        public int Destination { get; set; }
        public int Timestamp { get; set; }

        public Packet(int source, int destination, int timestamp)
        {
            Source = source;
            Destination = destination;
            Timestamp = timestamp;
        }
    }

    /// <summary>
    /// 路由器类，管理数据包
    /// </summary>
    public class Router
    {
        // TODO: 添加必要的数据结构来存储数据包
        private List<(int, int, int)> list;
        private HashSet<(int, int, int)> set;
        private int _memoryLimit;
        private int _curCount;

        /// <summary>
        /// 初始化路由器，设置内存限制
        /// </summary>
        /// <param name="memoryLimit">最大可存储的数据包数量</param>
        public Router(int memoryLimit)
        {   
            // TODO: 初始化数据结构
            _memoryLimit = memoryLimit;
            _curCount = 0;
            list = new List<(int, int, int)>();
            set = new HashSet<(int, int, int)>();
        }

        /// <summary>
        /// 添加数据包到路由器
        /// </summary>
        /// <param name="source">源机器标识符</param>
        /// <param name="destination">目标机器标识符</param>
        /// <param name="timestamp">到达时间戳</param>
        /// <returns>是否成功添加（非重复数据包）</returns>
        public bool AddPacket(int source, int destination, int timestamp)
        {
            // TODO: 实现添加数据包的逻辑
            var packet = ( source, destination, timestamp );
            if (set.Contains(packet)) return false;
            list.Add(packet);
            set.Add(packet);
            _curCount++;
            if (_curCount > _memoryLimit)
            {
                var oldestPacket = list[0];
                list.RemoveAt(0);
                set.Remove(oldestPacket);
                _curCount--;
            }
            return true;
        }

        /// <summary>
        /// 转发下一个数据包（按FIFO顺序）
        /// </summary>
        /// <returns>转发的数据包信息，如果没有则返回空数组</returns>
        public int[] ForwardPacket()
        {
            // TODO: 实现转发数据包的逻辑
            if (_curCount > 0)
            {
                var element = list[0];
                int[] packet = new[] { element.Item1, element.Item2, element.Item3 };
                list.RemoveAt(0);
                set.Remove((element.Item1, element.Item2, element.Item3));
                _curCount--;
                return packet;
            }
            return new int[0];
        }

        /// <summary>
        /// 获取符合条件的数据包数量
        /// </summary>
        /// <param name="destination">目标机器标识符</param>
        /// <param name="startTime">开始时间戳</param>
        /// <param name="endTime">结束时间戳</param>
        /// <returns>符合条件的数据包数量</returns>
        public int GetCount(int destination, int startTime, int endTime)
        {
            // TODO: 实现获取符合条件的数据包数量的逻辑
            int ans = 0;
            foreach (var element in list)
            {
                if (element.Item2 == destination)
                {
                    if (element.Item3 >= startTime && element.Item3 <= endTime )
                    {
                        ans++;
                    }
                }
            }
            return ans;
        }
    }

    public class W444Q2A1 : ILeetCodeQuestion
    {
        public void Run()
        {
            Console.WriteLine("运行 W444Q2: 设计路由器");

            // 测试用例1
            Console.WriteLine("测试用例1:");
            Router router1 = new Router(3);
            Console.WriteLine($"addPacket(1, 4, 90): {router1.AddPacket(1, 4, 90)}");
            Console.WriteLine($"addPacket(2, 5, 90): {router1.AddPacket(2, 5, 90)}");
            Console.WriteLine($"addPacket(1, 4, 90): {router1.AddPacket(1, 4, 90)}");
            Console.WriteLine($"addPacket(3, 5, 95): {router1.AddPacket(3, 5, 95)}");
            Console.WriteLine($"addPacket(4, 5, 105): {router1.AddPacket(4, 5, 105)}");
            
            int[] forwardedPacket1 = router1.ForwardPacket();
            Console.Write($"forwardPacket(): [");
            Console.Write(string.Join(", ", forwardedPacket1));
            Console.WriteLine("]");
            
            Console.WriteLine($"addPacket(5, 2, 110): {router1.AddPacket(5, 2, 110)}");
            Console.WriteLine($"getCount(5, 100, 110): {router1.GetCount(5, 100, 110)}");
            
            Console.WriteLine();

            // 测试用例2
            Console.WriteLine("测试用例2:");
            Router router2 = new Router(2);
            Console.WriteLine($"addPacket(7, 4, 90): {router2.AddPacket(7, 4, 90)}");
            
            int[] forwardedPacket2 = router2.ForwardPacket();
            Console.Write($"forwardPacket(): [");
            Console.Write(string.Join(", ", forwardedPacket2));
            Console.WriteLine("]");
            
            int[] forwardedPacket3 = router2.ForwardPacket();
            Console.Write($"forwardPacket(): [");
            Console.Write(string.Join(", ", forwardedPacket3));
            Console.WriteLine("]");
            
            // 测试用例3
            Console.WriteLine("测试用例3:");
            Router router3 = new Router(2);
            Console.WriteLine($"addPacket(1, 5, 1): {router3.AddPacket(1, 5, 1)}");
            Console.WriteLine($"getCount(5, 1, 1): {router3.GetCount(5, 1, 1)}");
            Console.WriteLine($"addPacket(5, 3, 1): {router3.AddPacket(5, 3, 1)}");
            Console.WriteLine($"addPacket(2, 5, 1): {router3.AddPacket(2, 5, 1)}");
            Console.WriteLine($"addPacket(5, 4, 1): {router3.AddPacket(5, 4, 1)}");
            Console.WriteLine($"addPacket(2, 5, 1): {router3.AddPacket(2, 5, 1)}");
            
            Console.WriteLine();
        }
    }
}