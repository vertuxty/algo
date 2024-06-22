#include <iostream>
#include <vector>
#include "string"
#include "array"
#include "list"
#include "cmath"
#include "unordered_set"

int main() {

    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> logs(n + 1);
    logs[1] = 0;
    for (int i = 2; i < n + 1; i++)
    {
        logs[i] = logs[i / 2] + 1;
    }
    std::vector<std::vector<int>> sparseTableMin(logs[n] + 1);
    std::vector<std::vector<int>> sparseTableMax(logs[n] + 1);
    std::vector<int> a(n);
    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }

    for (int i = 0; i < logs[n] + 1; i++)
    {
        sparseTableMin[i] = std::vector<int> (n);
        sparseTableMax[i] = std::vector<int> (n);
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            if (i != 0)
            {
                sparseTableMin[i][j] = std::min(sparseTableMin[i - 1][j], sparseTableMin[i - 1][j + (1 << (i - 1))]);
            } else {
                sparseTableMin[0][j] = b[j];
            }
        }
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            if (i != 0)
            {
                sparseTableMax[i][j] = std::max(sparseTableMax[i - 1][j], sparseTableMax[i - 1][j + (1 << (i - 1))]);
            } else {
                sparseTableMax[0][j] = a[j];
            }
        }
    }

    int ansMax_l = 0;
    int ansMin_l = 0;
    int ansMax_r = 0;
    int ansMin_r = 0;
    long long count = 0;

    for (int i = 0; i < n; i++)
    {
        int l1 = i - 1;
        int l2 = i - 1;
        int r1 = n;
        int r2 = n;
        while (r1 - l1 > 1)
        {
            int mid = (l1 + r1)/2;
            int p_l = logs[mid - i + 1];
            ansMax_l = std::max(sparseTableMax[p_l][mid + 1 - (1 << p_l)], sparseTableMax[p_l][i]);
            ansMin_l = std::min(sparseTableMin[p_l][mid + 1 - (1 << p_l)], sparseTableMin[p_l][i]);
            if (ansMax_l <= ansMin_l) {
                l1 = mid;
            } else {
                r1 = mid;
            }
        }
        while (r2 - l2 > 1)
        {
            int mid = (l2 + r2)/2;
            int p_l = logs[mid - i + 1];
            ansMax_l = std::max(sparseTableMax[p_l][mid + 1 - (1 << p_l)], sparseTableMax[p_l][i]);
            ansMin_l = std::min(sparseTableMin[p_l][mid + 1 - (1 << p_l)], sparseTableMin[p_l][i]);
            if (ansMax_l < ansMin_l) {
                l2 = mid;
            } else {
                r2 = mid;
            }
        }
        count += l1 - l2;
    }
    std::cout << count;
    return 0;
}
