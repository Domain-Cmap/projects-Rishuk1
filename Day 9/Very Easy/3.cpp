#include <iostream>
#include <string>
using namespace std;

int maxRepeating(string sequence, string word) {
    int maxK = 0;
    int wordLen = word.length();
    int seqLen = sequence.length();
    
    while (sequence.find(word) != string::npos) {
        maxK++;
        sequence.replace(sequence.find(word), wordLen, "");
    }
    return maxK;
}

int main() {
    string sequence, word;
    cin >> sequence >> word;
    cout << maxRepeating(sequence, word) << endl;
    return 0;
}
