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

        //Build (max)heap subroutine
        void BUILD_HEAP()
        {   //initialy heapsize is n.
            for(int i=n/2-1;i>=0;--i)
                HEAPIFY(i,n);

        }

        //Heapify subroutine
        void HEAPIFY(int i,int heapsize)
        {   //heapsize is size of heap
            int Left=2*i+1;
            int Right=2*i+2;
            int largest=i;  //initialized by root
            data t;

            //all index <size of array(n)
            if(Right<heapsize)
            {
                if(arr[Left]<arr[Right])
                    largest=Right;
                else
                    largest=Left;
            }
            else if(Left<heapsize)
                    largest=Left;

            if(arr[i]<arr[largest])
            {
                t=arr[i],arr[i]=arr[largest],arr[largest]=t;//swapping
                HEAPIFY(largest,heapsize);
            }
        }

        //Heap_sort
        void HEAP_SORT()
        {   //heap(array) is zero indexed.
            data t;
            BUILD_HEAP();
            int heapsize=n;
            for(int i=n-1;i>0;--i)
            {
                t=arr[0],arr[0]=arr[i],arr[i]=t;
                //now we don't have to include last( at index=heapsize-1) element in the heap.
                HEAPIFY(0,--heapsize);
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
    List.HEAP_SORT();
    List.sorted_list_walk();

}
