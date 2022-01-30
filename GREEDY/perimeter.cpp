#include<bits/stdc++.h>
using namespace std;

void maximumPerimeterTriangle(vector<long> v)
{
    sort(v.rbegin(),v.rend());
    
    for(int i=2;i<v.size();i++)
    {
        if(v[i]+v[i-1] > v[i-2])
        {
            cout<<v[i]<<" "<<v[i-1]<<" "<<v[i-2]<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
    return;
}


int main(){
    int n;
    cin>>n;
    vector<long> v;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    maximumPerimeterTriangle(v);
}