#define ll long long 
class Solution {

public:
    int M = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        ll src =0;
        // time is vary --> so we use the prioirty Queue..
        priority_queue< pair<ll,ll> , vector<pair<ll,ll>> ,greater<pair<ll,ll>> > pq;
        //push the things --> {dis,node}
        pq.push({0,0});
         
        //make the adjList :
        vector<pair<ll,ll>> adj[n];
        for(auto it : roads){
            ll u = it[0];
            ll v = it[1];
            ll time = it[2];
            //undirected graph
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }

        //make dist vector
        vector<ll> dist(n,LLONG_MAX);
        dist[src]=0;
        vector<ll> ways(n,0);
        ways[src]=1;

        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;

            pq.pop();

            for(auto it : adj[node]){
                ll neighNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[neighNode]){
                    dist[neighNode] = dis + wt;
                    pq.push({dis+wt , neighNode});
                    ways[neighNode] = ways[node];
                }

                else if(dis + wt  == dist[neighNode]){
                    ways[neighNode] = (ways[neighNode]+ways[node])%M;
                }
            }

        }
        return ways[n-1]%M;
    }
};