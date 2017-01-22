# 解题思路
# 正确写出链表反转即可

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l1 = self.RevertListNode(l1)
        l2 = self.RevertListNode(l2)
        head = None
        temp = None
        add = 0
        while (l1 != None or l2 != None or add != 0):
            newNode = ListNode(add)
            add = 0
            if (l1):
                newNode.val += l1.val
            if (l2):
                newNode.val += l2.val
            add = newNode.val / 10
            newNode.val %= 10

            if (temp):
                temp.next = newNode
                temp = temp.next
            else:
                head = newNode
                temp = newNode

            if (l1):
                l1 = l1.next
            if (l2):
                l2 = l2.next

        return self.RevertListNode(head)

    def RevertListNode(self, head):
        pre = None
        cur = head
        while (cur):
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp
        return pre

