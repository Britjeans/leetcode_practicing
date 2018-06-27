//9ms
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return -1;
        if(n==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
        int front=nums[0],back=nums[n-1];
        if(front>back){
            if(target==back) return n-1;
            if(target==front) return 0;
            if(target<front&&target>back) return -1; 
           if(target>front){
               int lo=0,hi=n-1;
               while(lo<hi){
                   int mi=(lo+hi)/2;
                   if(nums[mi]>target||nums[mi]<front)  hi=mi-1;
                   else if(nums[mi]>=front&&nums[mi]<target) lo=mi+1;
                   else return mi;    
               }
               return target==nums[lo]?lo:-1;   
           }
           if (target<back){
               int lo=0,hi=n-1;
               while(lo<hi){
                   int mi=(lo+hi)/2;
                   if(nums[mi]<=back&&nums[mi]>target)  hi=mi-1;
                   else if(nums[mi]<target||nums[mi]>back) lo=mi+1;
                   else return mi;    
               }
               return target==nums[lo]?lo:-1;   
           }  
        }
        else{
            int lo=0,hi=n-1;
            while(lo<hi){
                int mi=(lo+hi)/2;
                if(nums[mi]>target) hi=mi-1;
                else if(nums[mi]<target) lo=mi+1;
                else return mi;
            }
            return target==nums[lo]?lo:-1;
            
        }
        
    }
};
