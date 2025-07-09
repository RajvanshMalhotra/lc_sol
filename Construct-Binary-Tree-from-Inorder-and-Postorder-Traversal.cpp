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
    map<int,int>mp;
    TreeNode* helper(int is,int ie,int ps,int pe,vector<int>&inorder,vector<int>&postorder){
        if(is>ie || ps>pe) return nullptr;
        TreeNode* root=new TreeNode(postorder[pe]);
        int i=mp[postorder[pe]];
        int len=i-is;
        root->left=helper(is,i-1,ps,ps+len-1,inorder,postorder);
        root->right=helper(i+1,ie,ps+len,pe-1,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n1=inorder.size();
        for(int i = 0; i < n1; i++) {
            mp[inorder[i]] = i;
        }

        return helper(0,n1-1,0,n1-1,inorder,postorder);
        
    }
};