#include <iostream>
using namespace std;

string toRoman(int num) {
    string roman = "";

    string symbols[] = {"C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[]    = {100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i = 0; i < 9; i++) {
        while (num >= values[i]) {
            roman += symbols[i];
            num -= values[i];
        }
    }
    
    return roman;
}

int main() {
    int number;
    
    cout << "Enter a number (1-999): ";
    cin >> number;
    
    if (number <= 0 || number >= 1000) {
        cout << "Number out of range!" << endl;
    } else {
        cout << "Roman numeral: " << toRoman(number) << endl;
    }

    return 0;
}
