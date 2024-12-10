#include <stdio.h>
//1
void addAllItem(int arr[100][100], int *n, int *m) {
    printf("Nhap so dong: ");
    scanf("%d", n);
    printf("Nhap so cot: ");
    scanf("%d", m);
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
//2
void showItem(int arr[100][100], int n, int m) {
    printf("Ma tran hien tai:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
//3
void corner(int arr[100][100], int n, int m) {
    printf("Cac phan tu o goc ma tran:\n");
    printf("%d %d\n", arr[0][0], arr[0][m - 1]);
    printf("%d %d\n", arr[n - 1][0], arr[n - 1][m - 1]);
}
//4
void borderLine(int arr[100][100], int n, int m) {
    printf("Cac phan tu tren duong bien:\n");
    for (int j = 0; j < m; j++) printf("%d ", arr[0][j]);
    printf("\n");
    for (int i = 1; i < n - 1; i++) {
        printf("%d ", arr[i][0]);
        for (int j = 1; j < m - 1; j++) printf("0 ");
        printf("%d\n", arr[i][m - 1]);
    }
    for (int j = 0; j < m; j++) printf("%d ", arr[n - 1][j]);
    printf("\n");
}
//5
void diagonal(int arr[100][100], int n, int m) {
    printf("Cac phan tu tren duong cheo chinh va cheo phu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j || i + j == m - 1) printf("%d ", arr[i][j]);
            else printf("0 ");
        }
        printf("\n");
    }
}
//6
void showPrime(int arr[100][100], int n, int m) {
    printf("Cac so nguyen to trong mang la:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int is_prime = 1;
            if (arr[i][j] <= 1) {
                is_prime = 0;
            } else {
                for (int k = 2; k * k <= arr[i][j]; k++) {
                    if (arr[i][j] % k == 0) {
                        is_prime = 0;
                        break;
                    }
                }
            }
            if (is_prime) {
                printf("%d ", arr[i][j]);
            }
        }
    }
}

int main() {
    int arr[100][100];
    int n, m;
    int choose;
    do {
        printf("\n------------------------MENU-------------------------\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                addAllItem(arr, &n, &m);
                break;
            case 2:
                showItem(arr, n, m);
                break;
            case 3:
                corner(arr, n, m);
                break;
            case 4:
                borderLine(arr, n, m);
                break;
            case 5:
                diagonal(arr, n, m);
                break;
            case 6:
                showPrime(arr, n, m);
                break;
            case 7:
                printf("Thoat\n");
                break;
            default:
                printf("Khong hop le\n");
        }
    } while (choose != 7);

    return 0;
}

