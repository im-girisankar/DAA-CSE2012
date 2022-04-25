#include<iostream>
using namespace std;

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
 

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;

   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];

   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;

   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {    
      array[k] = rarr[j];
      j++; k++;
   }
}

int m,count1=0,count2=0;
void mergeSort(int *array, int l, int r) {
   if(l < r) {
      int m = l+(r-l)/2;
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
 
int main() {
    
    int size,c;
    cout<<"Enter the number of elements : ";
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>array[i];
    }

        cout<<"\nInput Array : ";
        display(array,size);
	    cout<<"\n";
	    mergeSort(array,0,size-1);
	    cout<<"MergeSorted Array : ";
	    display(array,size);
    
	return 0;
}