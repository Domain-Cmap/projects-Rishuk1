#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int elm = -1;
    int count = 0;
    for(int i=0;i<n;i++){
        if(count==0){
            count = 1;
            elm = arr[i];
        }
        else{
            if(arr[i]==elm){
                count = 0;
            }
        }
    }
    if(count==1){
        cout << elm << endl;
    }
    

    return 0;
}