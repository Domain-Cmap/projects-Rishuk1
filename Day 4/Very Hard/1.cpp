#include <bits/stdc++.h>
using namespace std;
 
void printNGE(int A[], int n)
{
    int arr[2 * n];
    for (int i = 0; i < 2 * n; i++)
        arr[i] = A[i % n];
    int next, i, j;
    for (i = 0; i < n; i++) {
        next = -1;
        for (j = i + 1; j < 2 * n; j++) {
            if (arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }
        cout << next << ", ";
    }
}
 
int main()
{
    int arr[] = { 1, 2, 1 };
    int N = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, N);
    return 0;
}