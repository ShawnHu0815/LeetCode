using System;
using LeetCode.Properties;

namespace LeetCode
{
    public class Q142 : ILeetCodeQuestion
    {
        // 检测链表中的环
        public ListNode DetectCycle(ListNode head)
        {
            if (head == null || head.next == null) return null;

            ListNode slow = head;
            ListNode fast = head;

            while (fast != null && fast.next != null)
            {
                slow = slow.next;
                fast = fast.next.next;

                if (slow == fast)
                {
                    slow = head;
                    while (slow != fast)
                    {
                        slow = slow.next;
                        fast = fast.next;
                    }
                    return slow;
                }
            }

            return null;
        }

        // 运行示例
        public void Run()
        {
            Console.WriteLine("Running Q142: Linked List Cycle II");

            // 创建链表示例：3 -> 2 -> 0 -> -4 -> 2 (形成环)
            ListNode head = new ListNode(3);
            head.next = new ListNode(2);
            head.next.next = new ListNode(0);
            head.next.next.next = new ListNode(-4);
            head.next.next.next.next = head.next; // 形成环

            Q142 q142 = new Q142();
            ListNode result = q142.DetectCycle(head);

            Console.WriteLine(result != null ? "Cycle found at node with value: " + result.val : "No cycle found");
        }
    }
}