#include <iostream>
using namespace std;
# define INT_MAX 123456789
class circular_queue
{

public:
    int front;
    int rear;
    int queuesize;
    int num_items;
    int* queuearray;
    circular_queue(int a)
    {
        num_items=0;
        queuesize=a;
        front=rear=-1;
        queuearray=new int[queuesize];
    }
    void enqueue(int a)
    {
        if(front==-1 && rear==-1)       // queue is empty
        {
            num_items++;
            front=(front+1) % queuesize;
            rear=front;
            queuearray[front]=a;
        }
        else
        {
            num_items++;
            if(num_items>queuesize)
            {
                cout<<"queue is full\n";
                return;
            }
            else
            {
                rear=(rear+1)%queuesize;
                queuearray[rear]=a;
            }
        }
    }
    int dequeue()
    {
        if(front==-1 && rear==-1)
        {
            cout<<"the queue is empty\n";
            return INT_MAX;
        }
        int d=queuearray[front];
        num_items--;
        front++;
        if(front>rear+1)
        {
            front=rear=-1;
            cout<<"the queue is empty ";
            return INT_MAX;
        }
        return d;
    }
    void print()
    {
        if(front==-1 && rear==-1)
        {    cout<<"EMPTY\n";
            return;}
        for(int i=front ;i<=rear;i++)
            cout<<queuearray[i]<<" ";
        cout<<endl;
    }
    
};
int main()
{
    circular_queue n2(6);
    n2.enqueue(2);
    n2.enqueue(2);
    n2.enqueue(4);
    n2.enqueue(21);
    n2.enqueue(1);
    n2.enqueue(98);
    n2.enqueue(6);
    cout<<"removing: "<<n2.dequeue()<<endl;
    cout<<"removing: "<<n2.dequeue()<<endl;
    cout<<"removing: "<<n2.dequeue()<<endl;
    cout<<"removing: "<<n2.dequeue()<<endl;
    cout<<"removing: "<<n2.dequeue()<<endl;
    cout<<"removing: "<<n2.dequeue()<<endl;
    cout<<"removing: "<<n2.dequeue()<<endl;
    n2.print();
    
    return 0;
}
