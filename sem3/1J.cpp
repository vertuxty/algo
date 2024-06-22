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
std::vector<int> tim;
int cycle_st = -1;
int cycle_end = -1;
long long totalTime = 0;


int invertColor(int color) {
    return color == 1 ? 2 : 1;
}

void dfs(int v) {
    if (mark[v]) {
        return;
    }
    for (int u: E[v]) {
        dfs(u);
    }
    order.push_back(v);
    totalTime += tim[v];
    mark[v] = 1;
}

int main() {

    int n;
    std::cin >> n;
    tim.resize(n);
    E.resize(n);
    mark.resize(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> tim[i];
    }
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int u;
            std::cin >> u;
            u--;
            E[i].push_back(u);
        }
    }
    dfs(0);
    std::cout << totalTime << " " << order.size() << "\n";
    for (int v: order) {
        std::cout << v + 1 << " ";
    }
    return 0;
}
 
