#include <iostream>

using namespace std;

int main()
{
    int n, v[100], sorted;
    cout<<"Number of elements:  ";
    cin>>n;
    cout<<"Elements:  ";
    for(int i=0;i<n;i++)
        cin>>v[i];
    do
    {
        sorted=1;
        for(int i=0;i<n;i++)
        {
            if(v[i]>v[i+1])
            {
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                sorted=0;
            }
        }
    }while(sorted==0);
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<"   ";
    return 0;
}
