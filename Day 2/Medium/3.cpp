#include<bits/stdc++.h>
using namespace std;

int ContainerWithMaxWater(int arr[],int n){
    int left = 0;
    int right = n - 1;
    int maxArea = 0;

    while(left < right){
        int h = min(arr[left],arr[right]);
        int w = right - left;
        int area = h * w;
        maxArea = max(maxArea,area);
        if(arr[left] < arr[right])
        left ++;

        else{
            right --;
        }
        }
        return maxArea;
}

int main()
{
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max Water: " << ContainerWithMaxWater(arr,n);
}
