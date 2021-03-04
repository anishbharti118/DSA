#include<iostream>
using namespace std;
#define MAX 10
struct stack{
    int Items[MAX];
    int top=-1;
};
typedef struct stack St;
//check if stack is full
int isfull(St *s){
    if(s->top==MAX-1)
        return 1;
    return 0;
}
//check if stack is empty
int isempty(St *s){
    if(s->top==-1)
        return 1;
    return 0;
}
//adding element to the stack
void push(St *s,int x){
    if(isfull(s)){
        printf("Stack is Full\n");
        return;
    }
    s->top++;
    s->Items[s->top]=x;
    printf("Inserted: %d\n",x);
}

void pop(St *s){
    if(isempty(s)){
        printf("Stack is Empty\n");
        return;
    }
    printf("Item Popped: %d\n",s->Items[s->top--]);
}

void peek(St *s){
    if(isempty(s)){
        printf("Stack is Empty\n");
        return;
    }
    printf("Element at Top is %d\n",s->Items[s->top]);
}

void printst(St *s){
     if(isempty(s)){

        printf("Stack is Empty\n");
        return;
    }
    for(int i=s->top;i>=0;--i)
        cout<<s->Items[i]<<endl;
}

int main(){
    St A;

    push(&A,10);
    push(&A,15);
    push(&A,20);
    peek(&A);
    push(&A,30);
    cout<<"\n";
    pop(&A);
    pop(&A);
    cout<<"\n";
    printst(&A);
    return 0;
}