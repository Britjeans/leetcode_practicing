class Solution {
public:

    bool BFS(vector<bool>& visited,stack<int>& s,vector<vector<int>>& graph,vector<bool>& set){
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()!=0){
                s.push(i);break;
            }
        }
        while(!s.empty()){  
            while(!s.empty()){
                int t=s.top();
                s.pop();
                visited[t]=true;
                for(int i=0;i<graph[t].size();i++){
                    if(visited[graph[t][i]]==true){
                        if(set[graph[t][i]]==set[t]) return false;
                    }else{
                        visited[graph[t][i]]=true;
                        s.push(graph[t][i]);
                        set[graph[t][i]]=!set[t];
                    }                       
                 }
             }
             for(int i=0;i<graph.size();i++){
                if(visited[i]==false&&graph[i].size()!=0){
                    s.push(i); break;
                }
            }    
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool>visited;
        stack<int> s;
        vector<bool> set;//
        for(int i=0;i<graph.size();i++){
            visited.push_back(false);
            set.push_back(false);
        }
        bool res=BFS(visited,s,graph,set);
        
        return res;
    }
};
