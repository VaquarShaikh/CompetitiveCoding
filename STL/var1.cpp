#include<bits/stdc++.h>
using namespace std;

int bs(int arr[],int si,int ei,int k){
    int ans = 0;
    while(si <= ei){
        int mid = (si + ei)/2;
        if(arr[mid] - arr[si] >= k){
            ans = mid;
            ei = mid - 1;
        }else{
            si = mid+1;
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[100000];
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int count = 0;
    for(int i = 0;i < n;i++){
        int index = bs(arr,i,n-1,k);
        count += (n - index);
    }
    cout<<count<<endl;
}
