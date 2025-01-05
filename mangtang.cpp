#include <stdio.h>
#include <math.h>
#define max 1000000
#define ll long long
ll a[max];

void nhap(ll a[], int n){
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
}

void xuat(ll a[], int n){
    for(int i = 0; i < n; i++){
        printf("%lld ", a[i]);
    }
    printf("\n");
}

// void hoanvi(ll &a, ll &b){
//     ll temp = a;
//     a = b;
//     b = temp;
// }

void interchange_sort(ll a[], int n){
    for(int i = 1; i < n; i++){
    	if(a[i] <= a[i - 1]){
    		printf("\nNo");
    		return ;
    	}
    }
    printf("\nyes");
}
void maxunfix(int a[], int n){
    for(int i = 0; i <n; i++){
        int check = 1;
        for(int j = i + 1; j < n; j++){
            if(a[i] <= a[j]){
                check = 0; 
                break;
            }
        }
        if(check) printf("%d ", a[i]);
    }
}
void maxfix(ll a[], int n){
    int maxi = -1e9;
    printf("%d", a[0]);
    for(int i = 0; i < n; i++){
        if(a[i] > max){
            printf("%d ", a[i]);
            maxi = a[i];
        }
        printf("%d ", a[i]);
    }
}   
int diehard(ll a[], int n){
    int dem25 = 0, dem50 = 0;
    for(int i = 0; i < n; i++){
            if(a[i] == 25) ++dem25;
            else if(a[i] == 50){
                if(dem25 == 0) return 0; // khong ban duoc hang
                else{
                    --dem25;
                    ++dem50;
                }
            }
            // day la toi luot to 100
            else{
                //Kiểm tra nếu không có tờ 25 hoặc tổng số tiền 25 và 50 nhỏ hơn 75
                if(dem25 == 0 || (dem25 * 25 + dem50 * 50 < 75))
                    return 0;
                //Nếu có tờ 50, giảm dem50 và dem25 đi 1
                if(dem50 != 0){
                    --dem50, --dem25;
                }
                //Nếu không có tờ 50, giảm dem25 đi 3 (vì 3 tờ 25 tương đương 75).
                else{
                    dem25 -= 3; 
                }
            }
        }
        return 1;
}
void Gmaill(ll a[], int n){
    for(int i = 0; i < n; i++){
        // nam o dau
        if(i == 0){
            printf("\nmini: %d maxi: %d", a[1] - a[0], a[n-1] - a[0]);
        }
        else if(i == n -1){
            printf("\nmini: %d maxi: %d", a[n-1] - a[n-2], a[n-1] - a[0]);           
        }
        else{
            printf("\nmini: %d maxi: %d", (int)fmin(a[i] - a[i-1], a[i+1] - a[i]), (int)fmax(a[i] - a[0], a[n-1] - a[i]));
        }
    }
}
// test đếm cặp số nguyên tố
int gcd(int a, int b){
    if(b == 0 ) return a;
    else return gcd(b, a%b);
}
int main(){
    int n;
    scanf("%d", &n);
    nhap(a, n);
    // Gmaill(a, n);
        // maxfix(a, n);
    // interchange_sort(a, n);
    // printf("\n");
    // nhap(a, n);
    // if(diehard(a, n)){ 
    // printf("\nYes"); 
    // } 
    // else { 
    //     printf("\nNo");
    // }
    // return 0;
    int cnt = 0;
    for(int i =0 ;i < n; i++){
        for(int j = i+1; j < n; j++){
            if(gcd(a[i], a[j]) == 1) ++cnt;
        }
    }
    printf("%d", cnt);
}
