#include<iostream>
using namespace std;
#define MAX 10
class queue{
    private:
        int Items[MAX],rear=-1,front=-1;
    public:
        bool isfull(){
            if(front==0 && rear==MAX-1)
                return true;
            return false;
        }

        bool isempty(){
            if(front==-1)
                return true;
            return false;
        }

        void enqueue(int x){
            if(isfull()){
                printf("Queue is Full\n");
                return;
            }
            else{
                if(front==-1)
                    front=0;
                rear++;
                Items[rear]=x;
                cout<<"Inserted: "<<x<<endl;
            }
        }

        void dequeue(){
            if(isempty()){
                printf("Queue is Empty\n");
                return;
            }
            else{
                int x=Items[front];
                if(front>=rear){
                    front=-1;
                    rear=-1;
                }
                else
                    front++;
                cout<<"Deleted: "<<x<<endl;
            }
        }

        void display(){
            if(isempty()){
                printf("Queue is Empty\n");
                return;
            }
            else{
                for(int i=front;i<=rear;++i)
                    cout<<Items[i]<<"\t";
                cout<<"\n";
            }
        }
};

int main(){
    queue Q;

    Q.dequeue();
    Q.enqueue(5);
    Q.enqueue(7);
    Q.enqueue(9);
    Q.display();
    Q.dequeue();
    Q.display();
    return 0;
}