//dp solution
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        if (p.empty()) return s.empty();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        //initialize dp
        dp[0][0]=true;
        for(int j=0;j<n;j++){
            if(p[j]=='*') dp[0][j+1]=dp[0][j-1];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(p[j]==s[i]||p[j]=='.') dp[i+1][j+1]=dp[i][j];
                else if(p[j]=='*'){
                    if(p[j-1]!=s[i]&&p[j-1]!='.') dp[i+1][j+1]= dp[i+1][j-1];
                    else  dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
                }
            }
        }
        return dp[m][n];
    }
