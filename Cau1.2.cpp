#include<bits/stdc++.h>

using namespace std;

int tong(int a[],int n){
	if(n == 0){
		return 0;
	}
	else{
		if(a[n - 1] % 2 != 0){
			return a[n - 1] + tong(a, n - 1);
		}
		else{
			return tong(a, n - 1); 
      }
   }
}

int main(){
	int n = 10;
	int a[] = {5,5,5,5,5,5,5,5,5,5};
	cout << tong(a,10) << endl;
	return 0;
}
