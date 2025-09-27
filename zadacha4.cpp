#include <iostream>
using namespace std;

int main() {
    int A, B;

    cout << "Enter number A (A > B): ";
    cin >> A;
    cout << "Enter number B: ";
    cin >> B;

    if (A <= B) {
        cout << "A must be greater than B!" << endl;
        return 0;
    }

    int steps = 0;
    while (A > B) {
        if (A % 2 == 0 && A / 2 >= B) {
            A /= 2;
        } else {
            A -= 1;
        }
        steps++;
    }

    cout << "Minimal number of operations: " << steps << endl;

    return 0;
}
