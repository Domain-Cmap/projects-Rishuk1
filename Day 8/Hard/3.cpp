#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;

    void buildGraph(const vector<vector<string>>& equations, const vector<double>& values) {
        for (int i = 0; i < equations.size(); ++i) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double value = values[i];
            graph[a][b] = value;
            graph[b][a] = 1.0 / value;
        }
    }

    double dfs(const string& start, const string& end, unordered_map<string, bool>& visited) {
        if (graph.find(start) == graph.end() || visited[start]) {
            return -1.0;
        }
        if (start == end) {
            return 1.0;
        }
        visited[start] = true;
        for (const auto& neighbor : graph[start]) {
            double result = dfs(neighbor.first, end, visited);
            if (result != -1.0) {
                return result * neighbor.second;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(const vector<vector<string>>& equations, const vector<double>& values, const vector<vector<string>>& queries) {
        buildGraph(equations, values);
        vector<double> result;
        for (const auto& query : queries) {
            unordered_map<string, bool> visited;
            result.p
