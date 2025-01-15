#include <bits/stdc++.h>
using namespace std;

int findMaxSi(vector<int> &A) {
    stack<int> st;
    int maxSi = 0;

    for (int i = 0; i < A.size(); ++i) {
        while (!st.empty() && st.top() > A[i]) {
            int M2 = st.top();
            st.pop();
            if (!st.empty()) {
                int M1 = st.top();
                int Si = (((M1 ^ M2) ^ (M1 | M2)) & (M1 ^ M2));
                maxSi = max(maxSi, Si);
            }
        }
        st.push(A[i]);
    }

    return maxSi;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << findMaxSi(A) << endl;
    return 0;
}
