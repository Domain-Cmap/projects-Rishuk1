#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);  // Update the minimum price seen so far
        maxProfit = max(maxProfit, price - minPrice);  // Calculate the potential profit
    }
    return maxProfit;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) cin >> prices[i];
    cout << maxProfit(prices) << endl;
    return 0;
}
