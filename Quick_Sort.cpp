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

        //Partition
        int PARTITION(int p,int q)
        {
            //We are taking first element of array as pivot.
            int pivot=arr[p],i=p,j=p+1,t;

            while(j<=q)
            {//left from the index i are smaller than pivot.
                if(arr[j]<pivot)
                {
                    i++;
                    t=arr[j],arr[j]=arr[i],arr[i]=t;//swapping
                }
                j++;
            }
            t=arr[p],arr[p]=arr[i],arr[i]=t;

            return i;//index of pivot
        }

        //Quick sort
        void QUICK_SORT(int p,int q)
        {
            if(q<=p)
                return ;
            int r=PARTITION(p,q);//r have the index of pivot
            QUICK_SORT(p,r-1);
            QUICK_SORT(r+1,q);
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
    List.QUICK_SORT(0,n-1);
    List.sorted_list_walk();

}
