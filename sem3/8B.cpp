#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

int n, m;
int s, to;

std::vector<int> N;

std::vector<int> mark;
std::vector<int> path;

int timer = 1;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string str;
    std::cin >> str;
    n = str.size();
    N.resize(n, 0);
    N[0] = n;
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            N[i] = std::min(r - i + 1, N[i - l]);
        }
        while (i + N[i] < n && str[N[i]] == str[i + N[i]]) {
            N[i]++;
        }
        if (i + N[i] - 1 > r) {
            l = i;
            r = i + N[i] - 1;
        }
    }
    for (int func: N) {
        std::cout << func << " ";
    }
    return 0;
}
 
