#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void iSort(vector<char> &vec)
{
    for(auto it=vec.begin(); it!=vec.end(); it++)
    {
        auto insertion_point = upper_bound(vec.begin(),it,*it);
        rotate(insertion_point,it,it+1);
    }
}

void display(vector<char> vec)
{
    for(char x:vec)
        cout<<x<<" ";
}

int main()
{
    vector<char> arr={'e','a','f','b','d','c'};
    iSort(arr);
    display(arr);
    return 0;
}