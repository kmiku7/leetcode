# o(n**3)

class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
        results = []
        num.sort()
        num_len = len(num)
        if num_len < 4:
            return results
        for idx_first in xrange(num_len):
            if sum(num[idx_first:idx_first+4]) > target:
                break
            for idx_second in xrange(idx_first+1, num_len):
                first_two_sum = num[idx_first] + num[idx_second]
                if num[idx_first] + sum(num[idx_second:idx_second+3]) > target:
                    break
                twoSum(num, num_len, idx_second+1, target - first_two_sum, [idx_first, idx_second], results)
        return results

def twoSum(num, num_len, begin, target, prefix, results):
    first_idx = begin
    last_idx = num_len - 1
    while first_idx < last_idx:
        two_sum = num[first_idx] + num[last_idx]
        if two_sum < target:
            first_idx += 1
        elif two_sum == target:
            tmp_prefix = list(prefix)
            tmp_prefix.append(first_idx)
            tmp_prefix.append(last_idx)
            selected_num = [num[idx] for idx in tmp_prefix]
            if selected_num not in results:
                results.append(selected_num)
            first_idx += 1
        else:
            last_idx -= 1

