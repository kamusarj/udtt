#include<bits/stdc++.h>

using namespace std;

double SUM(double a[],int l,int r){
	if(l==r){
		return a[l];
	}
	int mid = (l+r)/2;
	double leftsum = SUM(a,l,mid);
	double rightsum = SUM(a,mid+1,r);
	return leftsum + rightsum;
}

int main(){
	int n = 10;
	double a[n];
	for(int i=0;i<n;i++){
		a[i] = (rand() % 1000) / 10.0;
		cout << a[i] << " ";
	}
	double sum = SUM(a,0,n-1);
	cout << endl << "Tong day tren la:" << sum;
	return 0;
}