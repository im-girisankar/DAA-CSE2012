#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
 
int max(int a, int b, int c) { return max(max(a, b), c); }

int BF1(int arr[],int n)
{
    int ans=INT_MIN;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j+i>n)
                break;
            int sum=0;
            for(int k=j;k<(j+i);k++)
                sum+=arr[k];
            ans=max(ans,sum);
        }
    }
    return ans;
}

int BF2(vector<int> &vec,int n)
{
    int smax=INT_MIN;
    for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum=sum+vec[j];
                smax=max(smax,sum);
            }
        }
    return smax;
}

int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
 
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
 
    return max(left_sum + right_sum, left_sum, right_sum);
}
 
int divconqmaxsubarray(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];
 
    int m = (l + h) / 2;
 
    return max(divconqmaxsubarray(arr, l, m),
               divconqmaxsubarray(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}

int auxmaxsubarray(int A[],int n)
{
    int max_end[n];
    max_end[0]=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]+max_end[i-1]>0)
            max_end[i]=A[i]+max_end[i-1];
        else
            max_end[i]=A[i];
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
        ans=max(ans,max_end[i]);
    return ans;
}

int kadanes(int arr[], int n) {
 int maxSum = INT_MIN;
 int i=0;
 for(; i <= n - 1; i++) {
   int currSum = 0;
   int j=i;
   for (; j <= n - 1; j++) {
     currSum += arr[j];
     if (currSum > maxSum) {
       maxSum = currSum;
     }
   }
 }
 
 return maxSum;
 
}

int main()
{
    int arr[] = {1, 3, 8, -2, 6, -8, 5};
    vector<int> vec={1, 3, 8, -2, 6, -8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int divconq=divconqmaxsubarray(arr,0,n-1);
    cout<<"Brute force method 1 : "<<BF1(arr,n);
    cout<<"\nBrute force method 2 : "<<BF2(vec,n);
    cout<<"\nDivide and conquer method : "<<divconq;
    cout<<"\nAuxilliary array method : "<<auxmaxsubarray(arr,n);
    cout<<"\nKadane's Method sum : "<<kadanes(arr,n);
    return 0;
}