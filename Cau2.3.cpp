#include<bits/stdc++.h>

using namespace std;

struct danhsach{
	int khoiluong;
	double giatri;
};

int thamlam(danhsach *a,int n,double C, int b[]){
	double V = 0;
	int count = 0;
	for(int i = 0; i < n; i++){
		if(V + a[i].giatri <= C){
			V += a[i].giatri;
			count++;
			b[i] = i;
		}
		if(V == C) return count;
	}
	if(V != C) return 0;
}

void qhd(double **f, int n, int M, danhsach *a){
	for (int j = 0; j <= M; j++) f[0][j] = 0;
    for (int i = 1; i <= n; i++) { 
        for (int j = 0; j <= M; j++) {
            f[i][j] = f[i-1][j]; 
            if (a[i-1].khoiluong <= j) { 
                int temp = a[i-1].giatri + f[i-1][j-a[i-1].khoiluong];
                if (f[i][j] < temp) {
                    f[i][j] = temp;
                }
            }
        }
    }
}

void result(double **f, int n, int M, danhsach *a) {
    cout << "Gia tri lon nhat: " << f[n][M] << endl;
    int i = n, j = M;
    cout << "Gia tri cua cac goi hang duoc chon: ";
    while (i != 0) {
        if (f[i][j] != f[i-1][j]) { 
            cout << a[i-1].giatri << " "; 
            j -= a[i-1].khoiluong;
        }
        i--;
    }
    cout << endl;
}

int main(){
	int n = 8;
	int b[n];
	for (int i=0;i<n;i++){
		b[i] = -1;
	}
	danhsach *a = new danhsach[n];
	a[0] = {1,2.3};
	a[1] = {2,3.1};
	a[2] = {6,4.1};
	a[3] = {3,5.7};
	a[4] = {4,6.6};
	a[5] = {9,7.4};
	a[6] = {7,8.9};
	a[7] = {8,10};
	double C = 9.5;
	int M = 15;
	double **f = new double*[n+1];
    for (int i = 0; i <= n; i++) {
        f[i] = new double[M+1];
    }
	if(thamlam(a,n,C,b)!=0){
		cout << thamlam(a,n,C,b) << endl;
		for (int i=0;i<n;i++){
			if(b[i]!=-1) cout << b[i] << " ";
		}
		cout << endl;
	}
	else cout << "Khong co phuong an thoa man" << endl;
	qhd(f,n,M,a);
	result(f,n,M,a);
	return 0;
}