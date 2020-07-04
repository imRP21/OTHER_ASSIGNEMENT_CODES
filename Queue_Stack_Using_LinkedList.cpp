#include<iostream>
#include<cstdlib>
using namespace std;

template<typename data>
struct Node
{
    data key;
    Node<data> *next;
};
/////////////// CLASS LinkList ////////////////
template<typename data>
class LinkList
{
    protected:
        Node<data> *head,*tail;

    public:
        LinkList() { head=NULL,tail=NULL; };
        void front(data tmp);
        void last(data tmp);
        void display();
        int SIZE();
};

template<typename data>
void LinkList<data>::front(data tmp)
{
    Node<data> *t=new Node<data>;
    t->key=tmp;

    if(head==NULL)
    {
        t->next=head;
        head=t;
        tail=t;
    }
    else
    {
        t->next=head;
        head=t;
    }
}

template<typename data>
void LinkList<data>::last(data tmp)
{
    Node<data> *t=new Node<data>;
    t->key=tmp;
    t->next=NULL;

    if(head==NULL)
    {
        head=t;
        tail=t;
    }
    else
    {
        tail->next=t;
        tail=t;
    }
}

template<typename data>
int LinkList<data>::SIZE()
{
    int count=0;
    Node<data> *t=head;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }

    return count;
}

template<typename data>
void LinkList<data>::display()
{
    cout<<endl;
    Node<data> *t=head;
    while(t!=NULL)
    {
        cout<<t->key<<"->";
        t=t->next;
    }
    cout<<"NULL"<<endl;
}

/////////////// CLASS LinkStack ///////////////
template<typename data>
class LinkStack:public LinkList<data>
{
    public:
        LinkStack() { this->head=NULL,this->tail=NULL;};
        void PUSH(data tmp);
        void POP();
};

template<typename data>
void LinkStack<data>::PUSH(data tmp)
{
    Node<data> *t=new Node<data>;
    t->key=tmp;
    t->next=NULL;

    if(this->head==NULL)
    {
       this->head=t;
       this->tail=t;
    }
    else
    {
        (this->tail)->next=t;
        (this->tail)=t;
    }
}

template<typename data>
void LinkStack<data>::POP()
{
    if(this->tail==NULL)
        cout<<"POP IS NOT POSSIBLE IN CURRENT STACK";
    else
    {
        Node<data> *curr=this->head,*pre=NULL;
        while(curr!=this->tail)
        {
            pre=curr;
            curr=curr->next;
        }
        if(pre!=NULL)       //we have to check whether the list has one element
        {                   //or not .Because in that case while loop doesn't
            pre->next=NULL; //execute as curr=head=tail.(only 1 element) so
            this->tail=pre; //pre->next would throw an error and here after
        }                   //deletion head also needs to modify by assign it
        else                //to NULL .
        {
            this->tail=NULL;
            this->head=NULL;
        }
        delete curr;
    }
}

/////////////// CLASS linkQueue ///////////////
template<typename data>
class LinkQueue:public LinkList<data>
{
    public:
        LinkQueue() { this->head=NULL,this->tail=NULL; };
        void ENQUEUE(data tmp);
        void DEQUEUE();
};

template<typename data>
void LinkQueue<data>::ENQUEUE(data tmp)
{
    Node<data> *t=new Node<data>;
    t->key=tmp;
    t->next=NULL;

    if(this->head==NULL)
    {
       this->head=t;
       this->tail=t;
    }
    else
    {
        this->tail->next=t;
        this->tail=t;
    }
}

template<typename data>
void LinkQueue<data>::DEQUEUE()
{
    if(this->head==NULL)
        cout<<"POP IS NOT POSSIBLE IN CURRENT QUEUE";
    else
    {
        Node<data> *t=this->head;
        this->head=(this->head)->next;
        delete t;
    }
}

int main()
{
    LinkQueue<long> S;
    for(int i=0;i<10;i++)
        S.ENQUEUE(rand()),S.display();

    for(int i=0;i<10;i++)
        S.DEQUEUE(),S.display();

    return 0;
}
