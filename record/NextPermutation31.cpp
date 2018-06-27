class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2) return;
        int n=nums.size();
        int i=n-2,j=n-1;
        while(i>=0&&nums[i]>=nums[j]){
               i--;
               j--;
        } 
        if(i>=0){
            while(j<n-1&&nums[j]>nums[i]) j++;
            if(nums[j]<=nums[i]) j--;
            int tmp=nums[i];
            nums[i]=nums[j];
            nums[j]=tmp;
        }
        i++;
        if(i==n-1) return;
        for(int k=i;k<=(n+i-1)/2;k++){
            int tmp=nums[k];
            nums[k]=nums[n-1+i-k];
            nums[n-1+i-k]=tmp;
        }
        return;
        
        
    }
};
