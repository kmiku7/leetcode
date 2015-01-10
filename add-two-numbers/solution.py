# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import sys
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    @classmethod
    def build_num(cls, num):
        remain, digit = divmod(num, 10)
        head = ListNode(digit)
        prev_node = head
        while remain != 0:
            remain, digit = divmod(remain, 10)
            prev_node.next = ListNode(digit)
            prev_node = prev_node.next
        return head

    def print_r(self):
        if self.next is not None:
            self.next.print_r()
        sys.stdout.write(str(self.val))

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        left, right = l1, l2
        carry, digit_sum = divmod(left.val + right.val, 10)
        head = ListNode(digit_sum)
        prev_node = head
        left, right = left.next, right.next
        while left is not None and right is not None:
            carry, digit_sum = divmod(left.val + right.val + carry, 10)
            prev_node.next = ListNode(digit_sum)
            prev_node = prev_node.next
            left, right = left.next, right.next
        tail_remain = left if right is None else right
        while tail_remain is not None:
            carry, digit_sum = divmod(tail_remain.val + carry, 10)
            prev_node.next = ListNode(digit_sum)
            prev_node = prev_node.next
            tail_remain = tail_remain.next
        if carry != 0:
            prev_node.next = ListNode(carry)
        return head
            
        
