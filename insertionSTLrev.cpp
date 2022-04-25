//tried and failed 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void iSort(vector<int> &vec)
{
    for(auto it=(vec.end()-2); it!=vec.begin(); it--)
    {
        auto insertion_point = upper_bound(it,vec.end()-1,*it);
        rotate(it,insertion_point,vec.end()-1);
    }
}

void display(vector<int> vec)
{
    for(int x:vec)
        cout<<x<<" ";
}

int main()
{
    vector<int> arr={5,7,2,3,4,1,6};
    iSort(arr);
    display(arr);
    return 0;
}