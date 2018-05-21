//recursion version time limited exceeded
class Solution {
public:
    int minPath(vector<vector<int>>& grid, int d, int r) {
	    int sum = 0;
	    if (d == 0) {
    		for (int i = 0; i <= r; i++) sum += grid[0][i];
	    	    return sum;
    	}
    	else if (r == 0) {
	    	for (int i = 0; i <= d; i++) sum += grid[i][0];
	        	return sum;
	    }
	    int res = min(minPath(grid,d - 1, r), minPath(grid,d, r - 1)) + grid[d][r];
    	return res;
    }

    int minPathSum(vector<vector<int>>& grid) {
	    int res;
	    res = minPath(grid, grid.size() - 1, grid[0].size() - 1);
	    return res;
    }
};
//iterative version acceppted solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
	    int res,sum=0;
	    int m=grid.size();
	    int n=grid[0].size();
	    vector<vector<int>> dist(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
        	sum+=grid[0][i];
        	dist[0][i]=sum;
        }
        sum=0;
        for(int i=0;i<m;i++){
        	sum+=grid[i][0];
        	dist[i][0]=sum;
        }
        
	    for(int i=1;i<m;i++){
	    	for(int j=1;j<n;j++){
	    		dist[i][j]=min(dist[i-1][j],dist[i][j-1])+grid[i][j];
	    	}
	    }	

	    return dist[m-1][n-1];
    }
};
