class DisjointSet{
    vector<int>rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }

    int findUPar(int u){
        if(parent[u]==u)return u;
        return parent[u]=findUPar(parent[u]);
    }

    void unionByRank(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<ulp_v){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>ulp_v){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

};

class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n=details.size();
        DisjointSet ds(n);
        unordered_map<string,int>mapMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string mail=details[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()){
                    mapMailNode[mail]=i;
                }
                else{
                    ds.unionByRank(i,mapMailNode[mail]);
                }
            }
        }
        vector<string>mergeMail[n];
        for(auto it:mapMailNode){
            string mail=it.first;
            int node=ds.findUPar(it.second);
            mergeMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0)continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(details[i][0]);
            for(auto it:mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};