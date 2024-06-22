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
std::vector<std::vector<int>> dist;
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
    std::cin >> n;
    dist.resize(n, std::vector<int> (n, INT_MAX));
    mark.resize(n);
    E.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            std::cin >> tmp;
            dist[i][j] = tmp;
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

    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
    return 0;
}
