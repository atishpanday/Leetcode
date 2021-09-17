#include<iostream>
#include<vector>

using namespace std;

int sumArr(vector<int> arr){
	int sum = 0;
	for(int i: arr){
		sum += i;
	}
	return sum;
}

vector<int> slicing(vector<int> S, int start, int end){
	vector<int> T(S.begin() + start, S.end() - end);
	return T;
}

int maxPosDist(vector<int> A){
	// basic idea - the sum of elements of the window will be minimum when the sum of the elements left in the original matrix is maximum
	// so we find the window where the sum is minimum
	// for this we start with the window being the entire matrix and then shrink it one by one from either side.
	int left, right;
	if(A.size() > 0){
		left = maxPosDist(slicing(A, 1, 0)); // the window slides from the left end
		right = maxPosDist(slicing(A, 0, 1)); // the windows slides from the right end
		int sumA = sumArr(A);
		if(sumA < left && sumA < right){
			return sumA;
		}
		else if(left < sumA && left < right){
			return left;
		}
		else return right;
	}
	else return 0;

}

int maxNegDist(vector<int> A){
	// basic idea - the sum of elements of the window will be maximum when the sum of the elements left in the original matrix is minimum
	// so we find the window where the sum is maximum
	// for this we start with the window being the entire matrix and then shrink it one by one from either side.
	int left, right;
	if(A.size() > 0){
		left = maxNegDist(slicing(A, 1, 0)); // the window slides from the left end
		right = maxNegDist(slicing(A, 0, 1)); // the windows slides from the right end
		int sumA = sumArr(A);
		if(sumA > left && sumA > right){
			return sumA;
		}
		else if(left > sumA && left > right){
			return left;
		}
		else return right;
	}
	else return 0;

}

int main(){
	vector<int> A{1, 2, -3, -1, 8, -20};
	cout << "The maximum positive is: " << sumArr(A) - maxPosDist(A) << endl;
	cout << "The maxmimum negative is: " << sumArr(A) - maxNegDist(A) << endl;
	return 0;
}
