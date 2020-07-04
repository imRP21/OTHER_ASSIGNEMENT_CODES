#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/////////////// F(X) which converts num to string ///////////////
string num_to_str(long num)
{
    int i=0,length=floor(log10(num))+1;
    char str[length+1];

    while(num)
    {
        str[length-1-i++]=num%10 + 48;
        num/=10;
    }
    str[length]='\0';

    return str;
}

struct Student
{
    long StudentID;
    string name;
    Student *next;
};

/////////////// CLASS linked_list ///////////////
class linked_list    //single_linked_list   -This is the same as the single_linked_list that I had implemented in
{                    //the one of the previous lab submission with needed modifications.
    Student *head,*tail;

    public:
        linked_list()
        {
            head=NULL;
            tail=NULL;
        }

        Student *getHead()
        {
            return head;
        }

        void front(long n,string t)
        {
            Student *tmp=new Student;
            tmp->StudentID=n;
            tmp->name=t;
            if(head==NULL)        //when linked_list is empty ie,head=tail=NUll
            {
                tmp->next=head;
                head=tmp;
                tail=tmp;
            }
            else                  //If we are inserting first element(as new head).
            {
                tmp->next=head;
                head=tmp;
            }
        }

        void insert_Student_data(long n,string t)//we are inserting the node as per the sorted order, so no need to sort it again.
        {
            Student *tmp=new Student;
            tmp->StudentID=n;
            tmp->name=t;
            tmp->next=NULL;

            if(head==NULL)
            {
                head=tmp;
                tail=tmp;
            }
            else
            {
                Student *ptr=head, *ptr1=NULL;
                while(ptr!=NULL && (ptr->StudentID)<n)
                {
                    ptr1=ptr;
                    ptr=ptr->next;
                }

                if(ptr==head)//if tmp would be the first element of the list.
                {
                    head=tmp;
                    tmp->next=ptr;
                }
                else if(ptr==NULL)//if the tmp would be the last element of the list.
                {
                    ptr1->next=tmp;
                    tail=tmp;
                }
                else//other than corner cases.
                {
                    tmp->next=ptr;
                    ptr1->next=tmp;
                }

            }
        }

        void walk()
        {
            Student *ptr=head;
            while(ptr!=NULL)
            {
                cout<<"-->"<<'['<<ptr->StudentID<<" : "<<ptr->name<<']';
                ptr=ptr->next;
            }
            cout<<endl;
        }

        string search_Student_data(long n)   //As corresponding linked_list is sorted, one could use binary search also.
        {
            Student *ptr=head;
            while(ptr!=NULL && (ptr->StudentID)!=n)
                ptr=ptr->next;

            if(ptr!=NULL)
                return ptr->name;

            else
                return "Not Found";
        }

        int getStudentID(string t)
        {
            Student *tmp=head;
            while(tmp!=NULL)
            {
                if(tmp->name==t)
                    return tmp->StudentID;
                tmp=tmp->next;
            }

            return -1;
        }

        string getName(long n)
        {
            Student *tmp=head;
            while(tmp->StudentID!=n)
            {
                tmp=tmp->next;
            }
            if(tmp!=NULL)
                return tmp->name;
            else
                return "error";
        }
        void delete_Student_data(long n)
        {
            Student *curr=head,*pre=NULL;
            if(n==head->StudentID)       //here curr is at head
            {
                head=head->next;
                delete curr;    //we are removing previous head after deletion it won't be needed
            }
            else if(n==tail->StudentID)
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
                    if(curr->StudentID==n)
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

/////////////// CLASS HashTable ///////////////
class HashTable
{
    int SIZE;
    static linked_list *table;

    public:
        HashTable(int n)
        {
            SIZE=n;
            table= new linked_list[SIZE];
        }

        void insert_data(long n,string t)
        {
            int index=HashFunction(n);
            table[index].insert_Student_data(n,t);
        }

        void delete_data(long key)//We are deleting Student data by Student ID
        {
            int index=HashFunction(key);
            table[index].delete_Student_data(key);

        }

        string search_data(long key)//We are searching Student data by Student ID
        {
            int index=HashFunction(key);

            return table[index].search_Student_data(key);
        }

        int HashFunction(long n)
        {
            return (n%SIZE);
        }

        void display_HashTable()
        {
            for(int i=0;i<SIZE;++i)
            {
                cout<<"INDEX NO. "<<i;
                table[i].walk();
            }
        }
};
linked_list* HashTable::table;
int main()
{
    int n=13; // as per the requirement.
    HashTable HT(n);

    //This following DATASET is given to us.
    long HASH_DATASET[100][2] = {
{201600001,1},{201600002,2},{201600003,3},{201600004,4},{201600005,5},{201600006,6},{201600007,7},{201600008,8},{201600009,9},{201600010,10},
{201600011,11},{201600012,12},{201600013,13},{201600014,14},{201600015,15},{201600016,16},{201600017,17},{201600018,18},{201600019,19},{201600020,20},
{201600021,21},{201600022,22},{201600023,23},{201600024,24},{201600025,25},{201700113,26},{201700117,27},{201700121,28},{201700125,29},{201700129,30},
{201700133,31},{201700137,32},{201700141,33},{201700145,34},{201700149,35},{201700153,36},{201700157,37},{201700161,38},{201700165,39},{201700169,40},
{201700173,41},{201700177,42},{201700181,43},{201700185,44},{201700189,45},{201700193,46},{201700197,47},{201700201,48},{201700205,49},{201700209,50},
{201911001,51},{201911005,52},{201911009,53},{201911013,54},{201911017,55},{201911021,56},{201911025,57},{201911029,58},{201911033,59},{201911037,60},
{201911041,61},{201911045,62},{201911049,63},{201911053,64},{201911057,65},{201911061,66},{201911065,67},{201911069,68},{201911073,69},{201911077,70},
{201911081,71},{201911085,72},{201911089,73},{201911093,74},{201911097,75},{201911101,76},{201911105,77},{201911109,78},{201911113,79},{201911117,80},
{201911121,81},{201911125,82},{201911129,83},{201911133,84},{201911137,85},{201911141,86},{201911145,87},{201911149,88},{201911153,89},{201911157,90},
{201911161,91},{201911165,92},{201911169,93},{201911173,94},{201911177,95},{201911181,96},{201911185,97},{201911189,98},{201911193,99},{201911197,100},
};


    for(int i=0;i<100;++i)
    {
        HT.insert_data(HASH_DATASET[i][0],num_to_str(HASH_DATASET[i][1]));
    }

    HT.display_HashTable();

   /* cout<<HT.search_data(201600021)<<endl;
    cout<<HT.search_data(201911165)<<endl;
    cout<<HT.search_data(201911197)<<endl;
    */

    HT.delete_data(201600021);
    HT.display_HashTable();
    return 0;
}
