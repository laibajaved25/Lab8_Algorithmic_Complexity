
#include <iostream>
#include <vector>
using namespace std;

// Function to find a peak element using binary search
void findPeak(vector<vector<int>>& arr) {

    int rows = arr.size();
    int cols = arr[0].size();

    int low = 0;
    int high = cols - 1;

    while (low <= high) {

        // Find middle column
        int mid = low + (high - low) / 2;

        // Find maximum element in middle column
        int maxRow = 0;

        for (int i = 1; i < rows; i++) {
            if (arr[i][mid] > arr[maxRow][mid]) {
                maxRow = i;
            }
        }

        int current = arr[maxRow][mid];

        // Check left neighbor
        int left = (mid > 0) ? arr[maxRow][mid - 1] : -1;

        // Check right neighbor
        int right = (mid < cols - 1)
                        ? arr[maxRow][mid + 1] : -1;

        // Check whether current element is a peak
        if (current >= left && current >= right) {

            cout << "Peak Element: " << current << endl;
            cout << "Position: Row " << maxRow
                 << ", Column " << mid << endl;

            return;
        }

        // Search left half
        else if (left > current) {
            high = mid - 1;
        }

        // Search right half
        else {
            low = mid + 1;
        }
    }
}

int main() {

    vector<vector<int>> arr = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    cout << "2D Peak Element Finder" << endl;

    findPeak(arr);

    return 0;
}

