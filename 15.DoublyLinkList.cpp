#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data=d;
        prev=NULL;
        next=NULL;
    }
};
class DoublyLinkList
{
private:
    Node *head;
public:
    DoublyLinkList()
    {
        head=NULL;
    }
    void addNodeAtEnd(int d)
    {
        Node *newNode=new Node(d);
        if(head==NULL)
        {
            head=newNode;
            newNode->prev=head;
            newNode->next=NULL;
        }
        Node *trav=head;
        while(trav->next != NULL)
        {
            trav=trav->next;
        }
        trav->next=newNode;
        newNode->prev=trav;
        newNode->next=NULL;
    }
    void addNodeAtFront(int d)
    {
        Node *newNode = new Node(d);
        Node *trav=head;
        if(head==NULL)
        {
            head=newNode;
            newNode->next=NULL;
            newNode->prev=head;
            return;
        }
        head=newNode;
        newNode->next=trav;
        newNode->prev=head;
    }
    int deleteNodeAtEnd()
    {
        if(head==NULL)
        {
            cout<<"\n---list empty---\n";
            return 0;
        }
        Node *trav=head,*Prev=head;
        if(head->next==NULL)
        {
            head=NULL;
            return trav->data;
        }
        while(trav->next != NULL)
        {
            Prev=trav;
            trav=trav->next;
        }
        Prev->next=NULL;
        return trav->data;
    }
    int deleteNodeAtFront()
    {
        if(head==NULL)
        {
            cout<<"\n---list empty---\n";
            return 0;
        }
        Node *trav=head,*Prev=head;
        if(head->next==NULL)
        {
            head=NULL;
            return trav->data;
        }
        head=head->next;
        trav->next->prev=head;
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"\n---list empty---\n";
            return;
        }
        Node *trav=head;
        cout<<"\nyour list->\n";
        while(trav->next != NULL)
        {
            cout<<trav->data<<endl;
            trav=trav->next;
        }
        cout<<trav->data<<endl;
    }
};
int main()
{
    DoublyLinkList l;
	int temp,d;
	do{
		cout<<"\nLinked List\nDo you want to?\n";
		cout<<"1.Insert element at front.\n2.Insert element at End.\n3.Delete element at front.\n4.Delete element at end\n5.Print list.\nEnter your choice=";
		cin>>temp;
		switch(temp)
		{
		case 1:
            cout<<"\nEnter data for new node=";
			cin>>d;
			l.addNodeAtFront(d);
			break;
        case 2:
            cout<<"\nEnter data for new node=";
			cin>>d;
            l.addNodeAtEnd(d);
            break;
        case 4:
            if(l.deleteNodeAtEnd())
                cout<<"--deleted element is "<<l.deleteNodeAtEnd()<<"--\n";
            break;
        case 5:
            l.display();
            break;
        }
    }while(temp>0 && temp<6);
    return 0;
}