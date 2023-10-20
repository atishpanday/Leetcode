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