//Remove Element

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements: ";
    for(i=0; i<n; i++)
    cin>>a[i];

    set<int> st ;
    for(i=0; i<n; i++)
    st.insert(a[i]);

    cout<<st.size();

    return 0;
}