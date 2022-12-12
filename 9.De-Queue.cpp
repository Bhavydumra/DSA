#include<iostream>
using namespace std;
#define max 5
class DeQueue
{
private:
   int a[max],rear,front;
public:
    DeQueue()
    {
        rear=-1;
        front=-1;
    }
    bool isEmpty()
    {
        if(front == -1 && rear == -1)
        {
            return 1;
        }
        return 0;
    }
    bool isFull()
    {
        if(front==0 && rear==max-1)
            return 1;
        return 0;
    }
    void addAtFront(int d)
    {
        if(isFull())
        {
            cout<<"\nQueue full\n";
            return;
        }
        if(isEmpty())
        {
            front=rear=0;
            a[front]=d;
            cout << "\nvalue inserted " << d << front << endl;
            return;
        }
        ++rear;
        for(int i=rear;i>front;i--)
        {
            cout<<"shifting";
            a[i]=a[i-1];
        }
        a[front]=d;
        cout << "\nvalue inserted " << d << endl;
    }
    void addAtEnd(int d)
    {
        if(isFull())
        {
            cout<<"\nQueue full\n";
            return;
        }
        if(isEmpty())
        {
            front=rear=0;
            a[rear]=d;
            cout << "\nvalue inserted " << d << endl;
            return;
        }
        a[++rear]=d;
        cout << "\nvalue inserted " << d << endl;
    }
    int deleteFromFront()
    {
        if(isEmpty())
        {
            cout<<"\n--Queue empty--\n";
            return 0;
        }
        int temp=a[front];
        for(int i=front;i<rear;i++)
            a[i]=a[i+1];
        --rear;
        return temp;
    }
    int deleteFromEnd()
    {
        if(isEmpty())
        {
            cout<<"\n--Queue empty--\n";
            return 0;
        }
        return a[rear--];
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"\nQueue empty.\n";
            return;
        }
        cout<<"\nYour queue->\n";
        for(int i=front;i<=rear;i++)
            cout<<a[i]<<endl;
    }
};
int main()
{
    DeQueue q1;
    int ch;
    int value;
    do
    {
        cout << "\n1.Insert at front.\n2. Insert at end.\n3. Delete from front.\n4. Delete from end.\n5.PrintList.\n" << endl;

        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter value you want to insert in queue=" << endl;
            cin >> value;
            q1.addAtFront(value);
            break;

        case 2:
            cout << "\nEnter value you want to insert in queue=" << endl;
            cin >> value;
            q1.addAtEnd(value);
            break;

        case 3:
            cout << "\n--Deleted element " << q1.deleteFromFront() << "--\n";
            break;
        case 4:
            cout << "\n--Deleted element " << q1.deleteFromEnd() << "--\n";
            break;
        case 5:
            q1.display();
            break;
        default:
          break;
        }
    } while (ch>0 && ch<6);
    return 0;
}