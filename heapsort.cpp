#include<iostream>
using namespace std;
int main()
{
   int h[100], n;
   int i, k, j, v;
   bool heap;
   cout << "ENTER NO OF ELEMENTS\n";
   cin >> n;
   cout << "ENTER THE ELEMENTS\n";
   for (i = 1; i <= n; i++) {
      cin >> h[i];
   }
   for (i = n / 2; i >= 1; i--) {
      k = i;
      v = h[k];
      heap = false;
      while (heap == false && 2 * k <= n) {
         j = 2 * k;
         if (j < n) {
            if (h[j] < h[j + 1]) {
               j = j + 1;
            }
         }
         if (v >= h[j]) {
            heap = true;
         } else {
            h[k] = h[j];
            k = j;
         }
      }
      h[k] = v;
   }
   cout << "MAX HEAP\n--------\n";
   for (i = 1; i <= n; i++) {
      cout << h[i] << " ";
   }
   cout << endl;
   for (int last = n; last > 1; last--) {
      int temp = h[1];
      h[1] = h[last];
      h[last] = temp;
      int current_size = last - 1;
      k = 1;
      v = h[k];
      heap = false;
      while (heap == false && 2 * k <= current_size) {
         j = 2 * k;
         if (j < current_size) {
            if (h[j] < h[j + 1]) {
               j = j + 1;
            }
         }
         if (v >= h[j]) {
            heap = true;
         } else {
            h[k] = h[j];
            k = j;
         }
      }
      h[k] = v;
   }
   cout << "SORTED ARRAY (MAX HEAP)\n------------------------\n";
   for (i = 1; i <= n; i++) {
      cout << h[i] << " ";
   }
   cout<<"\n";
   return 0;
}