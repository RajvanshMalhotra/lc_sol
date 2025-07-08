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
    int count=0;
    pair<int,int> helper(TreeNode *root){
        if(!root)return {0,0};
        pair<int,int> left_st=helper(root->left);
        pair<int,int> right_st=helper(root->right);
        int sum=left_st.first+right_st.first+root->val;
        int nodes=right_st.second+left_st.second+1;
        if(sum/nodes==root->val) count++;
        return {sum,nodes};

    }

    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
    }
};