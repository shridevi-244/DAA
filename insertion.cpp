#include <iostream>
using namespace std;

int main()
{
    int n, i, j, v;
    cout<< "------------------------------\n";
    cout << "ENTER NUMBER OF ELEMENTS: ";
    cin >> n;
    if (n==0)
    {
       cout<<"\nARRAY SHOULD HAVE ATLEAST ONE ELEMENT\n\n";
       cout<<"------------------------------\n";
       return 0;
    }
    if (n<0)
    {
       cout<<"\nARRAY SIZE CAN'T BE NEGATIVE\n\n";
       cout<<"------------------------------\n";
       return 0;
    }

    int A[n];

    cout << "ENTER ELEMENTS:\n";
    for(i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for(i = 1; i < n; i++)
    {
        v = A[i];
        j = i - 1;

        while(j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = v;
    }

    cout << "SORTED ARRAY:\n------------\n";
    for(i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout<<"\n------------------------------\n";
    return 0;
}
