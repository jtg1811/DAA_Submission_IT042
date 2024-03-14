#include<bits/stdc++.h>
using namespace std;
int split(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int i = lb + 1;
    int j = ub;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }

        while (i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    int temp = arr[lb];
    arr[lb] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[],int lb,int ub){
    if(lb>ub){
        return;
    }
    else{
        int pos =split(arr,lb,ub);
        quickSort(arr,lb,pos-1);
        quickSort(arr,pos+1,ub);
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
    int n=10000;
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
    quickSort(best_case,0,n-1);
    end1 = clock();
    cout<<endl;
    start2 = clock();
    quickSort(worst_case,0,n-1);
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