#include<bits/stdc++.h>

using namespace std;

void show(string *a,int n){
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void TRY(int k,int n,string *S,string *a,bool *dd,int &dem){
	for (int i=0;i<n;i++){
		if(!dd[i]){
			a[k] = S[i];
			if(k == n-2){
				show(a,n-1);
				dem++;
			}
			else{
				dd[i] = true;
				TRY(k+1,n,S,a,dd,dem);
				dd[i] = false;
			}
		}
	}
}

int main(){
	int n=7,dem=0;
	string S[] = {"A","B","C","D","E","F","G"};
	string *a = new string[7];
	bool *dd = new bool[7];
	for (int i=0;i<n;i++){
		dd[i] = false;
	}
	TRY(0,n,S,a,dd,dem);
	cout << dem << endl;
	return 0;
}
