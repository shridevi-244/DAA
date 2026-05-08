#include<iostream>
using namespace std;
int main()
{
   int n;
   cout<<"Enter no. of elements:";
   cin>>n;
   int a[n];
   int temp,min;
   cout<<"ENTER ELEMENTS\n";
   for(int i=0;i<n;i++)
   {
      cout<<"Enter element "<<i<<":";
      cin>>a[i];
   }
   cout<<"---- Given Array ----\n";
   for (int i=0;i<n;i++)
   {
      cout<<a[i]<<" ";
   }
    cout<<"\n---------------------\n";
   for (int i=0;i<n-1;i++)
   {
      min=i;
      for(int j=i+1;j<n;j++)
      {
         if(a[j]<a[min])
         {
            min=j;
         }

         if(min != i)
         {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
         }
      }
      }
   cout<<"---- Sorted Array -----\n";
   for (int i=0;i<n;i++)
   {
      cout<<a[i]<<" ";
   }
    cout<<"\n-----------------------\n";
   return 0;
}