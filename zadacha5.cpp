#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct State {
    int a, b;
    vector<string> actions;
};

int main() {
    int A, B, N;
    cout << "Enter capacity of jug A: ";
    cin >> A;
    cout << "Enter capacity of jug B: ";
    cin >> B;
    cout << "Enter desired amount N: ";
    cin >> N;

    if (N > A && N > B) {
        cout << "mission impossible 2" << endl;
        return 0;
    }

    queue<State> q;
    set<pair<int,int>> visited;

    q.push({0, 0, {}});
    visited.insert({0, 0});

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int a = current.a;
        int b = current.b;

        if (a == N || b == N) {
            for (const string &act : current.actions)
                cout << act << endl;
            return 0;
        }

        vector<pair<State, string>> nextStates;

        nextStates.push_back({{A, b, current.actions}, ">A"});
        nextStates.push_back({{a, B, current.actions}, ">B"});
        nextStates.push_back({{0, b, current.actions}, "A>"});
        nextStates.push_back({{a, 0, current.actions}, "B>"});
        int pourAB = min(a, B - b);
        nextStates.push_back({{a - pourAB, b + pourAB, current.actions}, "A>B"});
        int pourBA = min(b, A - a);
        nextStates.push_back({{a + pourBA, b - pourBA, current.actions}, "B>A"});

        for (auto &ns : nextStates) {
            if (visited.find({ns.first.a, ns.first.b}) == visited.end()) {
                ns.first.actions.push_back(ns.second);
                visited.insert({ns.first.a, ns.first.b});
                q.push(ns.first);
            }
        }
    }

    cout << "mission impossible 2" << endl;
    return 0;
}
