//
class Solution {
public:
    bool issorted(vector<int> output){
        for(int i=0;i<output.size()-1;i++){
            if(output[i]>output[i+1]||output[i]==output[i+1]) return false;
        }       
        return true;
    }
    void backtrack(vector<vector<int>> &res,vector<int> &output, int k,int n){
        if(k<0&&n==0){
            if(issorted(output))
                res.push_back(output);
        }else{
            for(int i=1;i<=9;i++){
                output[k]=i;
                if(k==0&&n!=i) continue;
                if(i<=n&&n>0)//约束条件
                    backtrack(res,output,k-1,n-i);
            }
        }     
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;               
        vector<int> output(k,0);    
        backtrack(res,output,k-1,n);
        return res;        
    }
};
