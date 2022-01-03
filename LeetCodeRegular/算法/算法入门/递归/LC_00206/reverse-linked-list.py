"""
206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

示例 1：


输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：


输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        pre, cur = None, head
        while cur != None:
            mid = cur.next
            cur.next = pre
            pre = cur
            cur = mid
        return pre
       
 #重新做到这个题时，发现可以采用栈的方式进行解答，代码如下：
 # Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        stack = []    
        while head:
            stack.append(head)
            head = head.next
        m = len(stack)
        if m == 0:
            return None
        curr = head = stack.pop() #重新开始建立链表指针，注意保留head
        while len(stack) != 0:
            curr.next = stack.pop()
            curr = curr.next
        curr.next = None
        return head
        
