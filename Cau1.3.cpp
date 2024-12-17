#include<bits/stdc++.h>

using namespace std;

double sum(double a[],int l,int r){
	if(l == r ){
		if(a[l] > 0) return a[l];
		return 0;
	}
	int m = (l+r)/2;
	double leftsum = sum(a,l,m);
	double rightsum = sum(a,m+1,r);
	return leftsum + rightsum;
}

int main(){
	int n = 10;
	double a[] = {-1.2,2.4,-3.3,4.9,5.5,-6.1,-7.4,8.3,9.7,10};
	cout << sum(a,0,n-1) << endl;
	return 0;
}