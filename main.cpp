#include <bits/stdc++.h>

using namespace std;

const int SZ = 3;

using Matr = vector<vector<int>>;

set<Matr> used;

void print_matrix(const Matr& matrix) {
    for (int i = 0; i < SZ; ++i) {
        for (int j = 0; j < SZ; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

vector<Matr> answer;

bool dfs(Matr& m) {
    used.insert(m);

    return false;
}

int main() {
    Matr result = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Matr input(SZ, vector<int>(SZ));
    cout << "Введите изначальное расположение пятнашек (вместо пустого места напишите 0):\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> input[i][j];
        }
    }
    map<Matr, int> dist;
    map<Matr, Matr> prev;
    queue<Matr> q;
    q.push(input);
    dist[input] = 0;
    while (!q.empty()) {
        Matr m = q.front();
        if (m == result) break;
        int zi, zj;
        for (int i = 0; i < SZ; ++i) {
            for (int j = 0; j < SZ; ++j) {
                if (m[i][j] == 0) {
                    zi = i;
                    zj = j;
                }
            }
        }
        if (zi > 0) {
            swap(m[zi][zj], m[zi - 1][zj]);
            if (!dist.contains(m)) {
                dist[m] = dist[q.front()] + 1;
                prev[m] = q.front();
                q.push(m);
            }
            swap(m[zi][zj], m[zi - 1][zj]);
        }
        if (zj > 0) {
            swap(m[zi][zj], m[zi][zj - 1]);
            if (!dist.contains(m)) {
                dist[m] = dist[q.front()] + 1;
                prev[m] = q.front();
                q.push(m);
            }
            swap(m[zi][zj], m[zi][zj - 1]);
        }
        if (zi < SZ - 1) {
            swap(m[zi][zj], m[zi + 1][zj]);
            if (!dist.contains(m)) {
                dist[m] = dist[q.front()] + 1;
                prev[m] = q.front();
                q.push(m);
            }
            swap(m[zi][zj], m[zi + 1][zj]);
        }
        if (zj < SZ - 1) {
            swap(m[zi][zj], m[zi][zj + 1]);
            if (!dist.contains(m)) {
                dist[m] = dist[q.front()] + 1;
                prev[m] = q.front();
                q.push(m);
            }
            swap(m[zi][zj], m[zi][zj + 1]);
        }
        q.pop();
    }
    if (!dist.contains(result)) {
        cout << "Нет решения\n";
        return 0;
    }
    vector<Matr> answer;
    for (Matr m = result; m != input; m = prev[m]) {
        answer.push_back(m);
    }
    answer.push_back(input);
    reverse(answer.begin(), answer.end());
    for (const Matr& m : answer) {
        print_matrix(m);
    }
}
