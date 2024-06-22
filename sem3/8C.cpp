#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int n, m;
int s, to;
std::vector<std::vector<int>> E;
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

int main() {
    std::string S, T;
    std::cin >> S;
    std::cin >> T;
    std::string str = T + '#' + S;
    n = str.size();
    p.resize(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && str[i] != str[j]) {
            j = p[j - 1];
        }
        if (str[i] == str[j]) {
            p[i] = j + 1;
        } else {
            p[i] = j;
        }
    }
    for (int i = 0; i < S.size(); i++) {
        if (p[T.size() + i + 1] == T.size()) {
            dist.push_back(i - T.size() + 1);
        }
    }
    for (int pref: dist) {
        std::cout << pref << " ";
    }
    return 0;
}
