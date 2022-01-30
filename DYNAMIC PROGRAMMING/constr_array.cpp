#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

long countArray(int n, int k, int x) {
    long onecount = 1;
    long nononecount = 0;
    for(int i = 1;i < n;i++){
        long prevonecount = onecount;
        onecount = (nononecount*(k-1))%mod;
        nononecount = (prevonecount + (nononecount*(k-2))%mod)%mod;
    }if(x == 1){
        return onecount;
    }else{
        return nononecount;
    }
}

int main()
{
    int n,k,l;
    cin>>n>>k>>l;
    cout<<countArray(n,k,l)<<endl;
}