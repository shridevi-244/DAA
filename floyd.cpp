#include<iostream>
using namespace std;
int main()
{
   const int INF = 999;
   int n,i,j,k;
   int w[10][10],d[10][10];
   cout<<"Enter no of elements: ";
   cin>>n;
   for(i=0;i<n;i++)
   {
      for (j=0;j<n;j++)
      {
         cin>>w[i][j];
      }
   }
   for (i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         d[i][j]=w[i][j];
      }
   }
   for (k=0;k<n;k++)
   {
      for(i=0;i<n;i++)
      {
         for(j=0;j<n;j++)
         {
            if(d[i][j]==INF || d[i][j]>d[i][k]+d[k][j])
            {
               d[i][j]=d[i][k]+d[k][j];
            }
         }
      }
   }
   cout<<"\nTHE RESULTANT MATRIX:";
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         if(d[i][j] == INF)
         {
            cout<<"INF";
         }
         else
         {
            cout<<d[i][j]<<" ";
         }
      }
      cout<<endl;
   }
   return 0;
}