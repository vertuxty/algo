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

    int n;
    std::cin >> n;
    E.resize(n);
    mark.resize(n, 0);
    inDeg.resize(n, 0);
    std::vector<std::vector<int>> ans;
    for (int v = 0; v < n; v++) {
        int k_v;
        std::cin >> k_v;
        for (int j = 0; j < k_v; j++) {
            int u;
            std::cin >> u;
            u--;
            E[v].push_back(u);
        }
    }

    find_in_deg();

    std::priority_queue<int> q;
    std::vector<int> res;

    for (int i = 0; i < n; i++) {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.top();
        q.pop();
        res.push_back(v);
        for (int u: E[v]) {
            inDeg[u]-=1;
            if (inDeg[u] == 0) {
                q.push(u);
            }
        }
    }


    std::reverse(res.begin(), res.end());
    if (res.size() == n) {
        for (int v: res) {
            std::cout << v + 1 << " ";
        }
    } else {
        std::cout << -1;
    }
    return 0;
}
