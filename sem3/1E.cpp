#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>


std::vector<std::vector<int>> E;
std::vector<std::vector<int>> Er;
std::vector<int> q;
std::vector<int> mark;
std::vector<int> cycle;
std::set<int> order;
std::vector<int> inDeg;
std::vector<int> cmpId;
std::vector<int> from;
std::vector<long long> time_in;
std::vector<long long> time_out;
long long timer = 1;

int invertColor(int color) {
    return color == 1 ? 2 : 1;
}

bool dfs(int v, int color) {
    mark[v] = color;
    for (int u: E[v]) {
        if (mark[u] == 0) {
            dfs(u, invertColor(color));
        } else if (mark[u] == color) {
            return false;
        }
    }
    return true;
}

int main() {

    int n, m;
    std::cin >> n >> m;
    E.resize(n);
    mark.assign(n, -1);
    q.resize(n);
    int u1, v1;
    for (int i = 0; i != m; ++i) {
        std::cin >> u1 >> v1;
        --u1;
        --v1;
        if (u1 != v1) {
            E[u1].emplace_back(v1);
            E[v1].emplace_back(u1);
        }
    }
    int flag = true;
    for (int i = 0; i != n; ++i) {
        if (mark[i] == -1) {
            int h = 0, t = 0;
            q[t++] = i;
            mark[i] = 0;
            while (h < t) {
                int v = q[h++];
                for (int u: E[v]) {
                    if (mark[u] == -1) {
                        mark[u] = !mark[v];
                        q[t++] = u;
                    } else {
                        flag &= mark[v] != mark[u];
                    }
                }
            }
        }
    }
    if (flag) {
        for (int i = 0; i < n; i++) {
            std::cout << mark[i] + 1<< " ";
        }
    } else {
        std::cout << "-1";
    }

    return 0;
}
 
