#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin>>n;
    ll prices[n];
    for(int i = 0;i < n;i++){
        cin>>prices[i];
    }
    ll prefixsum[n];
    prefixsum[0] = prices[0];
    for(int i = 1;i < n;i++){
        prefixsum[i] = prefixsum[i-1]+ prices[i];
    }
    int q;
    cin>>q;
    while(q--){
        ll ans = 0;
        ll money_saved = 0;
        int curr_val;
        cin>>curr_val;
        ll index = lower_bound(prefixsum,prefixsum + n,curr_val)- prefixsum;
        if(index == 0 && prefixsum[index] == curr_val){
            ans = index + 1;
            money_saved = 0;
        }else if(curr_val < prefixsum[index]){
            ans = 0;
            money_saved = curr_val;
        }
        if(prefixsum[index] == curr_val){
            ans = index + 1;
            money_saved = 0;
        }else if(prefixsum[index - 1] < curr_val){
            ans = index;
            money_saved = curr_val - prefixsum[index - 1];
        }
        cout<<ans<<" "<<money_saved<<endl;
    }
}
