#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a[100];
void nhap(int a[], int *n){
	scanf("%d", n);
	for(int i = 0; i < *n; i++){
	scanf("%d", &a[i]);
	}
	printf("\n");
}
int tca(int a[], int n){
	int count = 1;
	int acp = 0;
	for(int i = 0; i < n; i++){
		if(a[i] < 0 && a[i] % 2 == 0 && a[i] % 3 != 0){
			count *= a[i], acp = 1;
		}
	}
	return acp ? count : 0;
}
void chc4(int a[], int n){
	int acp = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 0 && a[i] % 4 == 0){
			printf("%d ", a[i]);
			acp = 1;
		}
	}
	if(!acp) printf("Khong co so nao.");
	printf("\n");
}
void hoanvi(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void inter_giam(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] < a[j]);
			hoanvi(&a[i], &a[j]);
		}
	}
}
void xuat(int a[], int n){
	printf("\nMang giam dan: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main(){
	int n;
	nhap(a, &n);
	int tich = tca(a, n);
	if(tich != 0)
		printf("\n%d\n", tich);
	else{
		printf("\nKhong co so nao ca.\n");
	}
	chc4(a, n);
	inter_giam(a, n);
	xuat(a, n);
}