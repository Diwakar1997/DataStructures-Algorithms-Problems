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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            queue<TreeNode*> q2;
            double sum = 0.0;
            int count = 0;
            while(!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                count++;
                if(node->left){
                    q2.push(node->left);
                }
                if(node->right) {
                    q2.push(node->right);
                }
            }
            double mean = sum/count;
            result.push_back(mean);
            q.swap(q2);
        }
        
        return result;
    }
};