#include<iostream>
#include<string.h>

using namespace std;

void swap(char* a, char* b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

int sortAsc(string str, int start){
	int temp;
	for(int i=start; i<str.length(); i++){
		for(int j=i; j<str.length(); j++){
			if((int)str[i] > (int)str[j]){
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	int res = stoi(str);
	return res;
}

int nextGreater(int num){
	string str = to_string(num);
	for(int i=str.length()-1; i>=0; i--){
		for(int j=i-1; j>=0; j--){
			if((int)str[i] > (int)str[j]){
				swap(str[i], str[j]);
				return sortAsc(str, j+1);
			}
		}
	}
	return -1;
}

int main(){
	int num;
	cout << "enter an integer: ";
	cin >> num;
	cout << nextGreater(num) << endl;
	return 0;
}