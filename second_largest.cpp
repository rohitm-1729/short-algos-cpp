#include<iostream>
using namespace std;
int main()

{
    int n,i,big,sbig;
    cin>>n;int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];

    if(a[0]>=a[1])
    {
        big=a[0];
        sbig=a[i];
    }
    else
    {
        big=a[1];
        sbig=a[0];
    }

    for(i=2;i<n;i++)
    {
        if(a[i]>big)
        {
            sbig=big;
            big=a[i];
        }
        else if(a[i]>sbig)
        {
            sbig=a[i];
        }
    }
    cout<<"Second largest is "<<sbig<<endl;
    return 0;
}
