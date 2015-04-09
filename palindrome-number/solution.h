

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int original_x = x;
        int reversed = 0;
        int prev_reversed = 0;
        int reversed_div_10 = 0;

        while(x && prev_reversed==reversed_div_10){
            prev_reversed = reversed;
            reversed = reversed*10 + x%10;
            x = x/10;
            reversed_div_10 = reversed/10;
        }
        return original_x == reversed && reversed_div_10==prev_reversed;
    }
};
