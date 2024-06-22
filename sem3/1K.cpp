#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>


std::vector<std::vector<int>> E;
std::vector<int> mark;
std::vector<int> order;
std::vector<int> inDeg;
int hasCycle = false;

void find_in_deg() {
    for (int i = 0; i < E.size(); i++) {
        for (int j = 0; j < E[i].size(); j++) {
            inDeg[E[i][j]]+=1;
        }
    }
}

int main() {

    int n, m;
    std::cin >> n >> m;
    E.resize(n);
    mark.resize(n, 0);
    inDeg.resize(n, 0);
    std::vector<int> input;
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        E[u].push_back(v);
    }

    find_in_deg();
    for (int i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        v--;
        input.push_back(v);
    }
    for (int v = 0; v < n; v++) {
        if (inDeg[input[v]] == 0) {
            for (int u: E[input[v]]) {
                inDeg[u]--;
            }
            continue;
        } else {
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES";


    return 0;
}
