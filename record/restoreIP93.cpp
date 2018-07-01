class Solution {
public:
    int string2num(string a){
        int sum=0;
        for(int i=0;i<3;i++) sum=sum*10+a[i]-'0';
        return sum;
    }
    void backtrack(vector<string>& res,string tmp,int left,int cur,string s){
        int n=s.length();
        if(cur==4){
            //检查目前的数字是否符合要求
            if(left==3&&string2num(s.substr(n-left,3))>255||(left>1&&s[n-left]=='0')) return;
            tmp+=s.substr(n-left,left);
            res.push_back(tmp);
            return;
        }
        //找到前缀
        for(int i=1;i<=3;i++){
            if((left-i)>(4-cur)*3||(left-i)<=0||(i==3&&string2num(s.substr(n-left,i))>255)||(i>1&&s[n-left]=='0')) continue;
            tmp+=s.substr(n-left,i);
            tmp+='.';
            backtrack(res,tmp,left-i,cur+1,s);
            int size=tmp.size();
            tmp.erase(size-(i+1),i+1);
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string tmp="";
        if(s.length()>16||s.length()<4) return res;
        backtrack(res,tmp,s.length(),1,s);
        return res;
    }
};
