class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0) return 0;
        int k=-1;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=0;i<n;++i)if(obstacleGrid[m-1][i]) {k=i;}       
        for(int i=0;i<=k;++i)dp[m-1][i]=0;
        k=-1;
        for(int i=0;i<m;++i)if(obstacleGrid[i][n-1]) {k=i;}
        for(int i=0;i<=k;++i)dp[i][n-1]=0;
                            
        
        for(int i=m-2;i>=0;--i){
            for(int j=n-2;j>=0;--j){    
                if(obstacleGrid[i][j]) dp[i][j]=0;
                else dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];   
    }
};
