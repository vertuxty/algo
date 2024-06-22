#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>


std::vector<std::vector<int>> E;
std::vector<std::vector<int>> Er;
std::vector<int> mark;
std::vector<int> order;
std::vector<int> inDeg;
std::vector<int> cmpId;
int hasCycle = false;

void find_in_deg() {
    for (int i = 0; i < E.size(); i++) {
        for (int j = 0; j < E[i].size(); j++) {
            inDeg[E[i][j]]+=1;
        }
    }
}

void dfs(int v, int cmp) {
    cmpId[v] = cmp;
    mark[v] = true;
    for (int u: Er[v]) {
        if (!mark[u]) {
            dfs(u, cmp);
        }
    }
}

void fakeTopSort(int v) {
    mark[v] = 1;
    for (int u: E[v]) {
        if (!mark[u]) {
            fakeTopSort(u);
        }
    }
    order.push_back(v);
}

int main() {

    int n, m;
    std::cin >> n >> m;
    E.resize(n);
    Er.resize(n);
    mark.resize(n, 0);
    inDeg.resize(n, 0);
    cmpId.resize(n, -1);
    std::vector<int> input;
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        E[u].push_back(v);
        Er[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            fakeTopSort(i);
        }
    }
    std::reverse(order.begin(), order.end());
    mark.clear();
    mark.resize(n, 0);
    int cmp = 0;

    for (int v: order) {
        if (!mark[v]) {
            cmp++;
            dfs(v, cmp);
        }
    }
    std::cout << cmp << "\n";
    for (int v = 0; v < n; v++) {
        std::cout << cmpId[v] << " ";
    }
    return 0;
}
