// #include "Solution.h"

#include<iostream>
#include<cstring>
using namespace std;
#include<unordered_map>

char nonRepeatingCharacter(string str){
    unordered_map<char,int> m;
    int n = str.size();
    for(int i = 0;i < n;i++){
    	m[str[i]]++;
    }
    for(int i = 0;i < n;i++){
    	if(m[str[i]] == 1){
    		return str[i];
    	}
    }
    return str[0];
  //Write your code here
}




int main(){

  string str;
  cin >> str;

  char ch = nonRepeatingCharacter(str);

  cout << ch << endl;

}


