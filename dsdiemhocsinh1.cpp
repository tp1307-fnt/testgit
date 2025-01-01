#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define max 100

char maso[max][10];
char dsten[max][30];
float dstoan[max], dsly[max], dshoa[max];

void nhaphs(char maso[], char dsten[], float *dstoan, float *dsly, float *dshoa) {
    scanf("%s", maso); // Đọc số báo danh
    getchar(); // Loại bỏ ký tự còn lại trong bộ đệm
    fgets(dsten, 30, stdin); // Đọc tên có khoảng trống
    dsten[strcspn(dsten, "\n")] = 0; // Loại bỏ ký tự newline
    scanf("%f %f %f", dstoan, dsly, dshoa); // Nhập điểm
}

void nhapdshs(char maso[][10], char dsten[][30], float dstoan[], float dsly[], float dshoa[], int n) {
    for (int i = 0; i < n; i++) {
        nhaphs(maso[i], dsten[i], &dstoan[i], &dsly[i], &dshoa[i]);
    }
}

int main() {
    int n;
    do {
        printf("\nHay nhap SL hoc sinh ( 1 --> 100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100) {
            printf("\nNhap lai chu y gioi han hoc sinh.\n");
        }
    } while (n < 1 || n > 100);

    nhapdshs(maso, dsten, dstoan, dsly, dshoa, n);

    for (int i = 0; i < n; i++) {
        printf("\nMaso[%d]: %s\nTen[%d]: %s\nDiemToan[%d]: %.2f\nDiemly[%d]: %.2f\nDiemhoa[%d]: %.2f\n", 
               i, maso[i], i, dsten[i], i, dstoan[i], i, dsly[i], i, dshoa[i]);
    }

    printf("Hoc luc hoc sinh:");
    for (int i = 0; i < n; i++) {
        float averagescore = (dstoan[i] + dsly[i] + dshoa[i]) / 3.0; // Sử dụng kiểu float cho độ chính xác
        if (averagescore >= 8 && averagescore <= 10) {
            printf("Gioi\n");
        } else if (averagescore >= 6.5 && averagescore < 8) {
            printf("Kha\n");
        } else if (averagescore >= 5 && averagescore < 6.5) {
            printf("Trung Binh\n");
        } else {
            printf("Yeu\n");
        }
    }

    return 0;
}