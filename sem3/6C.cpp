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
std::vector<edge> E;
std::vector<std::vector<int>> Er;
std::vector<int> p;
std::vector<int> dist;
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

void dfs(int i) {
    mark[i] = 1;
    for (int u: Er[i]) {
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
    dist.resize(n, 30000);
    Er.resize(n);
    mark.resize(n);
    int v, u, w;
    for (int i = 0; i < m; i++) {
        std::cin >> v >> u >> w;
        v--;
        u--;
        E.emplace_back(v, u, w);
        Er[v].push_back(u);
    }
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int first = E[j].v;
            int second = E[j].u;
            int cost = E[j].w;
            dist[second] = std::min(dist[second], dist[first] + cost);
        }
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (mark[i]) {
            std::cout << dist[i] << " ";
        } else {
            std::cout << 30000 << " ";
        }
    }
    return 0;
}
