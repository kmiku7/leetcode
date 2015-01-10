import solution
from solution import ListNode
import sys

def main():
    left = ListNode.build_num(99)
    right = ListNode.build_num(1)
    op = solution.Solution().addTwoNumbers
    sum = op(left, right)
    left.print_r()
    print ""
    right.print_r()
    print ""
    sum.print_r()
    print ""

if __name__ == "__main__":
    main()
