//slow and should be modified
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen=0;
        string res=s.substr(0,1);   
        for(int i=0;floor(i/2)< s.length()-maxlen;++i){
            int curlen=0;
            while(s[floor(1.0*i/2+curlen)]==s[ceil(1.0*i/2-curlen)]){
                ++curlen;
                if(floor(1.0*i/2+curlen)>=s.length()||ceil(1.0*i/2-curlen)<0) break;
            } 
            int k=(i+1)%2;
            if(curlen-1>=maxlen) 
                if(res.length()<=2*(curlen-1)+k)
                    res=s.substr(ceil(1.0*i/2-curlen)+1,2*(curlen-1)+k);      
            maxlen=max(maxlen,curlen-1);  
        }
        return res;
    }
};
