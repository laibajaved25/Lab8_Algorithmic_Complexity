
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class KnightTour {

private:
    int N;

    vector<vector<int>> board;

    // All 8 possible knight moves
    int dx[8] = {
        -2, -1, 1, 2, 2, 1, -1, -2
    };

    int dy[8] = {
        1, 2, 2, 1, -1, -2, -2, -1
    };

    // Check if a square is valid and unvisited
    bool isSafe(int x, int y) {

        return x >= 0 && x < N &&
               y >= 0 && y < N &&
               board[x][y] == -1;
    }

    // Count available onward moves
    int countMoves(int x, int y) {

        int count = 0;

        for (int i = 0; i < 8; i++) {

            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (isSafe(nextX, nextY)) {
                count++;
            }
        }

        return count;
    }

    // Recursive backtracking
    bool solve(int x, int y, int moveNumber) {

        // All squares visited
        if (moveNumber == N * N) {
            return true;
        }

        vector<pair<int, pair<int, int>>> moves;

        // Generate valid next moves
        for (int i = 0; i < 8; i++) {

            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (isSafe(nextX, nextY)) {

                int degree = countMoves(nextX, nextY);

                moves.push_back({
                    degree, {nextX, nextY}
                });
            }
        }

        // Warnsdorff: try smallest onward degree first
        sort(moves.begin(), moves.end());

        for (auto move : moves) {

            int nextX = move.second.first;
            int nextY = move.second.second;

            board[nextX][nextY] = moveNumber;

            if (solve(nextX, nextY, moveNumber + 1)) {
                return true;
            }

            // Backtrack
            board[nextX][nextY] = -1;
        }

        return false;
    }

public:

    KnightTour(int size) {

        N = size;

        board.assign(N, vector<int>(N, -1));
    }

    void startTour(int startX, int startY) {

        if (startX < 0 || startX >= N ||
            startY < 0 || startY >= N) {

            cout << "Invalid starting position!" << endl;
            return;
        }

        board[startX][startY] = 0;

        if (solve(startX, startY, 1)) {

            cout << "\nKnight's Tour Solution:\n\n";

            for (int i = 0; i < N; i++) {

                for (int j = 0; j < N; j++) {

                    cout << board[i][j] << "\t";
                }

                cout << endl;
            }
        }
        else {

            cout << "No tour found from this position."
                 << endl;
        }
    }
};

int main() {

    int N = 8;

    KnightTour knight(N);

    // Starting position: row 0, column 0
    knight.startTour(0, 0);

    return 0;
}


