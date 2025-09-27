#include <iostream>
using namespace std;

int main() {
    double x, y;

    cout << "Enter power of first person (x): ";
    cin >> x;

    cout << "Enter power of second person (y): ";
    cin >> y;

    if (x > y) {
        cout << "Winner: X" << endl;
    } else {
        cout << "Winner: Y" << endl;
    }

    return 0;
}