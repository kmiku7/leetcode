#include <string>

using namespace std;



string bits_map[10] = {
        "",
        "I",
        "II",
        "III",
        "IV",
        "V",
        "VI",
        "VII",
        "VIII",
        "IX"
};

string tens_map[10] = {
        "",
        "X",
        "XX",
        "XXX",
        "XL",
        "L",
        "LX",
        "LXX",
        "LXXX",
        "XC"
};

string hundred_map[10] = {
        "",
        "C",
        "CC",
        "CCC",
        "CD",
        "D",
        "DC",
        "DCC",
        "DCCC",
        "CM"
};

string thousand_map[10]= {
        "",
        "M",
        "MM",
        "MMM",
        "4M",
        "5M",
        "6M",
        "7M",
        "8M",
        "9M"
};


class Solution {
public:
    string intToRoman(int num) {
        int bits = num%10;
        int tens = (num/10)%10;
        int hundred = (num/100)%10;
        int thousand = (num/1000)%10;

        return thousand_map[thousand] + hundred_map[hundred] + tens_map[tens] + bits_map[bits];
    }
};


