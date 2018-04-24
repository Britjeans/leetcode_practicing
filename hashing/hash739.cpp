/*stupid version*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> code,warm;
        queue<int> pos;
        bool comp=false;
        int end=temperatures.size();
          
        for(int i=0;i<end-1;i++){
            int temp=temperatures[i+1]-temperatures[i];
            if(temp>0){
                comp=true;
                warm.push_back(1);;
                pos.push(i);
            }
            else{warm.push_back(0);}
            code.push_back(temp);
        }
        warm.push_back(0);
        if(!comp) return warm;
   
        int temp=0;
        while(!pos.empty()) {  
            int sum=0,count=1;
            int index=pos.front();
            sum+=code[index];
            for(int j=index-1;j>=0;j--){  
                sum+=code[j];
                if(sum<=0) break;
                ++count;
                if(warm[j]==0){warm[j]= count;}
                                
            }
            temp=index;
            pos.pop();              
        }
        
        return warm;
        
    }
};


/*stack version*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> index;
        vector<int> warm(temperatures.size(),0);
        index.push(0);
        for(int i=1;i<temperatures.size();i++){   
            while(!index.empty()&&temperatures[i]>temperatures[index.top()]){              
                    warm[index.top()]=i-index.top();
                    index.pop();
            }
            index.push(i);
        }
        
        return warm;
        
    }
};
