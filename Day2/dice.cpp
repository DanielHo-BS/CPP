/* Dice */
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int rolldice();

int main() {
    int flag = 0;
    time_t seed;
    srand((unsigned) time(&seed));
    int sum = rolldice();
    int selfdice = 0;
    while(flag == 0){
        if(sum == 7 || sum == 11){
            cout << "You win!" << endl;
            flag = 1;
        }
        else if(sum == 2 || sum == 3 || sum == 12){
            cout << "You lose!" << endl;
            flag = 1;
        }
        else{
            selfdice = rolldice();
            if(selfdice == sum){
                cout << "You win!" << endl;
                flag = 1;
            }
            else if(selfdice == 7){
                cout << "You lose!" << endl;
                flag = 1;
            }
        }
    }

    return 0;

}

int rolldice() {
    int sum = 0;
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    sum = dice1 + dice2;
    cout << "You rolled " << dice1 << " + " << dice2 << " = " << sum << endl;
    return sum;
}