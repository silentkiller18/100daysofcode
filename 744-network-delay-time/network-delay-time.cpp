class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create an adjacency list to represent the graph
        vector<pair<int,int>> adj[n + 1];
        
        // Construct the adjacency list from the given 'times' vector
        for(auto it : times){
            int u = it[0]; // source node
            int v = it[1]; // destination node
            int wt = it[2]; // weight or time taken to travel from u to v
            adj[u].push_back({v, wt});
        }

        // Create a priority queue for Dijkstra's algorithm
        // Pair (time, node) is used where 'time' represents time taken to reach 'node'
        // and 'node' represents the node number
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Push the source node 'k' with time 0 to the priority queue
        pq.push({0 , k});

        // Initialize an array to keep track of minimum distances from the source node 'k' to all other nodes
        vector<int> dist(n+1 , INT_MAX);
        dist[k] = 0; // Distance from 'k' to itself is 0

        // Dijkstra's algorithm
        while(!pq.empty()){
            int time = pq.top().first; // Time taken to reach the current node
            int node = pq.top().second; // Current node
            pq.pop();

            // Iterate over all adjacent nodes of the current node
            for(auto it : adj[node]){
                int neighbourNode = it.first; // Neighbouring node
                int wt = it.second; // Weight of the edge between 'node' and 'neighbourNode'

                // If the total time taken to reach 'neighbourNode' through 'node' is less than
                // the current recorded distance to 'neighbourNode', update the distance
                if(time + wt < dist[neighbourNode]){
                    dist[neighbourNode] = time + wt;
                    // Push the updated distance and the neighbouring node to the priority queue
                    pq.push({dist[neighbourNode] , neighbourNode });
                }
            }  
        }

        // Find the maximum distance in 'dist' array
        int mx = *max_element(dist.begin()+1 , dist.end() );

        // If mx is still INT_MAX, it means some nodes are not reachable from the source 'k',
        // so return -1, otherwise return the maximum distance
        return mx == INT_MAX ? -1 : mx;
    }
};