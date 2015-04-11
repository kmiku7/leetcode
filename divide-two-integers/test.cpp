#include <climits>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int a = INT_MIN;

    unsigned int b = -a;
    
    cout << a << endl;
    cout << b << endl;

    return 0;
}
