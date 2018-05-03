//slow version
class Solution {
public:
int findCircleNum(vector<vector<int>>& M) {
    queue<int> friends,q,temp;
    int count=0;
    vector<bool> visited;
    int len=(int)M.size();
    for(int i=0;i<len;i++) {
        visited.push_back(false);
        q.push(i);
    }
    int c=0;
    while(!q.empty()){
        c++;
        int f=q.front();
        q.pop();
        friends.push(f);
        while(!friends.empty()){
            int top=friends.front();
            friends.pop();
            visited[top]=true;
            for(int i=0;i<len;i++){
                if(visited[i]==false&&i!=top){
                    if(M[top][i]==1) friends.push(i);
                }
            }
        }
        while(!q.empty()){
            if(!visited[q.front()]) temp.push(q.front());
            q.pop();
        }
        q=temp;
        while(!temp.empty())temp.pop();
        count++;
    }
    return count;
}

    
};
