
# [0, max_num)
def enumerator_four(max_num):
    current_nums = [0, 1, 2, 3]
    finish = False
    while not finish:
        yield current_nums
        for idx in xrange(3, -1, -1):
            current_nums[idx] += 1
            if current_nums[idx] >= max_num - 3 + idx:
                continue
            break
        for idx in xrange(idx, 3):
            current_nums[idx+1] = current_nums[idx] + 1
        finish = any((num >= max_num for num in current_nums))

            

class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
        results = []
        num.sort()
        if len(num) < 4:
            return results
        for idxs in enumerator_four(len(num)):
            selected_nums = [num[idx] for idx in idxs]
            if sum(selected_nums) == target and selected_nums not in results:
                results.append(selected_nums)
        return results
                
