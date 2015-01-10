class Solution:
    # @param ratings, a list of integer
    # @return an integer
    def candy(self, ratings):
        ratings_len = len(ratings)
        candies_count = [0] * ratings_len
        candies_count[0] = 1
        for idx in xrange(1, ratings_len):
            if ratings[idx] > ratings[idx-1]:
                candies_count[idx] = candies_count[idx-1] + 1
            else:
                candies_count[idx] = 1
        for idx in xrange(ratings_len-2, -1, -1):
            if ratings[idx] > ratings[idx+1] and candies_count[idx] <= candies_count[idx+1]:
                candies_count[idx] = candies_count[idx+1] + 1
        return sum(candies_count)
