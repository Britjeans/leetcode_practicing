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
    void Construct(TreeNode* root,int &count,vector<int> begin,vector<int> end,vector<int>& preorder, vector<int>& inorder){
            int n=preorder.size();
            int root2;
            if(begin[0]==end[0]) return;
            
            for(int i=begin[1];i<=end[1];i++){
                if(inorder[i]==preorder[begin[0]]){
                    root2=i;
                    break;
                }
            }
            //after obtained root in inorder set, we can split right tree and left tree
            if(root2>begin[1]){
                root->left=new TreeNode(preorder[begin[0]+1]);
                
                vector<int> tmp_b(2,0),tmp_e(2,0);
                tmp_b[0]=begin[0]+1;
                tmp_e[0]=root2-1-begin[1]+begin[0]+1;
                tmp_b[1]=begin[1];
                tmp_e[1]=root2-1;
                Construct(root->left,count,tmp_b,tmp_e,preorder,inorder);
            }       
            if(root2<end[1]){
                root->right=new TreeNode(preorder[root2+1-begin[1]+begin[0]]);
                
                begin[0]=root2-begin[1]+begin[0]+1;
                end[0]=end[1]-root2-1+begin[0];
                begin[1]=root2+1;
                Construct(root->right,count,begin,end,preorder,inorder);
            }
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        
        int n=preorder.size();
        if(n==0) return NULL;
        int count=0;
        //initialize all variables
        vector<int>begin(2,0),end(2,n-1);
        TreeNode* root=new TreeNode(preorder[begin[0]]);
        if(root==NULL) return root;
        Construct(root,count,begin,end,preorder,inorder);

        return root;
            
    }
};
