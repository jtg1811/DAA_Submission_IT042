 #include<bits/stdc++.h>
 using namespace std;
 void selectionsort(int a[],int n)
 {
    int i=0,j=0,temp;
    for(i =0;i<n-1;i++)
    {
        temp =i;
        for(j=i +1 ;j<n;j++)
        {
            if(a[temp]>a[j])
            {
                temp = j;
            }
        }
        if(temp !=i)
        {
            swap(a[temp],a[i]);
        }
        
    }
}
int main()
{
    int n=100000;
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
    selectionsort(best_case,n);
    end1 = clock();
    cout<<endl;
    start2 = clock();
    selectionsort(worst_case,n);
    end2 = clock();
    cout<<endl;

    float time1 = float(end1-start1)/(float)CLOCKS_PER_SEC;
    cout<<"Best Case : "<<time1<<endl;
    float time2 = float(end2 - start2)/(float)CLOCKS_PER_SEC;
    cout<<"Worst Case : "<<time2<<endl;
    // for(int j =0;j<n;j++)
    // {
    //     cout<<worst_case[j];
    //     cout<<" ";
    // }
    // cout<<endl;
    // for(int j =0;j<n;j++)
    // {
    //     cout<<best_case[j];
    //     cout<<" ";
    // }
}