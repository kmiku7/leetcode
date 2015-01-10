class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        bit_zero = 0
        bit_one = 0
        for item in A:
            # add
            bit_one, bit_zero = ((bit_zero & item) ^ bit_one), (bit_zero ^ item)
            # mod 3
            bit_one, bit_zero= (bit_one & ~bit_zero), (bit_zero & ~bit_one)
        assert bit_one == 0 or bit_zero == 0
        return bit_one | bit_zero
            

