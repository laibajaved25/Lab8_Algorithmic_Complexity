
#include <iostream>
#include <stack>
using namespace std;

// Perform one legal move between two pegs
void moveDisk(stack<int>& source,
              stack<int>& destination,
              char sourceName,
              char destinationName) {

    // Source is empty
    if (source.empty()) {

        int disk = destination.top();
        destination.pop();

        source.push(disk);

        cout << "Move disk " << disk
             << " from " << destinationName
             << " to " << sourceName << endl;
    }

    // Destination is empty
    else if (destination.empty()) {

        int disk = source.top();
        source.pop();

        destination.push(disk);

        cout << "Move disk " << disk
             << " from " << sourceName
             << " to " << destinationName << endl;
    }

    // Move smaller disk onto larger disk
    else if (source.top() < destination.top()) {

        int disk = source.top();
        source.pop();

        destination.push(disk);

        cout << "Move disk " << disk
             << " from " << sourceName
             << " to " << destinationName << endl;
    }

    else {

        int disk = destination.top();
        destination.pop();

        source.push(disk);

        cout << "Move disk " << disk
             << " from " << destinationName
             << " to " << sourceName << endl;
    }
}

// Iterative Tower of Hanoi
void towerOfHanoi(int N) {

    stack<int> source, auxiliary, destination;

    char sourceName = 'A';
    char auxiliaryName = 'B';
    char destinationName = 'C';

    // Place disks on source peg
    for (int i = N; i >= 1; i--) {
        source.push(i);
    }

    int totalMoves = (1 << N) - 1;

    // For even number of disks, swap auxiliary
    // and destination roles
    if (N % 2 == 0) {
        swap(auxiliaryName, destinationName);
    }

    cout << "Tower of Hanoi with "
         << N << " disks\n\n";

    // Repeat legal moves iteratively
    for (int i = 1; i <= totalMoves; i++) {

        if (i % 3 == 1) {

            moveDisk(source, destination,
                     sourceName, destinationName);
        }

        else if (i % 3 == 2) {

            moveDisk(source, auxiliary,
                     sourceName, auxiliaryName);
        }

        else {

            moveDisk(auxiliary, destination,
                     auxiliaryName, destinationName);
        }
    }

    cout << "\nTotal Moves: " << totalMoves << endl;
}

int main() {

    int N;

    cout << "Enter number of disks: ";
    cin >> N;

    if (N <= 0 || N > 20) {
        cout << "Please enter a number between 1 and 20."
             << endl;
        return 1;
    }

    towerOfHanoi(N);

    return 0;
}

