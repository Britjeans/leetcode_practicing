//slow version
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.length()<10) return res;
        unordered_map<int,int> m,c;
       // m[0]=0;
        m['C'-'A']=1;
        m['G'-'A']=2;
        m['T'-'A']=3;
        
        for(int i=0;i<s.length()-9;++i){
            int v=0;
            for(int j=0;j<10;j++){
                v<<=2;
                v|=m[s[i+j]-'A'];
            }
            if(c.find(v) == c.end()) c[v]=1;
            else {
                if(c[v]==1){
                    c[v]+=1;
                    res.push_back(s.substr(i,10));
                }
            }
        }
        return res;
        
    }
};
