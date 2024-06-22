#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>


std::vector<std::vector<int>> E;
std::vector<std::vector<int>> Er;
std::vector<int> dist;
std::vector<int> mark;
std::vector<int> cycle;
std::vector<int> order;
std::vector<int> inDeg;
std::vector<int> cmpId;
std::vector<int> from;
int hasCycle = false;
int flag = 0;
int cycle_st = -1;
int cycle_end = -1;
bool dfs(int v, int n) {
    mark[v] = 1;
    for (int u: E[v]) {
        if (mark[u] == 0) {
            from[u] = v;
            if (dfs(u, n))
            {
                return true;
            }
        } else if (mark[u] == 1) {
            cycle_st = u;
            cycle_end = v;
            return true;
        }
    }
    mark[v] = 2;
    return false;
}
int main() {

    int n, m;
    std::cin >> n >> m;
    E.resize(n);
    Er.resize(n);
    mark.resize(n, 0);
    inDeg.resize(n, 0);
    cmpId.resize(n, -1);
    dist.assign(n, INT_MAX - 100000);
    from.resize(n, -1);
    std::vector<int> input;
    cycle_st = -1;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        E[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (dfs(i, n)) {
            break;
        }
    }
    if (cycle_st == -1) {
        std::cout << -1;
    } else {
        cycle.push_back(cycle_st);
        for (int i = cycle_end; i != cycle_st; i=from[i]) {
            cycle.push_back(i);
        }
        std::reverse(cycle.begin(), cycle.end());
        std::cout << cycle.size() << "\n";
        for (int i = 0; i < cycle.size(); i++) {
            std::cout << cycle[i] + 1 << " ";
        }
    }
    return 0;
}
 
