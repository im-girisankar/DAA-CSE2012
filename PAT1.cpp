#include<iostream>
using namespace std;

void swap(char *a, char *b) {
	char t = *a;
	*a = *b;
	*b = t;
}

void display(char *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
 

void vowelmerge(char *array, int l, int m, int r) {
   int i, j, k, nl, nr;

   nl = m-l+1; nr = r-m;
   char larr[nl], rarr[nr];

   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;

   while(i < nl && j<nr) {
      if(larr[i]=='A'||larr[i]=='E'||larr[i]=='I'||larr[i]=='O'||larr[i]=='U') {
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

void vowelSort(char *array, int l, int r) {
   if(l < r) {
      int m = l+(r-l)/2;
      vowelSort(array, l, m);
      vowelSort(array, m+1, r);
      vowelmerge(array, l, m, r);
   }
}
 
int main() {
    
    int size;
    cout<<"Enter the number of elements : ";
    cin>>size;
    char array[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>array[i];
    }

        cout<<"\nInput Array : ";
        display(array,size);
	    cout<<"\n";
	    vowelSort(array,0,size-1);
	    cout<<"Vowel Sorted Array : ";
	    display(array,size);
    
	return 0;
}