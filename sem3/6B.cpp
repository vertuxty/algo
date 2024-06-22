#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef struct edge {
    int v;
    int u;
    int w;

    edge(int vertex_from, int vertex_to, int weight) : v(vertex_from), u(vertex_to), w(weight) {}
} edge;

int n, m;
int s, to;
std::vector<edge> Er;
std::vector<std::vector<int>> E;
std::vector<int> p;
std::vector<std::vector<long long>> dist;
std::vector<int> mark;
std::vector<int> path;
std::vector<int> cycle;
std::set<int> order;
std::vector<int> inDeg;
std::vector<int> cmpId;
std::vector<int> from;
std::vector<int> time_in;
std::vector<int> time_out;
int timer = 1;

int print() {
    if (!mark[to]) {
        std::cout << "-1";
        return 0;
    } else {
        int ind = to;
        while (ind != -1) {
            path.push_back(ind);
            ind = p[ind];
        }
        std::reverse(path.begin(), path.end());
        std::cout << path.size() - 1 << "\n";
        for (int v: path) {
            std::cout << v + 1 << " ";
        }
    }
}

void dfs(int i) {
    mark[i] = 1;
    for (int u: E[i]) {
        if (!mark[u]) {
            mark[u] = 1;
            dfs(u);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    dist.resize(n, std::vector<long long> (n, INT_MAX));
    mark.resize(n);
    E.resize(n);
    int v, u;
    long long w;

    for (int i = 0; i < m; i++) {
        std::cin >> v >> u >> w;
        v--;
        u--;
        if (dist[v][u] != INT_MAX) {
            dist[v][u] = std::min(dist[v][u], w);
        } else {
            dist[v][u] = w;
        }
        E[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][i] = 0;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] != INT_MAX ) {
                std::cout << dist[i][j] << " ";
            } else {
                std::cout << 30000 << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
