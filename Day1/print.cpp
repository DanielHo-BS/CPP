/* print.cpp */
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int i, j ,k, f;
    for (i = 1; i <=4; i++){
        for (j = 1; j<= 30; j++)
            cout << " ";
        for (k = 1; k <= 8 - 2*i; k++)
        for (f = 1; f <= 2*i - 1; f++)
            cout << "*";
        cout << endl;
    }

    for (i = 1; i <= 3; i++){
        for (j = 1; j <= 30; j++)
            cout << " ";
        for (k = 1; k <= 7 - 2*i; k++)
        for (f = 1; f <= 2*i - 1; f++)
            cout << "*";
        cout << endl;
    }

    return 0;
}