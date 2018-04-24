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
    int maximum(vector<int>nums){
        int index=0,max=0;
         //find the maximum
        for (int i=0;i<nums.size();i++){
            int temp=nums[i];
            if(temp>max){max=temp;index=i;}
        }
        return index;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())return NULL;
        
        TreeNode* root=new TreeNode(0) ;
        int index=maximum(nums);
        vector<int>left,right;
        for (int i=0;i<nums.size();i++){
            if(i<index)left.push_back(nums[i]);
            if(i>index) right.push_back(nums[i]);
            if(i==index) root->val=nums[i];
        }
        
        root->right=constructMaximumBinaryTree(right);
        root->left=constructMaximumBinaryTree(left);
        
        
        
        return root;
            
    }
};
