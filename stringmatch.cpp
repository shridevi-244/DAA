#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   int k=0,l=0;
   string text;
   string pattern;
   cout << "Enter the text:";
   getline(cin,text);
   cout << "Enter the pattern:";
   getline(cin,pattern);
   int tcount=0;
   while(text[k]!='\0')
   {
      tcount++;
      k++;
   }
   int pcount=0;
   while(pattern[l]!='\0')
   {
      pcount++;
      l++;
   }
   int n = tcount;
   int m = pcount;
   cout<<"Text length: "<<n<<"\n"<<"Pattern length: "<<m<<endl;
   bool found = false;
   for (int i=0;i<=n-m;i++)
   {
      int j=0;
      while(j<m && text[i+j]==pattern[j])
      {
         j++;
      }
      if (j==m)
      {
         cout << "The pattern found at the index : " << i << endl;
         found = true;
      }
   }
   if(!found)
   {
      cout << "Pattern not found!\n";
   }
   return 0;
}