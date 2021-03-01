#include<stdio.h>
#include<limits.h>
#include<iostream>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}

int max(int a,int b, int c){
    return max(max(a,b),c);
}

int maxCrossingSum(int A[],int l, int m, int h){
    int sum=0;
    int left_sum=INT_MIN;
    for(int i=m;i>=l;--i){
        sum=sum+A[i];
        if(sum>left_sum)
            left_sum=sum;
    }   

    sum=0;
    int right_sum=INT_MIN;
    for(int i=m+1;i<=h;++i){
        sum=sum+A[i];
        if(sum>right_sum)
            right_sum=sum;
    }

    return max(left_sum+right_sum,left_sum,right_sum);
}

int maxSubArraySum(int A[],int l, int h){
    if(l==h)
        return A[l];
    int m=(l+h)/2;

    return  max(maxSubArraySum(A,l,m),
                maxSubArraySum(A,m+1,h),
                maxCrossingSum(A,l,m,h));
}

int main(){
    int A[10];
    for(int i=0;i<10;++i)
        cin>>A[i];
    int max_sum=maxSubArraySum(A,0,9);
    cout<<"Max Sum SubArray: "<<max_sum;
    getchar();
}