#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

int main(){
    ll n,k;
    cin>>n>>k;
    ll* arr = new ll[n];

    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    sort(arr,arr + n);
    ll ans = arr[n-1] - arr[0];

    ll small = arr[0] + k,big = arr[n-1] - k;
    if(small > big){
        swap(small,big);
    }
    for(int i = 0;i <= n-2;i++){
        ll sub = arr[i] - k;
        ll add = arr[i] + k;

        if(sub >= small || add <= big){
            continue;
        }else{
            if(big - sub <= add - small){
                small = sub;
            }else{
                big = add;
            }
        }
    }
    cout<<min(ans,(big - small))<<endl;
}