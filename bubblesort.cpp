#include<iostream>
using namespace std;
int main()
{
   int n;

   int temp;
   cout<<"ENTER NUMBER OF ELEMENTS IN THE ARRAY:";
   cin>>n;
   int l1[n];
   cout<<"ENTER "<<n<<" ELEMENTS FOR THE ARRAY\n";
   for(int i=0;i<n;i++)
   {
      cout<<"ENTER ELEMENTS "<<i<<": ";
      cin>>l1[i];
   }
   cout<<"ENTERED ARRAY OF ELEMENTS\n";
   for(int i=0;i<n;i++)
   {

      cout<<l1[i]<<" ";
   }

   for(int i=0;i<=n-2;i++)
   {
      bool flag=false;
      for(int j=0;j<=n-2-i;j++)
      {
         if (l1[j]>l1[j+1])
         {
            temp=l1[j];
            l1[j]=l1[j+1];
            l1[j+1]=temp;
            flag=true;
         }

      }
      if(!flag)
      {
         break;
      }
   }
   cout<<"\n\nSORTED ARRAY OF ELEMENTS\n";
   for(int i=0;i<n;i++)
   {

      cout<<l1[i]<<" ";
   }
   cout<<"\n";

   return 0;
}
