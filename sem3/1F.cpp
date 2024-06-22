#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>


std::vector<std::vector<int>> E;
std::vector<int> mark;
std::vector<int> order;
std::vector<int> inDeg;
int hasCycle = false;

void find_in_deg() {
    for (int i = 0; i < E.size(); i++) {
        for (int j = 0; j < E[i].size(); j++) {
            inDeg[E[i][j]]+=1;
        }
    }
}

void dfs(int v, int n) {
    mark[v] = 1;
    for (int u: E[v]) {
        if (mark[u] == 0) {
            dfs(u, n);
        } else if (mark[u] == 1) {
            hasCycle = 1;
            return;
        }
    }
    order.push_back(v);
    mark[v] = 2;
}


int main() {

    int n, m;
    std::cin >> n >> m;
    E.resize(n);
    mark.resize(n, 0);
    inDeg.resize(n, 0);
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        E[u].push_back(v);
    }

    find_in_deg();

    std::queue<int> q;
    std::vector<int> res;

    for (int i = 0; i < n; i++) {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        res.push_back(v);
        for (int u: E[v]) {
            inDeg[u]-=1;
            if (inDeg[u] == 0) {
                q.push(u);
            }
        }
    }
    if (res.size() == n) {
        for (int v: res) {
            std::cout << v + 1 << " ";
        }
    } else {
        std::cout << -1;
    }


    return 0;
}
