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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==NULL)return v;
        queue<TreeNode*> t;
        TreeNode *node=NULL;
        t.push(root);
        int level=1,visited=0,total=1;
        while(!t.empty()){
            node=t.front();
            if(node==NULL) return v;
            visited++;
            t.pop();
            if(node->left!=NULL) {t.push(node->left); total++;}
            if(node->right!=NULL) {t.push(node->right);total++;}   
            if(visited==level)  {
                level=total;
                v.push_back(node->val);        
            } 
        }
        
        
        return v;
    }
};
