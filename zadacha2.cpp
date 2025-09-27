#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double S, V0, a;
    
    cout << "Enter distance S: ";
    cin >> S;
    cout << "Enter initial speed V0: ";
    cin >> V0;
    cout << "Enter acceleration a: ";
    cin >> a;
    
    double A = a / 2.0;
    double B = V0;
    double C = -S;
    
    double discriminant = B*B - 4*A*C;
    
    if (discriminant < 0) {
        cout << "No solutions (discriminant < 0)" << endl;
    } else {
        double t1 = (-B + sqrt(discriminant)) / (2*A);
        double t2 = (-B - sqrt(discriminant)) / (2*A);
        
        double t;
        if (t1 > 0 && t2 > 0) t = min(t1, t2);
        else if (t1 > 0) t = t1;
        else if (t2 > 0) t = t2;
        else {
            cout << "No positive solution for time" << endl;
            return 0;
        }
        
        cout << "Time t = " << t << " seconds" << endl;
    }

    return 0;
}
