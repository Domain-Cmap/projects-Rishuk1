#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> inDegree(numCourses, 0);
    vector<vector<int>> graph(numCourses);
    vector<int> order;

    for (const auto& prereq : prerequisites) {
        int course = prereq[0], prerequisite = prereq[1];
        graph[prerequisite].push_back(course);
        inDegree[course]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);
        for (int neighbor : graph[course]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return order.size() == numCourses ? order : vector<int>();
}

int main() {
    int numCourses;
    cin >> numCourses;

    int numPrerequisites;
    cin >> numPrerequisites;

    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    for (int i = 0; i < numPrerequisites; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    vector<int> result = findOrder(numCourses, prerequisites);
    if (result.empty()) {
        cout << "It is impossible to finish all courses.\n";
    } else {
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
