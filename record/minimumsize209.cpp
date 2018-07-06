//8ms
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        int globalmin=INT_MAX;
        int begin=0,end=0,sum=0;
        bool mark=false;
        while(end<=nums.size()&&begin<=end){
            while(sum<s&&end<nums.size()){sum+=nums[end];end++;}
            if(sum>=s){globalmin=min(globalmin,end-begin);mark=true;}
            sum-=nums[begin];
            begin++;
        }
        return mark?globalmin:0;
    }
};
