#include<iostream>

using namespace std;

struct node
{
        int p_id;
        float price;
        node *next;
};

class linked_list    //single_linked_list
{
        node *head,*tail;

public:
        linked_list()
        {
                head=NULL;
                tail=NULL;
        }

        node *gethead()
        {
                return head;
        }

        void front(int a,float b)
        {
                node *tmp=new node;
                tmp->p_id=a;
                tmp->price=b;
                if(head==NULL)        //when linked_list is empty ie,head=tail=NUll
                {
                        tmp->next=head;
                        head=tmp;
                        tail=tmp;
                }
                else                  //If we are inserting first element (as new head)
                {
                        tmp->next=head;
                        head=tmp;
                }
        }
        void after(int id,int a,float b)        //after id we are connecting new node.
        {
                node *t=head;
                while(t->p_id!=id)
                {
                        t=t->next;
                }
                node*p=new node;
                p->p_id=a;
                p->price=b;
                p->next=t->next;
                t->next=p;
                if(p->next==NULL)
                        tail=p;

        }

        void last(int a,float b)
        {
                node*tmp=new node;
                tmp->p_id=a;
                tmp->price=b;
                tmp->next=NULL;

                if(head==NULL)//tail is also null
                {
                        head=tmp;
                        tail=tmp;
                }
                else
                {
                        tail->next=tmp;
                        tail=tmp;
                }
        }

        void display_loop()
        {
                node*tmp=head;
                while(tmp!=NULL)
                {
                        cout<<tmp->p_id<<" : "<<tmp->price<<endl;
                        tmp=tmp->next;
                }
                cout<<"END OF TRVERSAL SEE YOU SOON ,RAJ PATEL I AM YOUR SERVANT Mr.Computer\n\n"<<endl;
        }

        float getPrice(int a)     //by product id we are getting its price
        {
                node *tmp=head;
                while(tmp!=NULL)
                {
                        if(tmp->p_id==a)
                                return tmp->price;
                        tmp=tmp->next;
                }

                return -1;
        }

        int getP_id(float a)      //by price we are getting its product id
        {
                node *tmp=head;
                while(tmp->price!=a)
                {
                        tmp=tmp->next;
                }
                if(tmp!=NULL)
                        return tmp->p_id;
                else
                        return -1;
        }
        void del_node(int a)
        {
                node *curr=head,*pre=NULL;
                if(a==head->p_id)       //here curr is at head
                {
                        if(a==tail->p_id)//we are checking that whether list had only one element or not.
                            tail=NULL;

                        head=head->next;
                        delete curr;    //we are removing previous head after deletion it won't be needed

                }
                else if(a==tail->p_id)
                {
                        while(curr!=tail)
                        {
                                pre=curr;
                                curr=curr->next;
                        }
                        pre->next=NULL;
                        tail=pre;
                        delete curr;    //we are removing previous tail after deletion it won't be needed
                }

                else
                {
                while(curr!=NULL)
                {
                        if(curr->p_id==a)
                        {
                                pre->next=curr->next;
                                delete curr;
                                break;
                        }
                        else
                                pre=curr;
                                curr=curr->next;
                }
                }
        }
};
int main()
{

        linked_list L;
        L.last(1,800);         //we can also take inputs from the user by cin , first store all the data in the array then
        L.front(2,800);          // we have two choices that we are appending all the product id's or prepending.
        L.front(3,1200);      //      [1]if we are appending then first product id and its corresponding price must be
        L.front(4,999.9);        //stored in linked_list by front fx and rest of all through last fx.
        L.after(4,5,500);       //      [2]if we are prepending then first product id and its corresponding price must be
                                //stored in linked_list by last fx and rest of all through front fx.


        L.display_loop();
       // cout<<endl<<L.getPrice(4)<<endl;
        //cout<<L.getP_id(500)<<endl;
        L.del_node(1);
        L.display_loop();
        return 0;
}
