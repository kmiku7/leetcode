#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <random>
#include <chrono>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        //sort(num.begin(), num.end());
        //return num[num.size()/2];       
        nth_element(num.begin(), num.begin()+num.size()/2, num.end());
        return num[num.size()/2];       

    }
};

class Solution1{
public:
    int majorityElement(vector<int>& num) {
        unordered_map<int, int> counter;
        for(auto iter = num.begin(); iter!=num.end(); ++iter){
            if(counter.find(*iter)==counter.end()){
                counter[*iter] = 1;
            } else {
                counter[*iter] += 1;
                if(counter[*iter] > num.size()/2) return *iter;
            }
        }
        return INT_MAX;
    }
};

class Solution2{
public:
    int majorityElement(vector<int>& num) {
        int majority = num[0];
        int count = 1;
        for(int i=1; i<num.size(); ++i){
            if(num[i]==majority){
                count += 1;
            } else {
                count -= 1;
                if(count==0){
                    majority = num[i];
                    count = 1;
                }
            }
        }
        return majority;
    }
};


int main(int argc, char** argv) {

    //vector<int> case_a = {2,3,1,1,1};
    int count = 100000;
    vector<int> case_a(count, INT_MAX);
    srandom(time(NULL));
    for(int i=0; i<(count-1); ++i){
        case_a.push_back(random()%count);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(case_a.begin(), case_a.end(), std::default_random_engine(seed));

    SOLUTION s;
    cout << s.majorityElement(case_a) << endl;

    return 0;
}
