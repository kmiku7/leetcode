#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needle_size = needle.size();
        const char* needle_str = needle.c_str();
        int backtrack[needle_size+1];
        backtrack[0] = -1;

        int pos_idx = 0;
        int suffix_idx = -1;
        while(pos_idx<needle_size-1) {
            if(suffix_idx==-1 || needle_str[pos_idx] == needle_str[suffix_idx]) {
                pos_idx += 1;
                suffix_idx += 1;
                if(needle_str[pos_idx] == needle_str[suffix_idx]) {
                    backtrack[pos_idx] = backtrack[suffix_idx];
                } else {
                    backtrack[pos_idx] = suffix_idx;
                }
            } else {
                suffix_idx = backtrack[suffix_idx];
            }
        }
        // print backtrack array
        //for(int i=0; i<needle_size; ++i) {
        //    cout << backtrack[i] << ", ";
        //}
        //cout << endl;

        // find
        pos_idx = -1;
        int haystack_size = haystack.size();
        const char* haystack_str = haystack.c_str();
        int needle_pos = -1;
        while(pos_idx < haystack_size && needle_pos < needle_size) {
            //cout << "find: " << needle_pos << ", " << pos_idx << endl;
            if(needle_pos == -1 || haystack_str[pos_idx] == needle_str[needle_pos]) {
                pos_idx += 1;
                needle_pos += 1;
            } else {
                needle_pos = backtrack[needle_pos];
            }
        }

        return needle_pos == needle_size ? pos_idx - needle_size : -1;
    }
};


int main(int argc, char** argv) {

    string a = "aaa";
    string b = "aaa";
    string c = "abc";
    string d = "aaaaaaaaaaaaaaaaaaaaaaaaaa";

    string aa = "mississippi";
    string bb = "issip";

    Solution s;
    cout << s.strStr(a, b) << endl;
//    cout << s.strStr(a, c) << endl;
//    cout << s.strStr(a, d) << endl;
    cout << s.strStr(aa, bb) << endl;

    string paper = "As is the case in radio frequency transmission systems, multipath propagation \
effects are important for wireless optical networks. The power launched from \
the transmitter may take many reflected and refracted paths before arriving at \
the receiver. In radio systems, the sum of the transmitted signal and its images \
at the receive antenna cause spectral nulls in the transmission characteristic. \
These nulls are located at frequencies where the phase shift between the paths \
causes destructive interference at the receiver. This effect is known as multipath \
fading [19]. \
Unlike radio systems, multipath fading is not a major impairment in wireless \
optical transmission. The “antenna” in a wireless optical system is the light \
detector which typically has an active radiation collection area of approximately \
The relative size of this antenna with respect to the wavelength of the \
infrared light is immense, on the order of The multipath propagation of \
light produces fades in the amplitude of the received electromagnetic signal at \
spacings on the order of half a wavelength apart. As mentioned earlier, the light \
detector is a square law device which integrates the square of the amplitude of \
the electromagnetic radiation impinging on it. The large size of the detector \
with respect to the wavelength of the light provides a degree of inherent spatial \
diversity in the receiver which mitigates the impact of multipath fading [2]. \
Although multipath fading is not a major impediment to wireless optical \
links, temporal dispersion of the received signal due to multipath propagation \
remains a problem. This dispersion is often modelled as a linear time invariant \
system since the channel properties change slowly over many symbol periods \
[ 1, 20]. The impact of multipath dispersion is most noticeable in diffuse infrared \
communication systems, which are described in more detail in Section 2.4.2. In \
short distance line-of-sight (LOS) links, presented in Section 2.4.1, multipath \
dispersion is seldom an issue. Indeed, channel models proposed for LOS links \
assume the LOS path dominates and model the channel as a linear attenuation \
and delay [21].";
    string target = "dispersion";
    for( int i=0; i<2000; ++i) 
        cout << s.strStr(paper, target) << endl;
    

    return 0;
}
