#include<iostream>
#include<vector>

class Solution{
public:

  int trap(std::vector<int>& height){
    // if the input vector is empty, simply return 0
    if(height.size() == 0){
      return 0;
    }

    // define the size of the input vector, the left array and the right array
    int n = height.size();
    int left[n], right[n];
    left[0] = height[0];
    right[n-1] = height[n-1];

    for(int i=1; i<n; i++){
      left[i] = std::max(left[i-1], height[i]);
    }

    for(int i=n-2; i>=0; i--){
      right[i] = std::max(right[i+1], height[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
      ans += std::min(left[i], right[i]) - height[i];
    }

    return ans;
  }
};

int main(){
  Solution sol;
  std::vector<int> height = {1, 2, 1, 0, 4, 5, 2, 4};
  std::cout << "the answer is: " << sol.trap(height);
  return 0;
}