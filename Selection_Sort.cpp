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

        //Selection_sort
        void SELECTION_SORT()
        {
            int i,j,t;
            for(i=0;i<n-1;i++)
            {
                int min_index=i;
                for(j=i+1;j<n;j++)
                    if(arr[min_index]>arr[j])
                        min_index=j;

                t=arr[min_index],arr[min_index]=arr[i],arr[i]=t;
            }
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
    List.SELECTION_SORT();
    List.sorted_list_walk();

}
