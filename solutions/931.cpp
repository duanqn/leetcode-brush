#include <limits>
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> f(matrix);
        int n = static_cast<int>(matrix.size());

        for(int i = 0; i < n; ++i){
            f[0][i] = matrix[0][i];
        }

        for(int i = 1; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int val = f[i-1][j];
                if(j - 1 >= 0){
                    val = std::min(val, f[i-1][j-1]);
                }
                if(j + 1 < n)){
                    val = std::min(val, f[i-1][j+1]);
                }
                val += matrix[i][j];
                f[i][j] = val;
            }
        }

        int res = std::numeric_limits<int>::max();
        for(int i = 0; i < n; ++i){
            res = std::min(res, f[n-1][i]);
        }

        return res;
    }
};