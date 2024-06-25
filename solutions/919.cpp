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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        nodes.clear();
        std::deque<TreeNode*> toVisit;
        toVisit.push_back(root);
        while(!toVisit.empty()){
            TreeNode* current = toVisit.front();
            toVisit.pop_front();

            nodes.push_back(current);
            if(current->left != nullptr){
                toVisit.push_back(current->left);
            }
            if(current->right != nullptr){
                toVisit.push_back(current->right);
            }
        }
    }
    
    int insert(int val) {
        int index = static_cast<int>(nodes.size());
        nodes.push_back(new TreeNode(val));
        int parentIndex = (index - 1) / 2;
        if(index % 2 == 0){
            nodes[parentIndex]->right = nodes[index];
        }
        else{
            nodes[parentIndex]->left = nodes[index];
        }

        return nodes[parentIndex]->val;
    }
    
    TreeNode* get_root() {
        return nodes[0];
    }

private:
    std::vector<TreeNode*> nodes;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */