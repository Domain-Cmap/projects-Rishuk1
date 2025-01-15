#include <bits/stdc++.h>
using namespace std;

int majorityelm(vector<int> arr) {
    int count = 0;
    int elm = -1;  // Default value for element
    int n = arr.size();

    // Step 1: Find a candidate for majority
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            elm = arr[i];
            count = 1;
        } else if (elm == arr[i]) {
            count++;
        } else {
            count--;
        }
    }

    // Step 2: Verify if the candidate is a majority element
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == elm) {
            count++;
        }
    }

    if (count > n / 2) {
        return elm;
    }
    
    return -1;
}

int main() {
    int a;
    vector<int> v;
    while (cin >> a) { 
        v.push_back(a);
    }

    if (v.empty()) {
        cout << "No elements provided!" << endl;
        return 0;
    }

    int elm = majorityelm(v);
    if (elm != -1) {
        cout << "Majority element: " << elm << endl;
    } else {
        cout << "No majority element found!" << endl;
    }

    return 0;
}