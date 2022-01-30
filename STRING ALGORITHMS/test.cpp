#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int countPalindromeSubstrings(char s[]) {
	int max = 0,count = 0;
	int n = strlen(s);
	for(int i = 0;i < n;i++){
		int l = i;
		int r = i;

		while(l >= 0 && r < n && s[l] == s[r]){
			int curr_l = r - l + 1;
			if(curr_l > max){
				max = curr_l;
			}
			l--;
			r++;
			count++;
		}

		l = i;
		r = i + 1;

		while(l >= 0 && r < n && s[l] == s[r]){
			int curr_l = r - l + 1;
			if(curr_l > max){
				max = curr_l;
			}
			l--;
			r++;
			count++;
		}
	}
	return count;
}

int main() {
	char input[10000];
	cin >> input;
	cout << countPalindromeSubstrings(input) << endl;
}