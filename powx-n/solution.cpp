class Solution {
public:
    double pow(double x, int n) {
        double sub_value[sizeof(int) * 8];
        sub_value[0] = x;
        for (int i = 1; i < (sizeof(int) * 8); ++i) {
            sub_value[i] = sub_value[i-1] * sub_value[i-1];
        }
        int idx = 0;
        unsigned tmp_n = (n > 0) ? n : -n;
        double result = 1.0;
        while (tmp_n != 0) {
            if (tmp_n & 1) {
                result *= sub_value[idx];
            }
            ++idx;
            tmp_n >>= 1;
        }
        if (n < 0) {
            result = 1 / result;
        }
        return result;
    }
};


