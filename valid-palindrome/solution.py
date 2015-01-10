class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        orig_str = [item.lower() for item in s if item.isalnum()]
        begin_idx, end_idx = 0, len(orig_str)-1
        while begin_idx < end_idx:
            if orig_str[begin_idx] != orig_str[end_idx]:
                return False
            begin_idx, end_idx = begin_idx+1, end_idx-1
        return True
