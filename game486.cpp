//slow version
class Solution {
public:
bool Predict(vector<int> pick,vector<int>& player,vector<int> nums,int rank){
    if(pick[1]-pick[0]==1){
        if(rank==1&&player[1]+max(nums[pick[1]],nums[pick[0]])>player[0]+min(nums[pick[1]],nums[pick[0]]))
            return false;
        else if(rank==0&&player[0]+max(nums[pick[1]],nums[pick[0]])<player[1]+min(nums[pick[1]],nums[pick[0]])) return false;
        else return true;
    }
    for(int i=0;i<=1;++i){
        vector<int> tmp=pick;
        tmp[i]=pick[i]+1-i*2;
        player[rank]+=nums[pick[i]];
        if(rank==1){ if(!Predict(tmp,player,nums,!rank)) { player[rank]-=nums[pick[i]];return false;}}
        else {if(Predict(tmp,player,nums,!rank)) { player[rank]-=nums[pick[i]];return true;}}
           
        player[rank]-=nums[pick[i]];
    }
    if(rank==1) return true;
    else return false;
}
bool PredictTheWinner(vector<int>& nums) {
    if(nums.size()==1) return true;
    vector<int>pick(2,0);
    vector<int>player(2,0);
    pick[1]=(int)nums.size()-1;
    return Predict(pick,player,nums,0);
}

};
