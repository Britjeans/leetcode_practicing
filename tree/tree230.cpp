//slow version 


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
    void goAlongLeftBranch(stack<TreeNode*>& s,TreeNode* node){
        while(node!=NULL){
            s.push(node);
            node=node->left;
        }
    }    
    int kthSmallest(TreeNode* root, int k) {
        stack <TreeNode*> s;
        int i=1;
        TreeNode* node=root;
        bool mark=true;
        while(true){
            if(mark) goAlongLeftBranch(s,node);
            if(s.empty())break;
            node=s.top();
            if(i==k)
            {
                return node->val;
            }
            else{
                if(node->right!=NULL){
                    node=node->right;
                    mark=true;
                }
                else{
                    mark=false;
                }
            }
            s.pop();
            i++;
        }
        return NULL;
    }
};

