#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node * next;
};

void printls(node *h){
    while(h!=NULL){
        cout<<h->data<<"\t";
        h=h->next;
    }
}

int main(){
    node *head,*p,*q;
    head = new node();
    p=new node();
    q=new node();
    head->data=1;
    head->next=p;
    p->data=2;
    p->next=q;
    q->data=3;
    q->next=NULL;
    printls(head);
    return 0;
}