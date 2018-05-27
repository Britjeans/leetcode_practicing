//complex version
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
    void Construct(TreeNode* root,vector<int> begin,vector<int> end,vector<int>& inorder, vector<int>& postorder){
            //the root is at the ned of postorder set
            if(begin[1]==end[1]||begin[0]==end[0]) return;
            int root2;
            for(int i=begin[0];i<=end[0];++i){                
                if(postorder[end[1]]==inorder[i]){
                    root2=i;break;
                }
            }
            if(root2>begin[0]){
                vector<int> tmp_b(2,0),tmp_e(2,0);
                tmp_b[0]=begin[0];
                tmp_e[0]=root2-1;
                tmp_b[1]=begin[1];
                tmp_e[1]=begin[1]+root2-begin[0]-1;            
                root->left=new TreeNode(postorder[tmp_e[1]]);
                Construct(root->left,tmp_b,tmp_e,inorder,postorder);
                    
            }
            if(root2<end[0]){
                root->right=new TreeNode(postorder[end[1]-1]);
                begin[0]=root2+1;
                end[1]=end[1]-1;
                begin[1]=end[1]-(end[0]-begin[0]);
                Construct(root->right,begin,end,inorder,postorder);
                
            }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        if(n==0) return NULL;
        TreeNode* root=new TreeNode(postorder[n-1]);
        vector<int> begin(2,0),end(2,n-1);
        Construct(root,begin,end,inorder,postorder);
        return root;
    }
};
