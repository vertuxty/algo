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

int n, m, k;
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

void smt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //            if (i == j) {
            int tmp = 0;
            std::cin >> tmp;
            dist[i][j] = tmp;
            //            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != 100000 && dist[k][j] != 100000) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void getData(int& j, int& v, int& u, long long& w) {
    v = Er[j].v;
    u = Er[j].u;
    w = Er[j].w;
}

void kPaths() {
    int v = 0, u = 0;
    long long w = 0;
    dist[0][s] = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            getData(j, v, u, w);
            if (dist[i][v] < LONG_LONG_MAX) {
                dist[i + 1][u] = std::min(dist[i + 1][u], dist[i][v] + w);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> k >> s;
    s--;
    dist.resize(k + 1, std::vector<long long> (n, LONG_LONG_MAX));
    mark.resize(n);
    E.resize(n);
    int v, u;
    long long w;

    for (int i = 0; i < m; i++) {
        std::cin >> v >> u >> w;
        v--;
        u--;
        Er.emplace_back(v, u, w);
    }
    dist[0][s] = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            getData(j, v, u, w);
            if (dist[i][v] < LONG_LONG_MAX) {
                dist[i + 1][u] = std::min(dist[i + 1][u], dist[i][v] + w);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        if (dist[k][i] == LONG_LONG_MAX) {
            std::cout << "-1\n";
        } else {
            std::cout << dist[k][i] << "\n";
        }
    }
    return 0;
}
