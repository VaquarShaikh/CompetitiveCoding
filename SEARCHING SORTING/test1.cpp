#include<iostream>
#include<unordered_map>
using namespace std;

int merge(int arr[],int si,int ei){
    int size = ei - si + 1;
    int* temp = new int[size];

    int mid = (si + ei)/2;
    int i = si,j = mid + 1,k = 0;
    int count = 0;
    while(i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            count += (mid + 1 - i);
        }
    }while(i <= mid){
        temp[k++] = arr[i++];
    }while(j <= ei){
        temp[k++] = arr[j++];
    }
    int m = 0;
    for(int i = si;i<=ei;i++){
        arr[i] = temp[m++];
    }
    delete [] temp;
    return count;
}

int mergesort(int arr[],int si,int ei){
    if(si >= ei){
        return 0;
    }
    int mid = (si + ei)/2;
    int lc = mergesort(arr,si,mid);
    int rc = mergesort(arr,mid+1,ei);
    int mc = merge(arr,si,ei);
    return lc + rc + mc;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<string,int> mapp;
        for(int i = 0;i < n;i++){
            string word;
            cin>>word;
            mapp.insert(make_pair(word,i));
        }
        int arr[n],k = 0;
        for(int i = 0;i < n;i++){
            string word;
            cin>>word;
            arr[k++] = mapp[word];
        }
        cout<<mergesort(arr,0,n-1)<<endl;
    }
}
