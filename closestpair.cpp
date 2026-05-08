#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int n,x1,x2,y1,y2;
   cout << "Enter no of points:";
   cin >> n;
   double x[n],y[n];
   if (n<2)
   {
      cout << "Enter atleast two points:"<< endl;
      return 0;
   }
   for (int i=0;i<n;i++)
   {
      cout << "Enter x and y:";
      cin >> x[i] >> y[i];
   }
   double mindis = 999999.0;
   for (int i=0;i<n;i++)
   {
      for(int j=i+1;j<n;j++)
      {
         double dist = sqrt(pow(x[j]-x[i],2)+pow(y[j]-y[i],2));
         cout << "The distance of points ( " << x[i] << "," << y[i] << " ),( " << x[j] << "," << y[j] << " ) : " << dist << "\n";
         if (dist<mindis)
         {
            mindis = dist;
            x1 = x[i];
            y1 = y[i];
            x2 = x[j];
            y2 = y[j];
         }
      }
   }
   cout << "The Closest Distance  : "<< mindis << endl;
   cout << "The obtained closest distance points are ( " << x1 << "," << y1 << " ),( "<<x2<<","<<y2<<" )\n";
   return 0;
}