#include <iostream>
#include <vector>
using namespace std;

void floodFillHelper(vector<vector<int>>& image, int sr, int sc, int color, int originalColor) {
    // Base cases to check the boundaries of the image
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
    if (image[sr][sc] != originalColor) return;

    // Change the color of the current pixel
    image[sr][sc] = color;

    // Recursively apply flood fill on the 4 neighboring cells
    floodFillHelper(image, sr + 1, sc, color, originalColor);  // Down
    floodFillHelper(image, sr - 1, sc, color, originalColor);  // Up
    floodFillHelper(image, sr, sc + 1, color, originalColor);  // Right
    floodFillHelper(image, sr, sc - 1, color, originalColor);  // Left
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int originalColor = image[sr][sc];
    if (originalColor != color) {
        floodFillHelper(image, sr, sc, color, originalColor);
    }
    return image;
}

int main() {
    int m, n, sr, sc, color;
    cout << "Enter the number of rows and columns of the image: ";
    cin >> m >> n;

    vector<vector<int>> image(m, vector<int>(n));
    cout << "Enter the image pixels:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> image[i][j];
        }
    }

    cout << "Enter the starting row, column, and color: ";
    cin >> sr >> sc >> color;

    vector<vector<int>> result = floodFill(image, sr, sc, color);

    cout << "Modified image:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
