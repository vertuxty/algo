#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>


std::vector<std::vector<std::pair<int, int>>> E;
std::vector<std::vector<int>> Er;
std::vector<int> dist;
std::vector<int> mark;
std::vector<int> order;
std::vector<int> inDeg;
std::vector<int> cmpId;
int hasCycle = false;

void dfs(int v) {
    mark[v] = 1;
    for (std::pair<int, int> pair: E[v]) {
        if (!mark[pair.first]) {
            dfs(pair.first);
        }
        dist[v] = std::min(dist[v], dist[pair.first] + pair.second);
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
    for (std::pair<int, int> u: E[v]) {
        if (!mark[u.first]) {
            fakeTopSort(u.first);
        }
    }
    order.push_back(v);
}

int main() {

    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    s--;
    t--;
    E.resize(n);
    Er.resize(n);
    mark.resize(n, 0);
    inDeg.resize(n, 0);
    cmpId.resize(n, -1);
    dist.assign(n, INT_MAX - 100000);
    dist[s] = 0;
    std::vector<int> input;
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < m; i++) {
        int u, v, len;
        std::cin >> u >> v >> len;
        u--;
        v--;
        E[v].emplace_back(u, len);
    }
    dfs(t);
    if (!mark[s]) {
        std::cout << "Unreachable";
    } else {
        std::cout << dist[t];
    }
    return 0;
}
 
