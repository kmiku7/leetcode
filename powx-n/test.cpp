#include <iostream>
#include <cmath>

using namespace std;

#include "solution.cpp"

int main(int argc, char** argv) {
    Solution ss;
    int arr[] = {
                1, 100, 
                2, 100, 
                2, -100, 
                2, 0,
                1.00000, -2147483648};
    for (int i = 0; i < sizeof(arr)/sizeof(int); i += 2) {
        cout << pow(arr[i], arr[i+1]) << "\t" << ss.pow(arr[i], arr[i+1]) << endl;
    }
    return 0;
}
