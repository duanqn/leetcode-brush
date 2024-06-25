/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct Task{
        int column;
        int row;
        TreeNode* node;
    };

private:
    std::deque<Task> tasks;

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::map<int, std::vector<std::pair<int, int>>> data;
        tasks.emplace_back(Task{0, 0, root});
        while(!tasks.empty()){
            Task task = tasks.front();
            tasks.pop_front();

            data[task.column].push_back(std::make_pair(task.row, task.node->val));

            if(task.node->left != nullptr){
                tasks.emplace_back(Task{task.column - 1, task.row + 1, task.node->left});
            }
            if(task.node->right != nullptr){
                tasks.emplace_back(Task{task.column + 1, task.row + 1, task.node->right});
            }
        }

        vector<vector<int>> res;
        int index = 0;
        res.resize(data.size());
        for(auto it = data.begin(); it != data.end(); ++it){
            std::sort(it->second.begin(), it->second.end());
            for(auto&& pair: it->second){
                res[index].push_back(pair.second);
            }
            ++index;
        }

        return res;
    }
};