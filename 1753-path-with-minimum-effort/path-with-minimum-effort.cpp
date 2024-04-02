class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        //Here distance between two cells is different (vary) not fixed so that's why we use Priority Queue here 
        priority_queue < pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        //now push the source --> topLeft in the priority Queue
        pq.push({0, {0,0}});

        // step 2 : find n & m
        int n = grid.size();
        int m = grid[0].size();

        //step 3 : make a distance array of n x m  --> INT_MAX at all places 
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));

        //step 4 : for 4 direction :
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        //run a loop while until pq is NOT empty
        while(!pq.empty()){
            //extract the element 
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            //popout the element
            pq.pop();

            //if we reach at the destination BottomRight means we got it :
            if(row == n-1 && col == m-1) return dis;


            // go into 4 direction 
            for(int i=0;i<4;i++){
                //derive newrow and new col 
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                //make sure that it will be in the grid 
                if(nrow>=0 && ncol>=0 && ncol<m && nrow<n){
                    //acc to question : maximum absolute difference in heights between two consecutive cells of the route.
                    int x = max(dis , abs(grid[nrow][ncol]-grid[row][col]) );
                    //as we get maximum effort upto current cell check wheter this is small value which stored in the distance 2-D array
                    if(x<dist[nrow][ncol]){
                        //if value is small then update with small value and push into priority Queue
                        dist[nrow][ncol]=x;
                        pq.push({x,{nrow,ncol}});
                    }
                }

            }

        }
        // if we can't able to reach the destination return 0;
        return 0;
    }
};