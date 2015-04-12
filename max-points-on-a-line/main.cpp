#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <cstdlib>
#include <time.h>

using namespace std;


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

unsigned int sign_mask = (0x1 << sizeof(int)*8-1);

inline unsigned ssub(int left, int right, bool& positive) {
    if(((left^right)&sign_mask)==0) {
        positive = left >= right;
        return positive ? (left - right) : (right - left);
    } else {
        positive = left >= 0;
        return positive ? 
                    ((unsigned)left +(unsigned)-right)
                    : ((unsigned)-left + (unsigned)right);
    }
    
}

inline unsigned sgcd(int left, int right) {
    if(right==0) return left;
    int rem = left % right;
    while(rem) {
        left = right;
        right = rem;
        rem = left % right;
    }
    return right;
}

namespace std {

template<>
struct hash<pair<unsigned, unsigned>> {
    typedef pair<unsigned, unsigned> argument_type;
    typedef std::size_t result_type;

    result_type operator()(argument_type const& s) const {
        result_type const h1(std::hash<unsigned>()(s.first));
        result_type const h2(std::hash<unsigned>()(s.second));
        return h1^(h2<<1);
    }
};

}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        // [0] for positive & zoro & infinite slope;
        // [1] for negtive
        unordered_map<pair<unsigned, unsigned>, int> slopes[2];
        int same_point_count = 0;
        int max_on_same_line = 0;

        for(auto &origin : points) {
            slopes[0].clear();
            slopes[1].clear();
            same_point_count = 0;
            
            int temp_max = 0;
            for(auto &point : points) {
                if(origin.x == point.x && origin.y == point.y) {
                    same_point_count++;
                    continue;
                }
                bool diff_x_sign;
                unsigned diff_x_value = ssub(point.x, origin.x, diff_x_sign);
                bool diff_y_sign;
                unsigned diff_y_value = ssub(point.y, origin.y, diff_y_sign);
                int xy_gcd = sgcd(diff_x_value, diff_y_value);
                // assert(xy_gcd != 0);
                //cout << "----------" << endl;
                //cout << (origin.x) << " " << origin.y << " " << point.x << " " << point.y << endl;
                //cout << diff_x_value << " " << diff_x_sign << endl;
                //cout << diff_y_value << " " << diff_y_sign << endl;
                //cout << xy_gcd << endl;
            
                diff_x_value /= xy_gcd;
                diff_y_value /= xy_gcd;
                auto &slope = (diff_x_sign == diff_y_sign) ? slopes[0] : slopes[1];
                pair<unsigned, unsigned> key = make_pair(diff_x_value, diff_y_value);
                /*
                if(slope.find(key)!=slope.end()){
                    //cout << "find:(" << key.first << ", " << key.second << ")" << endl;
                    slope[key] += 1;
                } else {
                    //cout << "insert:(" << key.first << ", " << key.second << ")" << endl;
                    slope[key] = 1;
                }
                */
                temp_max = max(temp_max, ++slope[key]);
            }
            /*
            if(same_point_count > max_on_same_line)
                max_on_same_line = same_point_count;
            int temp_max = max_on_same_line - same_point_count;
            for(auto &slope : slopes) {
                for(auto &item : slope){
                    if(item.second > temp_max){
                        temp_max = item.second;
                    }
                }
            }
            */
            max_on_same_line = max(temp_max + same_point_count, max_on_same_line);
        } 
        return max_on_same_line;         
    }
};


#define SOLUTION Solution


vector<Point> build_case(){
    vector<Point> result;


    result.push_back(Point(0,0));
    result.push_back(Point(0,0));
    result.push_back(Point(1,1));
    result.push_back(Point(2,2));
    result.push_back(Point(0,2));
    result.push_back(Point(2,0));
    result.push_back(Point(0,INT_MAX));
    result.push_back(Point(0,INT_MIN));
    result.push_back(Point(0,INT_MAX));
    result.push_back(Point(0,INT_MIN));
    result.push_back(Point(0,INT_MAX));
    result.push_back(Point(0,INT_MIN));
    srandom(time(NULL));
    for(int i=0; i<1000; ++i) {
        result.push_back(Point(random(), -(int)random()));
    }
    return result;
}

int main(int argc, char** argv) {
    SOLUTION s;
    auto cases = build_case();

    int count = s.maxPoints(cases);
    cout << count << endl;

    return 0;
}
