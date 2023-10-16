class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int jump_size = n / 2;
        int curr = 0;

        while(jump_size > 0) {
            if(nums[curr] < nums[(curr + jump_size) - (n)*((curr + jump_size) % (n - 1))]) {
                curr = (curr + jump_size) - (n)*((curr + jump_size) % (n - 1));
            }
            else {
                curr = curr - (jump_size % curr) + (curr / jump_size) * (n - jump_size);
            }
            jump_size = jump_size / 2;
        }

        int l = 0, m = curr, r = n - 1;

        while(l != r) {
            if(target == nums[m]) {
                return m;
            }
            else if(target > nums[m]) {
                l = m;
                m = (r - l) / 2;
            }
            else {
                r = m;
                m = (r - l) / 2;
            }
        }

        return -1;
    }
};

// 0 1 2 3 4 5 6 7 8
// 6 7 8 0 1 2 3 4 5
