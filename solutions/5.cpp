#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        vector<int> f(size, 0);
        vector<int> f_half(size, 0);
        for(int center = 0; center < size; ++center){
            int len = 1;
            while(center - len >= 0 && center + len < size && s[center - len] == s[center + len]){
                len += 1;
            }
            f[center] = len * 2 - 1;
        }
        for(int center = 0; center < size - 1; ++center){
            int len = 0;
            while(center - len >= 0 && center + len + 1 < size && s[center - len] == s[center + len + 1]){
                len += 1;
            }
            f_half[center] = len * 2;
        }

        int max_len = 0;
        int max_center = 0;
        for(int i = 0; i < size; ++i){
            if(f[i] > max_len){
                max_len = f[i];
                max_center = i;
            }
            if(f_half[i] > max_len){
                max_len = f_half[i];
                max_center = i;
            }
        }

        if(max_len % 2 == 0){
            return s.substr(max_center - max_len / 2 + 1, max_len);
        }
        else{
            return s.substr(max_center - max_len / 2, max_len);
        }
    }
};