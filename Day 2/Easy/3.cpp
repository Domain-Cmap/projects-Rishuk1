#include<iostream>
#include<vector>

using namespace std;

int calculatepoints(vector<string>& operations){
    vector<int> scores;
    int total = 0;

    for(string operation : operations){
        if(operation == "C"){
            total -= scores.back();
            scores.pop_back();
        }
        else if(operation == "D"){
            int doubled = scores.back() * 2;
            scores.push_back(doubled);
            total += doubled;
        }
        else if(operation == "+"){
            int sum = scores[scores.size() - 1] + scores[scores.size() - 2];
            scores.push_back(sum);
            total += sum;
        }
        else{
            int num = stoi(operation);
            scores.push_back(num);
            total += num;
        }
    }
    return total;
}

int main() {
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    vector<string> operations(n);
    cout << "Enter the operations: \n";
    for (int i = 0; i < n; ++i) {
        cin >> operations[i];
    }

    int total = calculatepoints(operations);
    cout << "Total Score: " << total << endl;

    return 0;
}