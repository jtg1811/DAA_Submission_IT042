#include<bits/stdc++.h>
using namespace std;

void BinarySearch(int a[],int x,int n)
{
    int min =0,max=n-1;
    int mid = 0;
    while(min<=max)
    {
        mid = (min+max)/2;
        if(a[mid]==x)
        {
            cout<<"Data found at location : "<<mid;
            return;
        }
        else if(a[mid]>x)
        {
            max = mid-1;
        }
        else if(a[mid]<x)
        {
            min = mid+1;
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
    BinarySearch(arr,n/2,n);
    end1 = clock();
    cout<<endl;
    start2 = clock();
    BinarySearch(arr,n,n);
    end2 = clock();
    cout<<endl;

    double time1 = double(end1-start1);
    cout<<"Best Case : "<<time1<<endl;
    double time2 = double(end2 - start2);
    cout<<"Worst Case : "<<time2<<endl;
}