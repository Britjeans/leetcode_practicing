//recursion version time limited exceeded
class Solution {
public:
    int uniqueBST(int begin, int end){
        if(begin>end) return 1;
        int res=0;
        //set a number as pivot
        for(int i=begin;i<=end;i++){
             res+= uniqueBST(begin,i-1)*uniqueBST(i+1,end);
        }
        return res;
    }
        
    int numTrees(int n) {
        int res=0;
        res=uniqueBST(1,n);
        return res;
    }
};
//iterative version

int numTrees2(int n){
    
    vector<vector<int>> uniqueBST(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        uniqueBST[i][i]=1;
    }
    for(int j=1;j<n;j++){
        for(int i=0;i<n;i++){
            if(i+j>=n) break;
            for(int k=i;k<=i+j;k++){
                if(k-1<i){
                    uniqueBST[i][i+j]+=uniqueBST[k+1][i+j];
                    continue;
                }
                if(k+1>i+j){
                    uniqueBST[i][i+j]+=uniqueBST[i][k-1];
                    continue;
                }
                uniqueBST[i][i+j]+=uniqueBST[i][k-1]*uniqueBST[k+1][i+j];
            }

        }
    }
    
    return uniqueBST[0][n-1];
}
