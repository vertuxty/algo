#include <iostream>
#include <vector>


std::vector<std::vector<int>> E;
std::vector<bool> mark;

void dfs(int v, int n) {
    mark[v] = true;
    for (int edge: E[v]) {
        if (!mark[edge]) {
            dfs(edge, n);
            std::cout << (v + 1) << " " << (edge + 1) << "\n";
        }
    }
}

int main() {

    int n, m;
    std::cin >> n >> m;
    E.resize(n);
    mark.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    dfs(0, n);

    return 0;
}
