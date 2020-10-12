#include <iostream>

using namespace std;
void swap(int min_pos, int j, int v[])
{
    int aux;
    aux=v[min_pos];
    v[min_pos]=v[j];
    v[j]=aux;
}
int main()
{
    int n, v[100], min_pos+
    ;
    cout<<"Number of array's elements: ";
    cin>>n;
    cout<<endl<<"The elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int j=0;j<n-1;j++)
    {
        min_pos=j;
        for(int i=j+1;i<n;i++)
        {
           if(v[i]<v[min_pos])
                min_pos=i;
        }
        swap(min_pos, j, v);
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<"  ";
    return 0;
}
