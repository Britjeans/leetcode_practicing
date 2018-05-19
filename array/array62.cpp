//time limited exceed
class Solution {
public:
    void backtrack(int & count,int r,int d){
        if(r<=0&&d<=0){
            count+=1;
        }
        else{
            for(int i=0;i<=1;i++){
                //约束条件
                if(i==0&&r>0)
                    backtrack(count,r-1,d);
                else if(i==1&& d>0)
                    backtrack(count,r,d-1);
            }
        }
        
    }
    int uniquePaths(int m, int n) {
        int count=0;
        backtrack(count,m-1,n-1);
        return count;
    }
};
