class Solution
{
public:
    const int N = 1000;
    vector<pair<int, int>> res;
    int Dijkstra(vector<pair<int, int>> graph[], int src, int dst, int k)
    {
        // int jn = 0;
        vector<bool> vist(1000, false);
        vector<int> dist(1000, 1e9);
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, src}});
        dist[src] = 0;
        while (!pq.empty())
        {
            // auto ii = pq.top();
            auto ii = pq.front();
            pq.pop();
            int jn = ii.first;
            int dist_v = ii.second.first;
            int node = ii.second.second;
            if(node == dst && jn == k + 1)
            {
                // std::cout << 'cnt' << endl;
                res.push_back({jn, dist_v});
                break;
            }
            // if(vist[node])
            // {
            //     continue;
            // }
            if(jn > k + 1)
            {
                continue;
            }
            // for(int i = 0; i < 5; i++)
            // {
            //     std::cout << i << ": ";
            //     for(auto ii : graph[i])
            //     {
            //         std::cout << ii.first << " " << ii.second << endl;
            //     }
            //     std::cout << "\n";
            // }
            // std::cout << endl;
            // std::cout << node << " " << dist_v << endl;
            // vist[node] = true;
            for(auto ii : graph[node])
            {
                // std::cout << ii.second.first << " " << ii.second.second << endl;
                int child_v = ii.first;
                int wt = ii.second;
                if((dist_v + wt < dist[child_v]) && jn < k + 1)
                {
                    dist[child_v] = dist_v + wt;
                    pq.push({jn + 1, {dist[child_v], child_v}});
                    // jn++;
                }
            }
        }
        for(auto ii : res)
        {
            std::cout << ii.first << " " << ii.second << endl;
        }
        if(dist[dst] == 1e9)
        {
            return -1;
        }
        return dist[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // int n = flights.size();
        int kk = flights.size();
        vector<pair<int, int>> graph[N];
        for (int i = 0; i < kk; i++)
        {
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        return Dijkstra(graph, src, dst, k);
    }
};