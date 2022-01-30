#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int* getLps(string pattern){
	int len = pattern.length();
	int* lps = new int[len];

	lps[0] = 0;

	int i = 1, j = 0;
	while(i < len){
		if(pattern[i] == pattern[j]){
			lps[i] = j + 1;
			i++;
			j++;
		}else{
			if(j != 0){
				j = lps[j - 1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

int kmpSearch(string text,string pattern){
	int lenText = text.length(); 
	int lenPat = pattern.length();

	int* lps = getLps(pattern);

	int i = 0,j = 0;

	while(i < lenText && j < lenPat){
		if(text[i] == pattern[j]){
			i++;j++;
		}else{
			if(j != 0){
				j = lps[j - 1];
			}else{
				i++;
			}
		}

		if(j == lenPat){
			int diff = abs(i - j);
			return diff;
		}
	}

	return -1;
}

int main(){
	string str,substr;
	cin>>str>>substr;

	cout<<kmpSearch(str,substr)<<endl;
}