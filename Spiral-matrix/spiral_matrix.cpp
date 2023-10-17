class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral_matrix;

        int total_el = n * n;

        int i = 0, j = 0;
        int left_lim = 0, right_lim = n - 1, top_lim = 0, bottom_lim = n - 1;

        int curr_el = 1;
        int per_ind = 1;

        while(curr_el < total_el) {
            spiral_matrix[i][j] = curr_el;

            if(curr_el == 4*(n - (2*per_ind - 1))) {
                top_lim++;
                right_lim--;
                bottom_lim--;
                left_lim++;
                per_ind++;
            }

            if(i == top_lim && j < right_lim) {
                j++;
            }
            else if(j == right_lim && i < bottom_lim) {
                i++;
            }
            else if(i == bottom_lim && j > left_lim) {
                j--;   
            }
            else if(j == left_lim && i > top_lim) {
                i--;
            }

            curr_el++;
        }

        return spiral_matrix;
    }
};