#include <stdio.h>
#include <stdlib.h>
// huong dan su dung qsort(stdlib.h) va  comparator 
/*
 void qsort(void *base, size_t nitems, size_t size, int(*compar)(const void*, const void*))
 void qsort(mang(array), so_luong_phan_tu, kich_thuoc, int(*compar)(const void*, const void*))
*/
int comp(const void *a,const void *b){
	int *x = (int*)a;
	int *y = (int*)b;
	// if(*x < *y) return -1;
	// else return 1;
	return *x - *y;// return ve mang tang dan
	//con return *y - *x; thi ket qua chinh la giam dan
	/*
	+> *x - *y cho kq > 1 -->ham sau khi xep se theo mang giam dan 
	+> *x - *y cho kq < -1 --> ham sau khi xep se tand dan
	+> *x - *y cho kq = 1-->khong can sap xep ket qua nhu mang ban dau
	*/ 
}
/*
sap xep theo kieu tri tuyet doi tang dan
6
-9- 5 4 2 1
--> 1 2 4 -5 -9
*/
void qsort1(const void *a,const void *b){
	int *x = (int*)a;
	int *y = (int*)b;
	return abs(*x) - abs(*y);
}
/*
sap xep tong chu so tang dan
6
1 30 29 77 13 9
1 30 13 9 29 77
*/
int tong(int n){
	int sum=0;
	while(n){
		sum = n % 10;
		n/=10;
	}
	return sum;
}
void qsort2(const void* a, const void* b){
	int *x = (int*)a;
	int *y = (int*)b;
	return tong(*x)- tong(*y);
}
void hoanvi(int *a,  int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void interchange_sort(int a[], int n){
	for(int i=0; i < n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] > a[j]) 
				hoanvi(&a[i], &a[j]);
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n;i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int),comp);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\nHam interchange_sort:");
	interchange_sort(a, n);
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}

}