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

std::vector<std::vector<edge>> E;
std::vector<std::vector<int>> Er;
std::vector<int> dist;
std::vector<int> mark;
std::vector<int> cycle;
std::set<int> order;
std::vector<int> inDeg;
std::vector<int> cmpId;
std::vector<int> from;
std::vector<int> time_in;
std::vector<int> time_out;
int timer = 1;


void dfs(int v, int p = -1) {
    mark[v] = 1;
    time_in[v] = time_out[v] = timer++;

    int children = 0;
    for (edge edge: E[v]) {
        if (edge.u != p) {
            if (mark[edge.u] == 1) {
                time_out[v] = std::min(time_out[v], time_in[edge.u]);
            } else {
                dfs(edge.u, v);
                time_out[v] = std::min(time_out[v], time_out[edge.u]);
                if (time_out[edge.u] >= time_in[v] && p != -1) {
                    order.insert(v);
                }
                children++;
            }
        }
    }

    if (p == -1 && children > 1) {
        order.insert(v);
    }
}

int main() {

    int n, m;
    std::cin >> n >> m;
    E.resize(n);
    mark.assign(n, 0);
    time_in.resize(n);
    time_out.resize(n);
    int u1, v1;
    for (int i = 0; i != m; ++i) {
        std::cin >> u1 >> v1;
        --u1;
        --v1;
        E[u1].emplace_back(i, v1);
        E[v1].emplace_back(i, u1);
    }

    for (int i = 0; i != n; ++i) {
        if (!mark[i]) {
            dfs(i);
        }
    }
    std::cout << order.size() << "\n";
    for (int cutpoint: order) {
        std::cout << cutpoint + 1 << " ";
    }
    return 0;
}
 
