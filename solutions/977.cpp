class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> res;
        res.reserve(nums.size());

        if(nums.empty()){
            return res;
        }

        int index = 0;
        int left = 0;
        int right = 0;
        int size = static_cast<int>(nums.size());
        for(size_t i = 0; i < size; ++i){
            if(nums[i] == 0){
                index = i;
                break;
            }
            if(nums[i] > 0){
                if(i == 0){
                    index = i;
                }
                else if(std::abs(nums[i]) > std::abs(nums[i-1])){
                    index = i - 1;
                }
                else{
                    index = i;
                }
                break;
            }
            index = i;
        }

        res.push_back(nums[index] * nums[index]);
        left = index - 1;
        right = index + 1;

        while(left >= 0 || right < size){
            if(left >= 0 && right < size){
                if(std::abs(nums[left]) < std::abs(nums[right])){
                    res.push_back(nums[left] * nums[left]);
                    --left;
                }
                else{
                    res.push_back(nums[right] * nums[right]);
                    ++right;
                }
            }
            else if(left >= 0){
                res.push_back(nums[left] * nums[left]);
                --left;
            }
            else{
                res.push_back(nums[right] * nums[right]);
                ++right;
            }
        }

        return res;
    }
};