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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        if(root==NULL) return res;
        TreeNode* node;
        stack<TreeNode*> s;
        stack<TreeNode*> storage;
        s.push(root);
        bool mark=false;
        while(!s.empty()){
            node=s.top();            
            storage.push(s.top()); 
            temp.push_back(node->val);
            s.pop();
            if(node->right!=NULL){
                s.push(node->right);
                node->right->val+=node->val;
            }
            if(node->left!=NULL){
                s.push(node->left);
                node->left->val+=node->val;
            }
            if(node->left==NULL&&node->right==NULL){
                
                if(node->val==sum) {
                    for(int i=temp.size()-1;i>0;i--){
                        temp[i]=temp[i]-temp[i-1];
                    }
                    res.push_back(temp);
                    storage.pop();
                    temp.pop_back();
                    while(!storage.empty()&&!s.empty()&&storage.top()->right!=s.top()){
                        storage.pop();
                        temp.pop_back();
                    }
                }
                else{
                    storage.pop();
                    temp.pop_back();
                    while(!storage.empty()&&!s.empty()&&storage.top()->right!=s.top()){
                        storage.pop();
                        temp.pop_back();
                    }
                }
                    
                
            }
        }
        return res;
    }
};
