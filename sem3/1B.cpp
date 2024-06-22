#include <iostream>
#include <vector>


std::vector<std::vector<int>> E;
std::vector<bool> mark;
std::vector<int> comp;

void dfs(int v, int n) {
    mark[v] = true;
    comp.push_back(v + 1);
    for (int edge: E[v]) {
        if (!mark[edge]) {
            dfs(edge, n);
        }
    }
}

int main() {

    int n, m;
    std::cin >> n >> m;
    E.resize(n);
    mark.resize(n);
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            comp.clear();
            dfs(i, n);
            ans.push_back(comp);
            count+=1;
        }
    }
    std::cout << ans.size() << "\n";
    for (std::vector<int> companent: ans) {
        std::cout << companent.size() << "\n";
        for (int i = 0; i < companent.size(); i++) {
            std::cout << companent[i] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
