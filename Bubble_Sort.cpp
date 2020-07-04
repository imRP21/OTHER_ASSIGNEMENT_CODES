#include<iostream>
using namespace std;

template<typename data>
class unsorted
{
    data *arr;
    int n;
    int no_swaps=0;

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

        //Getting particular element of arr
        data getElement(int i)
        {
            return arr[i];//i is index => 0<=i<n
        }

        //Getting no_swaps
        int get_No_swaps()
        {
            return no_swaps;
        }

        //Bubble sort
        void BUBBLE_SORT()
        {
           int i,j,t;

            for(i=0;i<n-1;i++)
            {
                for(j=0;j<n-1-i;j++)
                {
                    if(arr[j]>arr[j+1])
                    {
                        no_swaps++;//increamented no_swaps;
                        t=arr[j],arr[j]=arr[j+1],arr[j+1]=t;//swapping
                    }
                }
            }
        }

        //Prints sorted array
        void sorted_list_walk()
        {
            for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
        }
        void Output()
        {
            cout<<"Array is sorted in "<<get_No_swaps()<<" swaps.\n";
            cout<<"First Element: "<<getElement(0)<<endl;
            cout<<"Last Element: "<<getElement(n-1)<<endl;
        }

};
int main()
{
    int n;
    cin>>n;
    unsorted<int> List (n);
    List.BUBBLE_SORT();
    List.Output();

}
