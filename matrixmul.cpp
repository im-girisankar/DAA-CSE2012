#include<iostream>
using namespace std;
#include<vector>

void read_matrix(vector<vector<int>> &M,int n)
{
    int i,j,x;
    for(int i=0;i<n;i++)
    {
        vector<int> row;
        for(j=0;j<n;j++)
        {
            cout<<"Enter element "<<i+1<<j+1<<" : ";
            cin>>x;
            row.push_back(x);
        }
        M.push_back(row);
    }
}

void print_matrix(vector<vector<int>> M)
{
    int n=M.size(),i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<M[i][j]<<"  ";
        cout<<"\n";
    }
}

void matrix_multiply(vector<vector<int>> &M1,vector<vector<int>> &M2,vector<vector<int>> &P)
{
    int i,j,k,n;
    n=M1.size();
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            P[i][j]=0;
            for(k=0;k<n;k++)
            {
                P[i][j]+=M1[i][k]*M2[k][j];
            }
        }
    }
}

int main()
{
    vector<vector<int>> M1,M2;
    int n;
    cout<<"Enter the size of the matrix : ";
    cin>>n;
    cout<<"First matrix \n";  
    read_matrix(M1,n);
    cout<<"\nSecond matrix \n";   
    read_matrix(M2,n);
    vector<vector<int>> P(n,vector<int>(n,0));
    matrix_multiply(M1,M2,P);
    cout<<"Product Matrix : \n";
    print_matrix(P);

    return 0;
}