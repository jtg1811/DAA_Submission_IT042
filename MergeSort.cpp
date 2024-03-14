#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int begin,int mid,int end)
{
    int i,j,k;
    int n1 = mid - begin + 1;
    int n2 = end - mid;

    int leftArray[n1],rightArray[n2];

    for(int i =0;i<n1;i++)
    {
        leftArray[i] = a[begin+i];
    }
    for(int j=0;j<n2;j++)
    {
        rightArray[j] = a[mid+1+j];
    }

    i=j=0;
    k = begin;

    while(i<n1 && j<n2)
    {
        if(leftArray[i]<=rightArray[j])
        {
            a[k] = leftArray[i];
            i++;
        }
        else
        {
            a[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k] = leftArray[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        a[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int begin,int end)
{
    if(begin<end)
    {
        int mid = (begin+end)/2;
        mergeSort(a,begin,mid);
        mergeSort(a,mid+1,end);
        merge(a,begin,mid,end);
    }
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}


int main()
{
    int n=173000;
    int best_case[n];
    int worst_case[n];
    int temp =0;
    for(int i=n;i>0;i--)
    {
        worst_case[temp] = i;
        temp++;
    }
    for(int i = 0;i<n;i++)
    {
        best_case[i] = i+1;
    }

    clock_t start1,end1,start2,end2;
    start1 = clock();
    mergeSort(best_case,0,n-1);
    end1 = clock();
    cout<<endl;
    start2 = clock();
    mergeSort(worst_case,0,n-1);
    end2 = clock();
    cout<<endl;

    float time1 = float(end1-start1)/(float)CLOCKS_PER_SEC;
    cout<<"Best Case : "<<time1<<endl;
    float time2 = float(end2 - start2)/(float)CLOCKS_PER_SEC;
    cout<<"Worst Case : "<<time2<<endl;



    cout<<"\n**********BEST CASE**********************\n";
    print(best_case,n);
    cout<<"\n******************WORST CASE****************\n";
    print(worst_case,n);
}