#include <bits/stdc++.h>

using namespace std;

void show(string *a,string *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ngoi ghe " << a[i] << endl ;
    }
    cout << endl;
}

void TRY(int k, int n, string *N, string *a, string *A, bool *dd) {
    for (int i = 0; i < n; i++) {
        if (!dd[i]) {
            A[k] = N[i];
            if (k == n - 1) {
                show(a,A, n);
            } else {
                dd[i] = true;
                TRY(k + 1, n, N, a, A, dd);
                dd[i] = false;
            }
        }
    }
}

int main() {
    string a[] = {"A", "B", "C", "D"};
    string N[] = {"Tung", "Cuc", "Truc", "Mai"};
    string *A = new string[4];
    bool *dd = new bool[4];
    for (int i = 0; i < 4; i++) {
        dd[i] = false;
    }
    TRY(0, 4, N, a, A, dd);
    return 0;
}
