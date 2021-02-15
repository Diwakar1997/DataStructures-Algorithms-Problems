//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int K;
    vector<int> result;
    
    void insert(int dist, TreeNode *root) {
        if(root == NULL)
            return;
        if(dist == K) {
            result.push_back(root->val);
            return;
        }
        if(dist > K) {
            return;
        }
        insert(dist+1, root->left);
        insert(dist+1, root->right);
    }
    
    int dfs(TreeNode* root, TreeNode* target) {
        if(root == NULL)
            return -1;
        if(root == target) {
            insert(0, root);
            return 1;
        }
        else {
            int left = dfs(root->left, target);
            int right = dfs(root->right, target);
            if(left != -1) {
                if(left == K) {
                    insert(K, root);
                }
                else
                    insert(left + 1, root->right);
                return left+1;
            }
           else if(right != -1) {
                if(right == K) {
                    insert(K, root);
                }
                else {
                    insert(right + 1, root->left);
                }
               return right+1;
            }
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(target == NULL)
            return {};
        K = k;
        dfs(root, target);
        
        return result;
    }
};