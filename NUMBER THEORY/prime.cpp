#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

int n;
bool primes[1000002];



int main(){
    cin>>n;
    for(int i = 0;i <= n;i++){
        primes[i] = true;
    }

    primes[0] = false;
    primes[1] = false;

    int count = 0;
    for(int i = 2;i*i <= n;i++){
        if(primes[i] == true){
            for(int j = i*i;j <= n;j+=i){
                primes[j] = false;
            }   
        }
    }

    for(int i = 0;i <= n;i++){
        if(primes[i]){
            count++;
        }
    }

    cout<<count<<endl;
}
