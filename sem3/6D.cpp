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
std::vector<std::vector<std::pair<int, int>>> E;
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


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    dist.resize(n, 1000000000);
    E.resize(n);
    dist[0] = 0;
    mark.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        std::cin >> v >> u >> w;
        v--;
        u--;
        E[v].emplace_back(u, w);
        E[u].emplace_back(v, w);
    }
    std::set<std::pair<int, int>> q;
    q.insert({0, dist[0]});
    while (!q.empty()) {
        std::pair<int, int> pair = (*q.begin());
        q.erase(q.begin());
        int v = pair.first;
        for (std::pair<int, int> pair_to: E[v]) {
            int u = pair_to.first;
            int w = pair_to.second;
            if (dist[u] > dist[v] + w) {
                q.erase({u, dist[u]});
                dist[u] = dist[v] + w;
                q.insert({u, dist[u]});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << dist[i] << " ";
    }
    return 0;
}
