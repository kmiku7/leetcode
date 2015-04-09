

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int original_x = x;
        int reversed = 0;
        int prev_reversed = 0;

        while(x && prev_reversed<=reversed){
            prev_reversed = reversed;
            reversed = reversed*10 + x%10;
            x = x/10;
        }
        return original_x == reversed && reversed>=prev_reversed;
    }
};
