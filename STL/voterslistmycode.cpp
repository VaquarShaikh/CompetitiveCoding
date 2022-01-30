
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int size = n1+n2+n3;
    set<int> s;
    int* arr = new int[size];
    for(int i = 0;i < size;i++){
        cin>>arr[i];
    }
    sort(arr,arr+size);
    unordered_map<int,int> mapp;
    for(int i = 0;i < size;i++){
        mapp[arr[i]]++;
    }
    for(int i = 0;i < size;i++){
        if(mapp[arr[i]] >= 2){
            s.insert(arr[i]);
        }
    }
    cout<<s.size()<<endl;
    set<int>::iterator it;
    for(it = s.begin();it != s.end();it++){
        cout<<*it<<endl;
    }
    delete [] arr;
}
