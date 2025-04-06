// using System;
// using System.Collections.Generic;
// using LeetCode.Properties;
//
// namespace LeetCode
// {
//     /// <summary>
//     /// 数据包类，存储数据包的属性
//     /// </summary>
//     public class Packet
//     {
//         public int Source { get; set; }
//         public int Destination { get; set; }
//         public int Timestamp { get; set; }
//
//         public Packet(int source, int destination, int timestamp)
//         {
//             Source = source;
//             Destination = destination;
//             Timestamp = timestamp;
//         }
//     }
//
//     /// <summary>
//     /// 路由器类，管理数据包
//     /// </summary>
//     public class Router
//     {
//         // 存储所有数据包的列表，保持FIFO顺序
//         private List<(int source, int destination, int timestamp)> _list;
//         // 用于快速检查重复的集合
//         private HashSet<(int source, int destination, int timestamp)> _set;
//         // 按目标地址索引的数据包映射，用于提高GetCount性能
//         private Dictionary<int, List<int>> _packetsByDestination;
//         private int _memoryLimit;
//         private int _curCount;
//
//         /// <summary>
//         /// 初始化路由器，设置内存限制
//         /// </summary>
//         /// <param name="memoryLimit">最大可存储的数据包数量</param>
//         public Router(int memoryLimit)
//         {
//             _memoryLimit = memoryLimit;
//             _curCount = 0;
//             _list = new List<(int, int, int)>();
//             _set = new HashSet<(int, int, int)>();
//             _packetsByDestination = new Dictionary<int, List<int>>();
//         }
//
//         /// <summary>
//         /// 添加数据包到路由器
//         /// </summary>
//         /// <param name="source">源机器标识符</param>
//         /// <param name="destination">目标机器标识符</param>
//         /// <param name="timestamp">到达时间戳</param>
//         /// <returns>是否成功添加（非重复数据包）</returns>
//         public bool AddPacket(int source, int destination, int timestamp)
//         {
//             var packet = (source, destination, timestamp);
//             
//             // 检查重复数据包
//             if (_set.Contains(packet)) 
//                 return false;
//             
//             // 添加到主要数据结构
//             _list.Add(packet);
//             _set.Add(packet);
//             _curCount++;
//             
//             // 添加到目标地址索引中
//             if (!_packetsByDestination.ContainsKey(destination))
//                 _packetsByDestination[destination] = new List<int>();
//             _packetsByDestination[destination].Add(timestamp);
//             
//             // 处理内存超限
//             if (_curCount > _memoryLimit)
//             {
//                 var oldestPacket = _list[0];
//                 _list.RemoveAt(0);
//                 _set.Remove(oldestPacket);
//                 
//                 // 从目标地址索引中也删除
//                 int oldDest = oldestPacket.destination;
//                 if (_packetsByDestination.ContainsKey(oldDest))
//                 {
//                     // 删除最早添加的相同目标地址的时间戳
//                     _packetsByDestination[oldDest].RemoveAt(0);
//                     if (_packetsByDestination[oldDest].Count == 0)
//                         _packetsByDestination.Remove(oldDest);
//                 }
//                 
//                 _curCount--;
//             }
//             
//             return true;
//         }
//
//         /// <summary>
//         /// 转发下一个数据包（按FIFO顺序）
//         /// </summary>
//         /// <returns>转发的数据包信息，如果没有则返回空数组</returns>
//         public int[] ForwardPacket()
//         {
//             if (_curCount > 0)
//             {
//                 var element = _list[0];
//                 int[] packet = new[] { element.source, element.destination, element.timestamp };
//                 _list.RemoveAt(0);
//                 _set.Remove(element);
//                 
//                 // 从目标地址索引中删除
//                 int dest = element.destination;
//                 if (_packetsByDestination.ContainsKey(dest))
//                 {
//                     // 找到并删除对应的时间戳
//                     for (int i = 0; i < _packetsByDestination[dest].Count; i++)
//                     {
//                         if (_packetsByDestination[dest][i] == element.timestamp)
//                         {
//                             _packetsByDestination[dest].RemoveAt(i);
//                             if (_packetsByDestination[dest].Count == 0)
//                                 _packetsByDestination.Remove(dest);
//                             break;
//                         }
//                     }
//                 }
//                 
//                 _curCount--;
//                 return packet;
//             }
//             
//             return new int[0];
//         }
//
//         /// <summary>
//         /// 获取符合条件的数据包数量
//         /// </summary>
//         /// <param name="destination">目标机器标识符</param>
//         /// <param name="startTime">开始时间戳</param>
//         /// <param name="endTime">结束时间戳</param>
//         /// <returns>符合条件的数据包数量</returns>
//         public int GetCount(int destination, int startTime, int endTime)
//         {
//             // 如果没有该目标地址的数据包，直接返回0
//             if (!_packetsByDestination.ContainsKey(destination))
//                 return 0;
//             
//             // 统计时间范围内的数据包数量
//             int count = 0;
//             foreach (int timestamp in _packetsByDestination[destination])
//             {
//                 if (timestamp >= startTime && timestamp <= endTime)
//                     count++;
//             }
//             
//             return count;
//         }
//     }
//
//     public class W444Q2A2 : ILeetCodeQuestion
//     {
//         public void Run()
//         {
//             Console.WriteLine("运行 W444Q2: 设计路由器");
//
//             // 测试用例1
//             Console.WriteLine("测试用例1:");
//             Router router1 = new Router(3);
//             Console.WriteLine($"addPacket(1, 4, 90): {router1.AddPacket(1, 4, 90)}");
//             Console.WriteLine($"addPacket(2, 5, 90): {router1.AddPacket(2, 5, 90)}");
//             Console.WriteLine($"addPacket(1, 4, 90): {router1.AddPacket(1, 4, 90)}");
//             Console.WriteLine($"addPacket(3, 5, 95): {router1.AddPacket(3, 5, 95)}");
//             Console.WriteLine($"addPacket(4, 5, 105): {router1.AddPacket(4, 5, 105)}");
//
//             int[] forwardedPacket1 = router1.ForwardPacket();
//             Console.Write($"forwardPacket(): [");
//             Console.Write(string.Join(", ", forwardedPacket1));
//             Console.WriteLine("]");
//
//             Console.WriteLine($"addPacket(5, 2, 110): {router1.AddPacket(5, 2, 110)}");
//             Console.WriteLine($"getCount(5, 100, 110): {router1.GetCount(5, 100, 110)}");
//
//             Console.WriteLine();
//
//             // 测试用例2
//             Console.WriteLine("测试用例2:");
//             Router router2 = new Router(2);
//             Console.WriteLine($"addPacket(7, 4, 90): {router2.AddPacket(7, 4, 90)}");
//
//             int[] forwardedPacket2 = router2.ForwardPacket();
//             Console.Write($"forwardPacket(): [");
//             Console.Write(string.Join(", ", forwardedPacket2));
//             Console.WriteLine("]");
//
//             int[] forwardedPacket3 = router2.ForwardPacket();
//             Console.Write($"forwardPacket(): [");
//             Console.Write(string.Join(", ", forwardedPacket3));
//             Console.WriteLine("]");
//
//             // 测试用例3
//             Console.WriteLine("测试用例3:");
//             Router router3 = new Router(2);
//             Console.WriteLine($"addPacket(1, 5, 1): {router3.AddPacket(1, 5, 1)}");
//             Console.WriteLine($"getCount(5, 1, 1): {router3.GetCount(5, 1, 1)}");
//             Console.WriteLine($"addPacket(5, 3, 1): {router3.AddPacket(5, 3, 1)}");
//             Console.WriteLine($"addPacket(2, 5, 1): {router3.AddPacket(2, 5, 1)}");
//             Console.WriteLine($"addPacket(5, 4, 1): {router3.AddPacket(5, 4, 1)}");
//             Console.WriteLine($"addPacket(2, 5, 1): {router3.AddPacket(2, 5, 1)}");
//
//             Console.WriteLine();
//         }
//     }
// }