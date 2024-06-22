#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef struct edge {
    int index;
    int u;

    edge(int index, int u) : index(index), u(u) {}
} edge;

int n, m;
int s, to;
std::vector<std::vector<int>> E;
std::vector<std::vector<int>> Er;
std::vector<int> parent;
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

int print() {
    if (!mark[to]) {
        std::cout << "-1";
        return 0;
    } else {
        int ind = to;
        while (ind != -1) {
            path.push_back(ind);
            ind = parent[ind];
        }
        std::reverse(path.begin(), path.end());
        std::cout << path.size() - 1 << "\n";
        for (int v: path) {
            std::cout << v + 1 << " ";
        }
    }
}

int main() {
    std::cin >> n >> m;
    E.resize(n);
    mark.assign(n, 0);
    time_in.resize(n);
    time_out.resize(n);
    dist.resize(n, 0);
    parent.resize(n, -1);
    int u1, v1;
    for (int i = 0; i != m; ++i) {
        std::cin >> u1 >> v1;
        --u1;
        --v1;
        E[u1].emplace_back(v1);
    }
    std::cin >> s >> to;
    s--;
    to--;
    std::queue<int> q;
    mark[s] = 1;
    parent[s] = -1;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u: E[v]) {
            if (!mark[u]) {
                mark[u] = 1;
                q.push(u);
                dist[u] = dist[v] + 1;
                parent[u] = v;
            }
        }
    }
    print();
    return 0;
}
 
