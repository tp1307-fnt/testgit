//test case 1 -- > 5
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Max 1000  
int a[Max];
void nhap(int a[], int n){
	for(int i = 0;i < n;i++){
		scanf("%d", &a[i]);
	}
}
void xuat(int a[], int n){
		for(int i = 0;i < n;i++){
		printf("%d ", a[i]);
	}
}
void sokhacnhau(int a[], int n){
	int count = 0, check = 1;
	for(int i = 0; i < n; i++){
		check = 1;
		for(int j = i + 1; j < n ;j++){
			if(a[i] == a[j]){
				check = 0;
				break;
			}
		}
		if(check) count++;
	}

	printf("\nso luong phan tu khac nhau la: %d", count);
}
int cmp(const void *a,const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	return *x - *y;
}
int cmp2(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	return *y - *x;
}
int cmp3(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	return *x - *y;
}
void hoanvi(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void interchange_sortTang(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n ; j++){
			if(a[i] > a[j])
			hoanvi(&a[i], &a[j]);
		}
	}
}
void interchange_sortGiam(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n ; j++){
			if(a[i] < a[j]);
			hoanvi(&a[i], &a[j]);
		}
	}
}
int cmp4(const void *a, const void *b){
	int *x = (int*)a;
	int *y = (int*)b;
	return abs(*x) - abs(*y);
}
int summer1(int n){
	int cmd = 0;
	while(n){
		cmd += n % 10;
		n /= 10;
	}
	return cmd;
}
int cmp6(const void *a, const void *b){
	int *x = (int *)a;
	int *y = (int *)b;
	if(summer1(*x) != summer1(*y)) return summer1(*x) - summer1(*y);
	else return *x - *y; 
}
int cmp7(const void *b, const void *a){
	int *x = (int*)a;
	int *y = (int*)b;
	return *x - *y;
}
int main(){
	int n;
	scanf("%d", &n);
	nhap(a, n);
	// sokhacnhau(a, n);
	// qsort(a, n, sizeof(int), cmp);
	// int cnt = 1;
	// for(int i = 1; i < n; i++){
	// 	if(a[i] != a[i-1]){
	// 		cnt++;
	// 	}
	// }
	// printf("\nSo luong khac nhau trong mang la: %d", cnt);
	// printf("\nHam tang la: ");
	// xuat(a, n);
	// printf("\n");
	// qsort(a, n, sizeof(int), cmp2);
	// printf("\nHam giam la: ");
	// xuat(a, n);
	// printf("\n");
	// printf("\nHam inter tang: ");
	// interchange_sortTang(a, n);
	// xuat(a, n);
	// printf("\nHam inter giam: ");
	// interchange_sortGiam(a,n);
	// xuat(a, n);
	// printf("\n");
	// // xet ham qsort nhanh 
	// qsort(a, n, sizeof(int), cmp3);
	// printf("\n");
	// for(int i = 0;i < n;i++){
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");
	// for(int i = n - 1; i >= 0; i--){
	// 	printf("%d ", a[i]);
	// }
	printf("\nHam sap xep theo abs: \n");
	qsort(a, n, sizeof(int), cmp4);
	for(int i = 0;i < n;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	qsort(a, n, sizeof(int), cmp6);
	for(int i = 0;i < n;i++){
		printf("%d ", a[i]);
	}
	int res = 1e9 + 5;
	for(int i = 1; i < n; i++){
		res = fmin(res, a[i] - a[i - 1]);
	}
	printf("\nKhoang cach nho nhat la: %d", res);
}