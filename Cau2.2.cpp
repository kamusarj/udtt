#include<bits/stdc++.h>

using namespace std;

int thamlam(double a[],int n, int C,double b[]){
	double M = 0;
	int count = 0;
	for (int i = n-1; i >= 0;i--){
		if(M <= C){
			M += a[i];
			count++;
			b[i] = a[i];
		}
		if(M>C){
			return count;
		}
	}
	return 0; 
}

int char_in_string(char ch, const char *p){
	int x = 0;
	while(p[x]!='\0'){
		if(p[x] == ch) return x;
		x++;
	}
	return -1;
}

int BMH(const char *p,const char *q){
	int v = strlen(q), i = v - 1;
	while(i<strlen(p)){
		int k = v - 1;
		while(k > -1 && p[i] == q[k]){
			i--;
			k--;
		}
		if(k < 0) return i+1;
		else{
			int x = char_in_string(p[i],q);
			if(x < 0) i = i + v;
			else i = i + v - x - 1;
		}
	}
	return -1;
}

int main(){
	int n = 8;
	double a[] = {1.1,2.1,3.4,5.6,6.1,7.4,8.3,9.9};
	double C = 30;
	char *P = "mothaibabonnamsaubay";
	char *Q = "namsau";
	double b[n];
	for (int i=0;i<n;i++){
		b[i] = 0;
	}
	cout << thamlam(a,n,C,b) << endl;
	if(thamlam(a,n,C,b)!=0){
		for (int i=0;i<n;i++){
			if(b[i]!=0) cout << b[i] << " ";
		}
		cout << endl;
	}
	cout << BMH(P,Q) << endl;
	return 0;
}