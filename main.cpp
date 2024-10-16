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
    int current = 1;
    bool found = true;
    for (int i = 0; i < SZ; ++i) {
        for (int j = 0; j < SZ; ++j) {
            if (m[i][j] != current++) {
                found = false;
                break;
            }
        }
        if (!found) break;
    }
    if (current == SZ * SZ + 1) {
        answer.push_back(m);
        return true;
    }

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
        if (!used.contains(m) && dfs(m)) {
            swap(m[zi][zj], m[zi - 1][zj]);
            answer.push_back(m);
            return true;
        }
        swap(m[zi][zj], m[zi - 1][zj]);
    }
    if (zj > 0) {
        swap(m[zi][zj], m[zi][zj - 1]);
        if (!used.contains(m) && dfs(m)) {
            swap(m[zi][zj], m[zi][zj - 1]);
            answer.push_back(m);
            return true;
        }
        swap(m[zi][zj], m[zi][zj - 1]);
    }
    if (zi < SZ - 1) {
        swap(m[zi][zj], m[zi + 1][zj]);
        if (!used.contains(m) && dfs(m)) {
            swap(m[zi][zj], m[zi + 1][zj]);
            answer.push_back(m);
            return true;
        }
        swap(m[zi][zj], m[zi + 1][zj]);
    }
    if (zj < SZ - 1) {
        swap(m[zi][zj], m[zi][zj + 1]);
        if (!used.contains(m) && dfs(m)) {
            swap(m[zi][zj], m[zi][zj + 1]);
            answer.push_back(m);
            return true;
        }
        swap(m[zi][zj], m[zi][zj + 1]);
    }
    return false;
}

int main() {
    Matr m(SZ, vector<int>(SZ));
    cout << "Введите изначальное расположение пятнашек (вместо пустого места напишите 0):\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> m[i][j];
        }
    }
    dfs(m);
    reverse(answer.begin(), answer.end());
    for (const auto& elem: answer) {
        print_matrix(elem);
    }
}
