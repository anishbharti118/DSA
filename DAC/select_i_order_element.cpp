#include<iostream>
using namespace std;

int select(int [],int,int,int);
int partition(int [], int,int);

int select(int A[], int p , int r, int i){
    if(p==r)    return A[p];
    int q=partition(A,p,r);
    if(q==i)        return A[i];
    else if(q>i)    return select(A,p,q-1,i);
    else            return select(A,q+1,r,i);
}

int partition(int A[],int p, int r){
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
    int A[8]={1,5,0,6,8,7,3,9};
    int i=3;        //can put position of any element we want to get
    int ans=select(A,0,7,i);
    cout<<"Median: "<<ans<<"\n";
    return 0;
}