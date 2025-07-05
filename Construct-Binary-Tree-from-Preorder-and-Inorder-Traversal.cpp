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

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int ps,int pe,int is,int ie){
        if(ps>pe || is>ie) return nullptr;
        int roote=preorder[ps];
        TreeNode *root=new TreeNode(roote);
        int i=is;
        int nc=0;
        while(inorder[i]!=roote){
            nc++;
            i++;
        }
        int lst_is=is,lst_ie=i-1;
        int rst_is=i+1,rst_ie=ie;
        int lst_ps=ps+1,lst_pe=ps+nc;
        int rst_ps=ps+nc+1,rst_pe=pe;
        root->left = helper(preorder, inorder, lst_ps, lst_pe, lst_is, lst_ie);

        root->right=helper(preorder,inorder,rst_ps,rst_pe,rst_is,rst_ie);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};