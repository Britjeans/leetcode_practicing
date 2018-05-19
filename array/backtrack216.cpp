class Solution {
public:

    void backtrack(vector<vector<int>> &res,vector<int> &output, int k,int n,int max){
        if(k<0&&n==0){
           res.push_back(output);
        }else{
            for(int i=1;i<max;i++){
                output[k]=i;
                if(k==0&&n!=i) continue;
                if(i<=n&&n>0)//约束条件
                    backtrack(res,output,k-1,n-i,i);
            }
        }     
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;               
        vector<int> output(k,0);    
        backtrack(res,output,k-1,n,10);
        return res;        
    }
};
