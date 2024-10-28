#include<bits/stdc++.h>

using namespace std;

struct hangkhong{
	string sohieu;
	int giave;
	int soghe;
};
hangkhong temp_data = {.sohieu = "",.giave = 0, .soghe = 0};

hangkhong A1(int k,int n,hangkhong *b){
	if(k>n) return temp_data;
	if(b[k].giave == 700000 && k<=n) return b[k];
	return A1(k+1,n,b);
}


void mergeSort(hangkhong *b,hangkhong *temp, int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;

    mergeSort(b,temp, l, mid);
    mergeSort(b,temp, mid + 1, r);

    int i = l, j = mid + 1;
    int k = 0;

    while (i <= mid && j <= r) {
        hangkhong nextValue;

        if (b[i].giave < b[j].giave) nextValue = b[i++];
        else nextValue = b[j++];

        temp[k++] = nextValue;
    }

    while (i <= mid) temp[k++] = b[i++];
    while (j <= r) temp[k++] = b[j++];

    for (int i=0; i<k; i++) b[l + i] = temp[i];
}

int giamin(hangkhong *b,int l,int r,int &k){
	int m = (l+r)/2;
	if(l == r){
		k = l;
		return b[l].giave;
	}
	int kl = k,kr = k;
	int minl = giamin(b,l,m,kl);
	int minr = giamin(b,m+1,r,kr);
	if(minl<minr){
		k = kl;
		return minl;
	}
	else{
		k = kr;
		return minr;
	}
}

void show(hangkhong *b,int n){
	for (int i=0;i<n;i++){
		cout << b[i].sohieu << setw(10) << b[i].giave  << setw(10) << b[i].soghe << endl;
	}
	cout << endl;
}

void TRY(int k,int n,hangkhong *b,hangkhong *temp,bool *dd,int &dem){
	for (int i=0;i<n;i++){
		if(!dd[i]){
			temp[k] = b[i];
			if(k == n-4){
				show(temp,n-3);
				dem++;
			}
			else {
				dd[i] = true;
				TRY(k+1,n,b,temp,dd,dem);
				dd[i] = false;
			}
		}
	}
}

void TRY1(int k,int n,hangkhong*b,hangkhong *temp,bool *dd,int &dem){
	int last_element = (k == 1) ? 0 : k - 1;
	for (int i = last_element ;i< n;i++){
		if(!dd[i]){
			temp[k] = b[i];
			if(k == n-4){
				show(temp,n-3);
				dem++;
				return;
			}
			else{
				dd[i] = true;
				TRY1(k+1,n,b,temp,dd,dem);
				dd[i] = false;
			}
		}
	}
}

int main(){
	int n = 7,dem=0,k=0;
	hangkhong *b = new hangkhong[n];
	hangkhong *temp = new hangkhong[n];
	b[0] = {"VN001",700000,50};
	b[1] = {"VN002",750000,45};
	b[2] = {"VN003",730000,47};
	b[3] = {"VN004",600000,80};
	b[4] = {"VN005",500000,100};
	b[5] = {"VN006",550000,90};
	b[6] = {"VN007",650000,70};
	bool *dd = new bool[n];
	for (int i=0;i<n;i++){
		dd[i] = false;
	}
	hangkhong a1 = A1(0,n,b);
	if(a1.sohieu != ""){
		cout << a1.sohieu << " " << a1.giave << " " << a1.soghe << endl;
	}
	else cout << "Khong co chuyen bay nao co gia ve 700000!" << endl;
	cout << giamin(b,0,n-1,k) << endl;
	cout << k << endl;
	cout << b[k].sohieu << " " << b[k].giave << " " << b[k].soghe << endl;
//	TRY(0,n,b,temp,dd,dem);
//	cout << dem << endl;
//	dem =0;
//	for (int i=0;i<n;i++){
//		dd[i] = false;
//	}
	TRY1(0,n,b,temp,dd,dem);
	cout << dem << endl;
	return 0;
}