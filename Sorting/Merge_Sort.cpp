#include <iostream>
#include <vector>
using namespace std;
void merge(int low,int mid,int high,vector<int> &arr){
    int n1=mid-low+1;
    int n2=high-mid;
    vector<int> l(n1),r(n2);
    int idx=low;
    for (int i=0;i<n1;i++){
        l[i]=arr[idx];
        idx++;
    }
    for (int i=0;i<n2;i++){
        r[i]=arr[idx];
        idx++;
    }

    int a=0,b=0;
    idx=low;
    while(a<n1 && b<n2){
        if (l[a]<r[b]){
            arr[idx]=l[a];
            a++;
            
        }else{
            arr[idx]=r[b];
            b++;
        }
        idx++;
    }
    while(a<n1){
        arr[idx]=l[a];
        a++;
        idx++;
    }
    while(b<n2){
        arr[idx]=r[b];
        b++;
        idx++;
    }
}
void mergeSort(int low,int high,vector<int> &arr){
    if (low>=high) return ;
    if (low<high){
        int mid=low+(high-low)/2;
        mergeSort(low,mid,arr);
        mergeSort(mid+1,high,arr);
        merge(low,mid,high,arr);
    }
}
int main(){
    vector<int> arr={4,2,7,1,5,3};
    int n=arr.size();
    mergeSort(0,n-1,arr);
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

}