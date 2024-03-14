#include<bits/stdc++.h>
using namespace std;
void BubbleSort(int a[],int n)
{
    int i =0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int n=1000;
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
    BubbleSort(best_case,n);
    end1 = clock();
    cout<<endl;
    start2 = clock();
    BubbleSort(worst_case,n);
    end2 = clock();
    cout<<endl;

    float time1 = float(end1-start1);
    cout<<"Best Case : "<<time1<<endl;
    float time2 = float(end2 - start2);
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