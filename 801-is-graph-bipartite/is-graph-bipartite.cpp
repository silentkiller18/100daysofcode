class Solution {
public:
    bool bfs(int i, vector<vector<int>>&graph, vector<int>&color){
        queue<int>q;
        q.push(i);
        color[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto ngr:graph[node]){
                if(color[ngr]==-1){
                    q.push(ngr);
                    if(color[node]==1){
                        color[ngr]=2;
                    }
                    else{
                        color[ngr]=1;
                    }
                }
                else if(color[node]==1 && color[ngr]==1){
                    return false;
                }
                else if(color[node]==2 && color[ngr]==2){
                    return false;
                }
            }    
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && bfs(i, graph, color)==false) return false;
        }
        return true;
    }
};