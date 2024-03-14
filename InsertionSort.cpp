#include<bits/stdc++.h>
using namespace std;
void InsertionSort(int a[],int n)
{
    int temp;
    for(int i = 1;i<n;i++)
    {
        temp = a[i];
        int j = i-1;
        while(j>=0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j=j-1;
        }
        a[j+1] = temp;
    }
}
int main()
{
    int n=10;
    int best_case[n];
    int worst_case[n];
    for(int i=n;i>0;i--)
    {
        worst_case[i-1] = i;
    }
    for(int i = 0;i<n;i++)
    {
        best_case[i] = i+1;
    }
    clock_t start1,end1,start2,end2;
    start1 = clock();
    InsertionSort(best_case,n);
    end1 = clock();
    cout<<endl;
    start2 = clock();
    InsertionSort(worst_case,n);
    end2 = clock();
    cout<<endl;

    float time1 = float(end1-start1)/(float)CLOCKS_PER_SEC;
    cout<<"Best Case : "<<time1<<endl;
    float time2 = float(end2 - start2)/(float)CLOCKS_PER_SEC;
    cout<<"Worst Case : "<<time2<<endl;
    for(int j =0;j<n;j++)
    {
        cout<<worst_case[j];
        cout<<" ";
    }
    cout<<endl;
    for(int j =0;j<n;j++)
    {
        cout<<best_case[j];
        cout<<" ";
    }
}