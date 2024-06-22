#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct edge {
    int index;
    int u;

    edge(int index, int u) {
        this->index = index;
        this->u = u;
    }
};

std::vector<std::vector<edge>> E;
std::vector<std::vector<int>> Er;
std::vector<int> dist;
std::vector<int> mark;
std::vector<int> cycle;
std::vector<int> order;
std::vector<int> inDeg;
std::vector<int> cmpId;
std::vector<int> from;
std::vector<int> timeIn;
std::vector<int> timeOut;
int timer = 1;
int cycle_st = -1;
int cycle_end = -1;

void dfs(int v, int p, int n) {
    mark[v] = 1;
    timeIn[v] = timer + 1;
    timeOut[v] = timer + 1;
    ++timer;
    for (edge edge: E[v]) {
        int u = edge.u;
        if (!mark[u]) {
            dfs(u, edge.index, n);
        }
        if (edge.index != p) {
            timeOut[v] = std::min(timeOut[v], timeOut[u]);
        }
    }
    if (timeOut[v] == timeIn[v] && p != -1) {
        order.push_back(p);
    }
}


int main() {

    int n, m;
    std::cin >> n >> m;
    E.resize(n);
    Er.resize(n);
    mark.resize(n, 0);
    timeIn.resize(n, -1);
    timeOut.resize(n, -1);
    std::vector<int> input;
    cycle_st = -1;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        E[u].emplace_back(i, v);
        E[v].emplace_back(i, u);
    }

    timer = 1;
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            dfs(i, -1, n);
        }
    }
    std::sort(order.begin(), order.end());
    std::cout << order.size() << "\n";
    for (int bride: order) {
        std::cout << bride + 1 << " ";
    }
    return 0;
}
