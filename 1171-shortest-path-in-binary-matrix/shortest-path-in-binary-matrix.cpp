class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q; // Queue to store distance and coordinates
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns
        
        // Check if starting cell is blocked
        if (grid[0][0] == 1)
            return -1;
        
        // Check if destination cell is blocked
        if (grid[n - 1][m - 1] == 1)
            return -1;
        
        // If there is only one cell and it is reachable
        if (n == 1 && grid[0][0] == 0)
            return 1;
        
        // Push the starting cell into the queue with distance 1
        q.push({1, {0, 0}});

        // Array to represent movements in row and column directions
        int delRow[] = {-1, 0, 1, 0, 1, -1, -1, 1};
        int delCol[] = {0, 1, 0, -1, 1, 1, -1, -1};

        // BFS traversal
        while (!q.empty()) {
            int dis = q.front().first; // Distance of current cell from the starting cell
            int row = q.front().second.first; // Row index of current cell
            int col = q.front().second.second; // Column index of current cell
            q.pop(); // Remove the current cell from the queue

            // Check all eight neighboring cells
            for (int i = 0; i < 8; i++) { // Loop through neighbors
                int newRow = row + delRow[i]; // Calculate new row index
                int newCol = col + delCol[i]; // Calculate new column index
                
                // Check if the new cell is within the grid boundaries and is unblocked
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 0) {
                    
                    // Mark the cell as visited (-1) to avoid revisiting
                    grid[newRow][newCol] = -1;
                    
                    // If the new cell is the destination, return the distance + 1
                    if (newRow == n - 1 && newCol == m - 1) {
                        return dis + 1;
                    }
                    
                    // Push the new cell into the queue with distance incremented by 1
                    q.push({dis + 1, {newRow, newCol}});
                }
            }
        }
        // If destination cell is unreachable or there is no path, return -1
        return -1;
    }
};