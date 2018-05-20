//time limited exceed
/*solution 1*/
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
/*solution 2*/
class Solution {
public:
    int path(int m,int n){
        if(m==0||n==0)
            return 1;
        return path(m-1,n)+path(m,n-1);
    }    
    int uniquePaths(int m, int n) {        
        return path(m-1,n-1);
    }
};
//iteration solution
class Solution {
public:

    int uniquePaths(int m, int n) { 
        //vector<vector<int> > path(m, vector<int> (n, 1));
        if(m>n) return uniquePaths(n,m);
        vector<int> cur(m,1);
        for (int i = 1; i < n; i++){
             for (int j =1; j < m; j++){
                //path[i][j] = path[i - 1][j] + path[i][j - 1];
                cur[j]=cur[j]+cur[j-1];
            }
        }
        return cur[m-1];//path[m - 1][n - 1];
    }
};
