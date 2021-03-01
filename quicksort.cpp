#include<iostream>
using namespace std;
/*
DIVIDE AND CONQUER APPROACH
BEST CASE- PERFECTLY BALANCED PARTITION - O(nlogn)
WORST CASE- LEAST BALANCED PARTITION - O(n^2) - will cause stack overflow and TLE
This is the sorting algorithm whose worse case is sorted array
instead of last point pivot, we can randomly select the pivot
by
y=rand(p,r)
swap(A[y],A[r])
*/


void quicksort(int [],int,int);
int partition(int [],int,int);

void quicksort(int A[],int p, int r){
    if(p>=r)    return;
    int q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
}

int partition(int A[], int p, int r){
    int i=p-1;
    int x=A[r];
    for(int j=p;j<r;++j){
        if(A[j]<x){
            swap(A[j],A[i+1]);
            i++;
        }
    }
    swap(A[r],A[i+1]);
    return i+1;
}

int main(){
    int A[10]={2,8,7,1,3,5,6,4,9,6};
    quicksort(A,0,9);
    for(int i=0;i<9;++i)
        cout<<A[i]<<" ";
    cout<<"\n";
    return 0;
}