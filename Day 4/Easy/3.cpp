class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int len = students.size(); 
        queue<int> studentQueue;
        stack<int> sandwichStack;
        
        for (int i = 0; i < len; i++) {
            sandwichStack.push(sandwiches[len - i - 1]);
            studentQueue.push(students[i]);
        }

        int lastServed = 0;
        while (!studentQueue.empty() && lastServed < studentQueue.size()) {
            if (sandwichStack.top() == studentQueue.front()) {
                sandwichStack.pop(); 
                studentQueue.pop();
                lastServed = 0;
            } else {
                studentQueue.push(studentQueue.front()); 
                studentQueue.pop();
                lastServed++;
            }
        }

        return studentQueue.size();    
    }
};