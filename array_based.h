#include <iostream>
using namespace std;
#define INT_MAX 123456789
class queue
{
public:
    int* queuearray;
    int front;
    int rear;
    int num_items;
    queue()        //constructor
    {
        queuearray=nullptr;
        front=rear=-1;
        num_items=0;
    }
    queue(int a)        //parameterised constructor
    {
        num_items++;
        queuearray=new int[num_items];
        queuearray[0]=a;
        front=0;
        rear=front;
    }
    void enqueue(int a)        //used for inserting value in queue
    {
        if(rear==-1 && front==-1)   //empty
        {
            num_items++;
            queuearray=new int[num_items];
            queuearray[0]=a;
            front=0;
            rear=front;
        }
        else
        {
            num_items++;
            int *ab=new int[num_items];
            for(int i=front;i<=rear;i++)
            {
                ab[i]=queuearray[i];
            }
            ab[++rear]=a;
            delete [] queuearray;
            queuearray= new int[num_items];
            for(int i=front;i<=rear;i++)
            {
                queuearray[i]=ab[i];;
            }
            delete [] ab;
        }
    }
    int dequeue()        //used for removing from queue
    {
        //removes from front
        if(front==-1 && rear==-1)
        {
            cout<<"Sorry list is empty\n";
            return INT_MAX;
        }
            num_items--;
            int d= queuearray[front];
            front++;
            if(front>rear+1)
            {
                front=rear=-1;
                cout<<"QUEUE is empty\n";
                return INT_MAX;
            }
            return d;   
    }
    void print()        //prints queue
    {
        if(front==-1 && rear==-1)
        {
            cout<<"QUEUE IS EMPTY\n";
            return;
        }
        for(int i=front ;i<=rear;i++)
        {
            cout<<queuearray[i]<<" ";  
        }
        cout<<endl;
    }
    bool isEmpty()            //checks if the queue is empty
    {
        if(front==-1 && rear==-1)
            return 1;
        return 0;
    }
    void sort()        //sorts the queue [asecending order]
    {
        for(int j=front ;j<=rear;j++)
        {
            for(int i=front ;i<rear ;i++)
            {
                if(queuearray[i]>queuearray[i+1])
                {
                    //cout<<queuearray[i]<<endl;
                    int temp=queuearray[i];
                    queuearray[i]=queuearray[i+1];
                    queuearray[i+1]=temp;
                }
            }
        }
    }
    
    
};
int main()
{
    queue n1;
    n1.enqueue(2);
    n1.enqueue(4);
    n1.enqueue(21);
    n1.enqueue(1);
    n1.enqueue(98);
    n1.enqueue(6);
    cout<<"removing: "<<n1.dequeue()<<endl;
    n1.sort();
    n1.print();

    return 0;
}
