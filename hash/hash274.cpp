//
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0) return 0;
        int min=INT_MAX,max=0,max_h=citations.size();
        bool mark=false;
        for(int i=0;i<citations.size();++i){
            if(citations[i]>max) max=citations[i];
            if(citations[i]<min) min=citations[i];          
        }
        for(int h=min;h<=max;++h){
            int count=0,self=0;
            for(int i=0;i<citations.size();++i){
                if(citations[i]!=h)
                    count+=(citations[i]+1)>(h+1);
                else
                    self+=1;
            }
            if((count+self)>=h&&count<=h){max_h=h;mark=true;} 
            if(mark&&max_h!=h) return max_h;
        }
        return max_h;
    }
};
//still slow
class Solution {
public:
    int hIndex(vector<int>& citations) {
        priority_queue<int> q;
        for(int i=0;i<citations.size();++i){
            q.push(citations[i]);
        }
        int h=0;
        while(!q.empty()){
            int h_max=q.top();
            if(h_max<=h) return h;
            q.pop();
            ++h;            
        }
        return citations.size();
    }
};
