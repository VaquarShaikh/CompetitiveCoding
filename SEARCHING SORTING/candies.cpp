#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll candy[],int n,int k,ll val){
    int count = 0;
    for(int i = 0;i < n;i++){
        count += candy[i]/val;
        if(count >= k){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll candy[n];
        for(int i = 0;i < n;i++){
            cin>>candy[i];
        }
        sort(candy,candy + n);
        int ans = 0;
        ll l = 0;
        ll r = n - 1;
        while(l <= r){
            ll mid = l + (r - l)/2;
            if(check(candy,n,k,mid)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid - 1;
            }
        }
        cout<<ans<<endl;
    }
}
