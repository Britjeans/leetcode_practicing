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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        TreeNode* node;
        int levelNumber=1,count=1,levelCount=0,level=1;
        while(!q.empty()){
            node=q.front();
            q.pop();               
            temp.push_back(node->val);
            levelCount++;
            if(node->right!=NULL) {q.push(node->right);++count;} 
            if(node->left!=NULL) {q.push(node->left); ++count;}
        
            if(levelCount==levelNumber){
                levelNumber=count;               
                ++level;
                if(level%2==0){
                    int n=temp.size();
                    for(int i=0;i<n/2;i++){
                        int t=temp[n-1-i];
                        temp[n-1-i]=temp[i];
                        temp[i]=t;
                    }
                }
                res.push_back(temp);
                temp.clear();
            }         
        }
       // res.push_back(temp);
        return res;
    }
};
