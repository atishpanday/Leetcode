#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> answer;
	vector<vector<int>> permute(vector<int>& nums){
		findPerms(nums, 0, nums.size()-1);
        return answer;
	}

	void findPerms(vector<int>& nums, int start, int end){
		if(start == end) {
			// for(int i: nums) cout << i;
			// cout << endl;
			answer.push_back(nums);
            return;
		}
		for(int i=start; i<=end; i++){
			for(int i: nums) cout << i;
			cout << endl;
			swapNums(&nums[start], &nums[i]);
			findPerms(nums, start+1, end);
			swapNums(&nums[start], &nums[i]);
			for(int i: nums) cout << i;
			cout << endl;
		}
	}

	void swapNums(int* a, int* b){
		*a = *a+*b;
		*b = *a-*b;
		*a = *a-*b;
	}
};

int main(){
	Solution sol;
	vector<int> A{1, 2, 3};
	vector<vector<int>> output = sol.permute(A);
	// for(vector<int> i: output){
	// 	for(int j: i){
	// 		cout << j;
	// 	}
	// 	cout << "\n";
	// }
	return 0;
}