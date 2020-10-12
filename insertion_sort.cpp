#include <iostream>

using namespace std;

int main()
{
    int n, v[100], element, i, j;
    cout<<"Number of elements: ";
    cin>>n;
    cout<<endl<<"Elements: ";
    for(i=0;i<n;i++)
        cin>>v[i];
    for(i=1;i<n;i++)//from the second element to the last one  
       {
           element=v[i];//retain elem(2->last) 
           j=i-1;
           while(j>=0&&v[j]>element)
           {
               v[j+1]=v[j];
               j--;
           }
           v[j+1]=element;//put the element where it has to be 
       }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<"  ";
    return 0;
}
