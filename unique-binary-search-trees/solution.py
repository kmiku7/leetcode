class Solution:
    # @return an integer
    def numTrees(self, n):
        if n <= 1:
            return 1
        combis = [1, 1]
        for x in xrange(2, n+1):
            left = 0
            right = x - left - 1
            combi = 0
            while left < right:
                combi += combis[left] * combis[right] * 2
                left += 1
                right -= 1
            if left == right:
                combi += combis[left] * combis[right]
            combis.append(combi)
        return combis[-1]

            
