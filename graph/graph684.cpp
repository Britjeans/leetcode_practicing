class Solution {
public:
    int find(vector<int>& parent,int x){
        if(parent[x]==-1)
            return x;
        return find(parent,parent[x]);
    }
    void Union(vector<int>& parent,int x,int y){
        int xroot=find(parent,x);
        int yroot=find(parent,y);
        parent[yroot]=xroot;      
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V=(int)edges.size();
        vector<int> parent;
        for(int i=0;i<V;i++)
            parent.push_back(-1);

        for(int i=0;i<V;i++){
            int x=find(parent,edges[i][0]-1);
            int y=find(parent,edges[i][1]-1);
            if(x==y){
                return edges[i];              
            }
            Union(parent, x,y);
        }
        
    }
};
