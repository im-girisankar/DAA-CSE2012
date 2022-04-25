#include <iostream>
using namespace std;
 
int countSolutions(int n)
{
   int res = 0;
   for (int x = 0; x*x < n; x++)
      for (int y = 0; x*x + y*y < n; y++)
         res++;
   return res;
}
 
int main()
{
    int a;
    cout << "Total Number of distinct Non-Negative pairs is "
         << countSolutions(1) << endl;
    return 0;
}