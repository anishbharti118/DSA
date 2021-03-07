#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

void insert_beg(node **h,int x){
    node *p = new node();
    p->data=x;
    p->next=*h;
    *h=p;
}

void insert_end(node **h,int x){
    node *p = new node();
    p->data=x;
    p->next=NULL;
    if(*h==NULL){
        *h=p;
        return;
    }
    node *last = *h;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=p;
    p->next=NULL;
}

void insert_pos(node **h,int x,int pos){
    node *p= new node();
    p->data=x;
    node *tmp = *h;
    int i=1;
    while(tmp->next!=NULL && i!=pos){
        ++i;
        tmp=tmp->next;
    }
    p->next=tmp->next;
    tmp->next=p;
}

void printls(node *h){
    while(h!=NULL){
        cout<<h->data<<"\t";
        h=h->next;
    }
}

int main(){
    node *head=NULL;
    insert_end(&head,8);
    insert_beg(&head,5);
    insert_beg(&head,3);
    insert_pos(&head,7,3);
    insert_end(&head,10);
    printls(head);
    return 0;
}