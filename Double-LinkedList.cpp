#include<iostream>

using namespace std;

struct node
{
        int p_id;
        float price;
        node *next,*pre;
};

class linked_list      //double_linked_list
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
                if(head==NULL)          // If we are inserting first element as head when my linked_list is empty ie,head=tail=NUll
                {
                        tmp->pre=NULL;  //head is equal to NULL.
                        tmp->next=head;
                        head=tmp;
                        tail=tmp;
                }
                else
                {
                        tmp->pre=NULL;          //head is not equal to NULL.
                        tmp->next=head;
                        head=tmp;
                }
        }
        void after(int id,int a,float b)        //id is that id after which we are connecting our node.and a is that id which we are
        {                                       //going to connect as node.
                node *t=head;
                while(t->p_id!=id)
                {
                        t=t->next;
                }
                node*p=new node;
                p->p_id=a;
                p->price=b;
                p->next=t->next;
                p->pre=t;
                (p->next)->pre=p;
                t->next=p;
                if(p->next==NULL)
                {
                        tail->next=p;
                        tail=p;
                }

        }

        void last(int a,float b)
        {
                node*tmp=new node;
                tmp->p_id=a;
                tmp->price=b;
                tmp->next=NULL;

                if(head==NULL)
                {
                        tmp->pre=tail; //tail is now NULL.
                        head=tmp;
                        tail=tmp;
                }
                else
                {
                        tmp->pre=tail;
                        tail->next=tmp;
                        tail=tail->next;    //we are assigning tmp;
                }
        }

        void display_loop()
        {
                node*tmp=head;
                while(tmp!=NULL)
                {
                        cout<<tmp->p_id<<" "<<tmp->price<<endl;
                        tmp=tmp->next;
                }
                cout<<"END OF TRVERSAL SEE YOU SOON ,RAJ PATEL I AM YOUR SERVANT Mr.Computer\n\n"<<endl;
        }
/*      static void display_rec(node *head)
        {
                if(head==NULL)
                {
                        cout<<
*/

        float getPrice(int a)     //by product id we are getting its price
        {
                node *tmp=head;
                while(tmp->p_id!=a)
                {
                        tmp=tmp->next;
                }
                if(tmp!=NULL)
                        return tmp->price;
                else
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

        void del_node(int a)            //a is that id which we are wanting to delete.
        {
                node *t=head;
                if(a==head->p_id)
                {
                        t=head;
                        (head->next)->pre= NULL;
                        head=head->next;
                        delete t;    //we are removing previous head ,after deletion it won't be needed
                }
                else if(a==tail->p_id)
                {
                        t=tail;
                        (tail->pre)->next=NULL;
                        tail=tail->pre;
                        delete t;    //we are removing previous tail ,after deletion it won't be needed
                }

                else
                {
                        while(t!=NULL)
                        {
                                if(t->p_id==a)
                                {
                                        (t->pre)->next=t->next;
                                        (t->next)->pre=t->pre;
                                        delete t;
                                        break;
                                }
                                else
                                        t=t->next;
                        }
                }
        }
};
int main()
{

        linked_list L;
        L.last(1,800);         //we can also take inputs from the user by cin , first store all the data in the array then
        L.last(2,800);          // we have two choices that we are appending all the product id's or prepending.
        L.last(3,1200);      //      [1]if we are appending then first product id and its corresponding price must be
        L.last(4,999.9);        //stored in linked_list by front fx and rest of all through last fx.
        L.last(5,500);       //      [2]if we are prepending then first product id and its corresponding price must be
                                //stored in linked_list by last fx and rest of all through front fx.

        L.display_loop();
        //cout<<endl<<L.getPrice(4)<<endl;
        //cout<<L.getP_id(500)<<endl;
        L.del_node(5);
        L.display_loop();
        return 0;
}
