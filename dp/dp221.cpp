//none dp version solution
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int row=matrix.size();
        int col=matrix[0].size();
        int curmax=0,globalmax=0;
        for(int i=0;i<row-globalmax;++i){
            for(int j=0;j<col-globalmax;++j){
                int sum=0;
                curmax=0;
                do{
                    curmax=curmax+1;
                    if((i+curmax)>row||(j+curmax)>col) break;
                    for(int k=0;k<curmax;k++) sum+=matrix[i+curmax-1][j+k]-'0';
                    for(int k=0;k<curmax-1;k++) sum+=matrix[i+k][j+curmax-1]-'0';    
                    
                }while(sum==curmax*curmax);
                globalmax=max(globalmax,curmax-1);
            }
        }
        return globalmax*globalmax;
        
    }
};
//dp version
