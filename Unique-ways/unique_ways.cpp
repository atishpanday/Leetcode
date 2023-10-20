// There is a robot on an m x n grid. The robot is initially located at the top-left
// corner (i.e., grid[0][0]). The robot tries to move to the bottom-right 
// corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at 
// any point in time.

// Given the two integers m and n, return the number of possible unique paths that 
// the robot can take to reach the bottom-right corner.

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev_num_ways(n, 0);
        prev_num_ways[0] = 1;
        int curr_num_ways;
        for(int i = 0; i < m; i++) {
            curr_num_ways = 0;
            for(int j = 0; j < n; j++) {
                curr_num_ways += prev_num_ways[j];
                prev_num_ways[j] = curr_num_ways;
            }
        }

        return curr_num_ways;
    }
};

// m = 3, n = 5
//
// 1 1 1 1 1
// 1 2 3 4 5
// 1 3 6 10 15

// The idea is that, for a single row, m = 1, every cell is reachable in 1 way
// When we add another row, then every cell in this row is reachable in k ways, where
// k is the cell's column position.
// When we add the number of paths of all the cells of the above 
// row less than or equal to the current cell's column, we get the 
// number of paths for the current cell.