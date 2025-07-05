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
    pair<int,bool>helper(TreeNode *root){
        if(!root) return{0,true};
        pair<int,bool>lp=helper(root->left);
        pair<int,bool>rp=helper(root->right);
        int diff=abs(lp.first-rp.first);
        int height=1+max(lp.first,rp.first);
        if(diff>1)return {height,false};
        return {height,lp.second && rp.second};

    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool>ans=helper(root);
        return ans.second;
        
    }
};