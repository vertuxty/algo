#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>


std::vector<std::vector<int>> E;
std::vector<std::vector<int>> Er;
std::vector<int> dist;
std::vector<int> mark;
std::vector<int> cycle;
std::vector<int> order;
std::vector<int> inDeg;
std::vector<int> cmpId;
std::vector<int> from;
int cycle_st = -1;
int cycle_end = -1;

int invertColor(int color) {
    return color == 1 ? 2 : 1;
}

bool dfs(int v, int n) {
    mark[v] = 1;
    for (int u: E[v]) {
        if (mark[u] == 0) {
            from[u] = v;
            if (dfs(u, n))
            {
                return true;
            }
        } else if (mark[u] == 1) {
            cycle_st = u;
            cycle_end = v;
            return true;
        }
    }
    mark[v] = 2;
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    E.resize(n, std::vector<int> (0));
    mark.resize(n, 0);
    std::string query;
    from.resize(n);
    for (int i = 0; i != n - 1; ++i) {
        std::cin >> query;
        for (int j = 0; j < query.size(); j++) {
            if (query[j] == 'R') {
                E[j + i + 1].emplace_back(i);
            } else {
                E[i].emplace_back(j + i + 1);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        if (dfs(i, n)) {
            break;
        }
    }
    if (cycle_st == -1) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}
