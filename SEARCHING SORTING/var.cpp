#include<bits/stdc++.h>
using namespace std;

//typedef long long ll

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int i = 0,j = 1,count = 0;
    while(i < n && j < n){
        if(i == j){
            j++;
        }else if(abs(v[i] - v[j]) >= k){
            count += (n-j);
            i++;
        }else{
            j++;
        }
    }
    cout<<count<<endl;
}







