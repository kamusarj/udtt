#include <iostream>
using namespace std;

void show(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int partition(int a[], int left, int right) {
    int mid = a[(left + right) / 2]; 
    int i = left, j = right;

    while (i <= j) {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;

        if (i <= j) {
            int tg = a[i];a[i] = a[j];a[j] = tg;
            i++;
            j--;
        }
    }
    return i;  // tra ve vi tri phan doan sau khi sap xep
}

void quick_sort_try(int a[], int left, int right) {
    if (left >= right) return;

    int index = partition(a, left, right);

    quick_sort_try(a, left, index - 1);
    quick_sort_try(a, index, right);
}

int main() {
    int *a;
    int n = 20;
    a = new int[n];
	for (int i=0;i<n;i++){
		a[i] = rand() % 10000 + 1;
	}
    cout << "Mang truoc sap sep: ";
    show(a, n);

    quick_sort_try(a, 0, n - 1);

    cout << "Mang sau sap xep: ";
    show(a, n);

    return 0;
}
