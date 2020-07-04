#include<iostream>
using namespace std;

template<typename data>
class unsorted
{
    data *arr;
    int n;

    public:
        //Default constructor
        unsorted()
        {
            n=0;
            arr=NULL;
        }

        //Paramaterized construtor
        unsorted(int N)
        {
            n=N;
            arr=new data[n];
            for(int i=0;i<n;i++)
                cin>>arr[i];
        }

        //Merge
        void MERGE(int p,int r,int q)
        {
            int ptr=p;
            int ptr1=p;
            int ptr2=r+1;
            int *t=new int[q-p+1];//auxiliary data structure for storing sorted variables

            while(ptr1<=r && ptr2<=q)
            {
                if(arr[ptr2]<arr[ptr1])
                    t[ptr-p]=arr[ptr2++];
                else
                    t[ptr-p]=arr[ptr1++];

                ptr++;
            }

            while(ptr<=q)
            {
                if(ptr1<=r)
                    t[ptr-p]=arr[ptr1++];
                else
                    t[ptr-p]=arr[ptr2++];

                ptr++;
            }

            for(int i=p;i<=q;i++)
                arr[i]=t[i-p];
        }

        //Merge sort
        void MERGE_SORT(int p,int q)
        {
            if(q<=p)
                return ;
            int r=(p+q)/2;
            MERGE_SORT(p,r);
            MERGE_SORT(r+1,q);
            MERGE(p,r,q);
        }

        //Prints sorted array
        void sorted_list_walk()
        {
            for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
        }

};
int main()
{
    int n;
    cin>>n;
    unsorted<int> List (n);
    List.MERGE_SORT(0,n-1);
    List.sorted_list_walk();

}

