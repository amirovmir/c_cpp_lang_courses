#include <iostream>
#include <stack>
#include <string>
#include <conio.h>
#include <sstream>

using namespace std;

class Graph {
private:
    int numTop;
    bool** links;
    stack <int> lastTop;
    stack <int> stk;

public:
    Graph() {
        cin >> numTop;
        cin.ignore(256, '\n');
        links = new bool* [numTop];
        for (int i = 0; i < numTop; i++) {
            links[i] = new bool[numTop];
        }

        string line, dir;
        for (int i = 0; i < numTop; i++) {
            cout << i + 1 << ": ";
            getline(cin, line);
            stringstream ss(line);
            while (getline(ss, dir, ' ')) {
                if (dir != "0")
                    this->links[i][stoi(dir) - 1] = 1;
            }
        }
        cout << endl;
    }

    ~Graph() {
        for (int i = 0; i < numTop; i++)
            delete[] *links;
        delete[] links;
    }

    void dfs(int ver) {
        for (int j = 0; j < numTop; j++) {
            if (lastTop.empty()) {
                if (links[ver][j] == 1) {
                    stk.push(j);
                    lastTop.push(ver);
                    dfs(j);
                    lastTop.pop();
                }
            }
            else {
                if (links[ver][j] == 1 && j != lastTop.top()) {
                    stk.push(j);
                    lastTop.push(ver);
                    dfs(j);
                    lastTop.pop();
                }
            }
        }
    }

    void dfsFill() {
        for (int i = 0; i < numTop; i++) {
            dfs(i);
            while (stk.size()) {
                links[i][stk.top()] = 1;
                stk.pop();
            }
        }
    }

    void print() {
        for (int i = 0; i < numTop; i++) {
            links[i][i] = 1;
            for (int j = 0; j < numTop; j++) {
                cout << links[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph;
    graph.dfsFill();
    graph.print();
    _getch();
    return 0;
}
