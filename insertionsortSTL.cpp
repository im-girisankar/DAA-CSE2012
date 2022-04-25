#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void iSort(vector<int> &vec)
{
    for(auto it=vec.begin(); it!=vec.end(); it++)
    {
        auto insertion_point = upper_bound(vec.begin(),it,*it);
        rotate(insertion_point,it,it+1);
    }
}

void display(vector<int> vec)
{
    for(int x:vec)
        cout<<x<<" ";
}

int main()
{
    vector<int> arr={2,1,5,3,7,5,4,6};
    iSort(arr);
    display(arr);
    return 0;
}