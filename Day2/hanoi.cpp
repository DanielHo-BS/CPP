/* Tower of Hanoi*/
#include <iostream>
using namespace std;

void move(char from, char to);
void towerOfHonoi(int n, char A, char B, char C, int &moves);

int main() {
    cout << "Enter the number of disks: ";
    int disks;
    cin >> disks;
    int moves = 0;
    towerOfHonoi(disks, 'A', 'B', 'C', moves);
    cout << "Total moves: " << moves << endl;

    return 0;
}

void move(char from, char to) {
    cout << "Move disk from " << from << " to " << to << endl;
}

void towerOfHonoi(int n, char A, char B, char C, int &moves) {
    if (n == 1){
        move(A, C);
        moves++;
    }
    else {
        towerOfHonoi(n-1, A, C, B, moves);
        move(A, C);
        moves++;
        towerOfHonoi(n-1, B, A, C, moves); 
    }
}