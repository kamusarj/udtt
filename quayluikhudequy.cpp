#include <iostream>
#include <stack>
using namespace std;

// Hàm hiển thị mảng
void show(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Hàm phân hoạch cho quicksort
int partition(int a[], int left, int right) {
    int pivot = a[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return i;
}

// Hàm quicksort khử đệ quy sử dụng ngăn xếp
void quick_sort_iterative(int a[], int n) {
    stack<pair<int, int>> s;
    s.push({0, n - 1});

    while (!s.empty()) {
        int left = s.top().first;
        int right = s.top().second;
        s.pop();

        if (left < right) {
            int pivotIndex = partition(a, left, right);

            // Đẩy các phân đoạn bên trái và bên phải vào ngăn xếp
            if (pivotIndex - 1 > left) {
                s.push({left, pivotIndex - 1});
            }
            if (pivotIndex < right) {
                s.push({pivotIndex, right});
            }
        }
    }
}

int main() {
    int *a;
    int n = 30;
    a = new int[n];
	for (int i=0;i<n;i++){
		a[i] = rand() % 10000 + 1;
	}
    cout << "Mang truoc sap sep: ";
    show(a, n);

    quick_sort_iterative(a, n);

    cout << "Mang sau sap xep: ";
    show(a, n);

    return 0;
}
