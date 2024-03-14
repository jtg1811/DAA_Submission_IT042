#include<bits/stdc++.h>
using namespace std;

void SequentialSearch(int a[],int x,int n)
{
    for(int i = 0;i<n;i++)   
    {
        if(a[i] == x)
        {
            cout<<"Data found at Location : "<<i;
            return;
        }
    }
}

int main()
{
    int n=100000;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = i +1;
    }
    clock_t start1,end1,start2,end2;
    start1 = clock();
    SequentialSearch(arr,1,n);
    end1 = clock();
    cout<<endl;
    start2 = clock();
    SequentialSearch(arr,n,n);
    end2 = clock();
    cout<<endl;

    float time1 = float(end1-start1);
    cout<<"Best Case : "<<time1<<endl;
    float time2 = float(end2 - start2);
    cout<<"Worst Case : "<<time2<<endl;
}