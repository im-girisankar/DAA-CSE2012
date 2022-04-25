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

void square_matrix_multiply_recursive(vector<vector<int> > &mat1,vector<vector<int> > &mat2, vector<vector<int> > &mat3, int top1, int left1, int top2, int left2, int size)
{       
    if (size==1)
    {
        mat3[top1][left2] += mat1[top1][left1] * mat2[top2][left2];
    }
    else
    {

        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1,top2,left2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1+size/2,top2+size/2,left2,size/2);
        
        
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1,top2,left2+size/2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1+size/2,top2+size/2,left2+size/2,size/2);
        
        
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1,top2,left2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1+size/2,top2+size/2,left2,size/2);
        
        
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1,top2,left2+size/2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1+size/2,top2+size/2,left2+size/2,size/2);
        
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
    cout<<"Product Matrix(using recursion): \n";
    square_matrix_multiply_recursive(M1,M2,P,0,0,0,0,n);
    print_matrix(P);

    return 0;
} 