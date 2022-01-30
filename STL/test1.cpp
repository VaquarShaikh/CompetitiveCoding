#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};

    cout<<lower_bound(arr,arr+5,55) - arr<<endl;
}
