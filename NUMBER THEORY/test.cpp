#include<iostream>
using namespace std;
// #include "solution.h"
#include<unordered_map>

int highestFrequency(int *input, int n){     
    
}



int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}


