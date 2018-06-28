//6ms 
class Solution {
public:
    int partition(int n){
        int res=1;
        for(int i=1;i<=n;i++) res*=i;
        return res;
    }
    string getPermutation(int n, int k) {
        
        string res="";
        string dict="";
        for(int i=0;i<n;i++) dict+=(i+1+'0');
        while(n>0){
            int val=partition(n-1);
            int front=(k-1)/val;
            res=res+dict[front];
            dict.erase(front,1);
            k-=front*val;
            n=n-1;
        }
        return res;
    }
};
