#include <string>
#include <unordered_map>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

namespace std{
template<>
struct hash<pair<long long, long long>> {
    typedef pair<long long, long long> argument_type;
    typedef std::size_t result_type;

    result_type operator()(argument_type const& s) const {
        result_type const h1(std::hash<long long>()(s.first));
        result_type const h2(std::hash<long long>()(s.second));
        return h1^(h2<<24);
    }
};
}

class Solution {
public:
    string fractionToDecimal(int numerator_r, int denominator_r) {
        long long int numerator = numerator_r;
        long long int denominator = denominator_r;
        vector<char> result;
        if((numerator^denominator)&(0x1ll<<(sizeof(long long int)*8-1)) && numerator!=0) {
            result.push_back('-');
        }
        numerator = llabs(numerator);
        denominator = llabs(denominator);
        unordered_map<pair<long long, long long>, int> loop_pos;
        string int_part = to_string(numerator/denominator);
        numerator = numerator % denominator;
        result.insert(result.end(), int_part.begin(), int_part.end());
        if(numerator==0) {
            goto END;
        }
        result.push_back('.');

        while(numerator) {
            char int_part = numerator*10/denominator + '0';
            numerator = numerator*10 % denominator;
            auto key = make_pair(numerator, denominator);
            if(loop_pos.find(key)==loop_pos.end()) {
                loop_pos[key] = result.size();
                result.push_back(int_part);
            } else {
                result.insert(result.begin()+loop_pos[key], '(');
                result.push_back(')');
                break;
            }
            long long gcd = get_gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
        }
END:
        return string(result.begin(), result.end());
    }
private:
    long long get_gcd(long long left, long long right) {
        long long rem = right;
        while(rem) {
            rem = left % right;
            left = right;
            right = rem;
        }
        return left;
    }
};


int main(int argc, char** argv) {
    int nums[] = {
        1,6,
        1,2,
        2,1,
        2,3,
        100,3,
        50,7,
        -50,7,
        50,-7,
        7, -12,
        1, 7,
        22, 7,
        INT_MAX, -1,
        INT_MIN, -1,
        -1, INT_MIN,
    };
    int count = sizeof(nums)/sizeof(int);
    Solution s;
    for(int i=0; i<count; i+=2) {
        cout << nums[i] << "," << nums[i+1] << ", ";
        cout << s.fractionToDecimal(nums[i], nums[i+1]) << ", ";
        cout << (double)nums[i]/nums[i+1] << endl;
    }
}
