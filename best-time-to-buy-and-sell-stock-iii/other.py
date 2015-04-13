class Solution:
    # @return an integer as the maximum profit 
    def maxProfit(self, k, prices):
        size = len(prices)
        if k > size / 2:
            return self.quickSolve(size, prices)
        dp = [None] * (2 * k + 1)
        dp[0] = 0
        for i in range(size):
            for j in range(min(2 * k, i + 1) , 0 , -1):
                dp[j] = max(dp[j], dp[j - 1] + prices[i] * [1, -1][j % 2])
        return max(dp)

    def quickSolve(self, size, prices):
        sum = 0
        for x in range(size - 1):
            if prices[x + 1] > prices[x]:
                sum += prices[x + 1] - prices[x]
        return sum

s = Solution();
price = [1,7,2,3, 2,3]
k = 2
print s.maxProfit(k, price)
