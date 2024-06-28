#include <string>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<pair<int, int>> f;
        int count = static_cast<int>(words.size());
        if(count == 0){
            return {};
        }

        f.resize(count);
        f[0] = {1, -1};

        auto canAppend = [&](int prev, int next) -> bool {
            if(groups[prev] == groups[next]){
                return false;
            }
            if(words[prev].size() != words[next].size()){
                return false;
            }
            int diff = 0;
            for(size_t i = 0; i < words[prev].size() && diff < 2; i++){
                if(words[prev][i] != words[next][i]){
                    diff++;
                }
            }
            return diff == 1;
        };

        for(int i = 1; i < count; i++){
            f[i] = {1, -1};
            for(int j = 0; j < i; j++){
                if(canAppend(j, i)){
                    if(f[j].first + 1 > f[i].first){
                        f[i] = {f[j].first + 1, j};
                    }
                }
            }
        }

        int max = -1;
        int maxIndex = -1;
        for(int i = 0; i < count; i++){
            if(f[i].first > max){
                max = f[i].first;
                maxIndex = i;
            }
        }

        vector<string> result;
        while(maxIndex != -1){
            result.push_back(words[maxIndex]);
            maxIndex = f[maxIndex].second;
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};