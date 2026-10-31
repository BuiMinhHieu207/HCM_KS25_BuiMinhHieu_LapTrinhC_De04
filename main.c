#include <stdio.h>
#include <string.h>

#define MAX 50

struct MatHang {
    char ma[20];
    char ten[50];
    int soLuong;
    float donGia;
};

struct MatHang ds[MAX];
int n = 0;

void themMatHang() {
    if (n >= MAX) {
        printf("Danh sach da day!\n");
        return;
    }

    printf("Nhap ma mat hang: ");
    scanf("%s", ds[n].ma);

    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ma, ds[n].ma) == 0) {
            printf("Ma mat hang da ton tai!\n");
            return;
        }
    }

    printf("Nhap ten mat hang: ");
    getchar();
    fgets(ds[n].ten, sizeof(ds[n].ten), stdin);
    ds[n].ten[strcspn(ds[n].ten, "\n")] = '\0';

    printf("Nhap so luong: ");
    scanf("%d", &ds[n].soLuong);

    printf("Nhap don gia: ");
    scanf("%f", &ds[n].donGia);

    n++;
    printf("Them thanh cong!\n");
}

void hienThiDanhSach() {
    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    printf("\n%-15s %-25s %-15s %-15s\n",
           "Ma", "Ten", "So luong", "Don gia");

    for (int i = 0; i < n; i++) {
        printf("%-15s %-25s %-15d %-15.2f\n",
               ds[i].ma, ds[i].ten,
               ds[i].soLuong, ds[i].donGia);
    }
}

void capNhatMatHang() {
    char ma[20];

    printf("Nhap ma mat hang can cap nhat: ");
    scanf("%s", ma);

    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ma, ma) == 0) {
            printf("Nhap ten moi: ");
            getchar();
            fgets(ds[i].ten, sizeof(ds[i].ten), stdin);
            ds[i].ten[strcspn(ds[i].ten, "\n")] = '\0';

            printf("Nhap so luong moi: ");
            scanf("%d", &ds[i].soLuong);

            printf("Nhap don gia moi: ");
            scanf("%f", &ds[i].donGia);

            printf("Cap nhat thanh cong!\n");
            return;
        }
    }

    printf("Khong tim thay mat hang!\n");
}

void xoaMatHang() {
    char ma[20];

    printf("Nhap ma mat hang can xoa: ");
    scanf("%s", ma);

    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ma, ma) == 0) {
            for (int j = i; j < n - 1; j++) {
                ds[j] = ds[j + 1];
            }

            n--;
            printf("Xoa thanh cong!\n");
            return;
        }
    }

    printf("Khong tim thay mat hang!\n");
}

int main() {
    int chon;

    do {
        printf("\n===== QUAN LY MAT HANG =====\n");
        printf("1. Them mat hang\n");
        printf("2. Hien thi danh sach mat hang\n");
        printf("3. Cap nhat mat hang theo ma\n");
        printf("4. Xoa mat hang theo ma\n");
        printf("5. Tim mat hang theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                themMatHang();
                break;

            case 2:
                hienThiDanhSach();
                break;

            case 3:
                capNhatMatHang();
                break;

            case 4:
                xoaMatHang();
                break;

            case 0:
                printf("Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 0);

    return 0;
}
