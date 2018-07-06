//8ms 
class Solution {
public:
    static bool myCompare(int a,int b){
        if(a==0||b==0) return a>b;
        vector<int> x,y;
        bool mark=true;
        while(a!=0){x.push_back(a%10); a=a/10;}
        while(b!=0){y.push_back(b%10); b=b/10;}
        if(x.size()<y.size()){
            vector<int> tmp=x;
            x=y;
            y=tmp;
            mark=false;
        }
        int l1=(int)x.size()-1;
        int l2=(int)y.size();
        int i=0;
        while(i<=l1){
            if(x[l1-i]>y[l2-1-i%l2])  return mark?true:false;
            if(x[l1-i]<y[l2-1-i%l2]) return mark?false:true;
            i++;
        }
        for(i=l2-1;i>=0;i--){
            if(x[i]>y[i]) return mark?false:true;
            if(x[i]<y[i]) return mark?true:false;
        }
        return mark?true:false;
    }
    string largestNumber(vector<int>& nums) {
        if(nums.size()==0) return "";
        if(nums.size()==1) return to_string(nums[0]);
        sort(nums.begin(),nums.end(),myCompare);
        string res="";
        if(nums[0]==0&&nums[1]==0) return "0";
        for(int i=0;i<nums.size();i++) res+=to_string(nums[i]);
        
        return res;
    }
};
