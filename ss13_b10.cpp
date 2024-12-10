#include<stdio.h>
//1
void addAllItem(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("phan tu thu arr[%d] : ",i);
		scanf("%d",&arr[i]);
	}
}
//2
void showItem(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("phan tu arr[%d]= %d \n",i, arr[i]);
	}
}
//3
void addItem(int arr[], int size){
	int index;
	int valueItem;
	printf("Nhap gia tri muon them: ");
	scanf("%d", &valueItem);
	printf("Nhap vi tri muon them:");
	scanf("%d",&index);
	for(int i=size; i>index; i-- ){
		arr[i]= arr[i-1];
		}
	arr[index]= valueItem;
	size++;
	printf("Mang sau khi them:");
	for(int i= 0; i<size ;i++){
		printf("%d ", arr[i]);
	}
}
//4
void fixItem(int arr[], int size){
	int index;
	int valueItem;
	printf("Nhap vi tri muon sua:");
	scanf("%d",&index);
	printf("Nhap gia tri muon sua: ");
	scanf("%d", &valueItem);
	for(int i=0; i<size; i++){
		if(i==index){
			arr[i]=valueItem;
		}
	}
	printf("Mang sau khi sua:");
	for(int i= 0; i<size ;i++){
		printf("%d ", arr[i]);
	}
}
//5
void deleteItem(int arr[], int size){
	int index;
	printf("nhap vi tri phan tu muon xoa: ");
	scanf("%d", &index);
	if(index<0 || index>=size){
		printf("Vi tri khong hop le");
		}else{
			for(int i=index ; i< size-1; i++){
					arr[i]=arr[i+1];
				}
				size--;
				printf("Mang sau khi xoa:");
				for(int i=0; i<size; i++){
					printf("%d ", arr[i]);
				}
		}
}
//6.1
void reduce(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep:");
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
		}
}
//6.2
void increase(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep:");
	for(int i=0; i<size; i++){
		printf("%d ", arr[i]);
		}
}
//7.1
void linearSearch(int arr[], int size, int x) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d duoc tim thay tai %d.\n", x, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Phan tu %d khong ton tai.\n", x);
    }
}
//7.2
void binarySearch(int arr[], int size, int x) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            printf("Phan tu %d duoc tim thay tai %d.\n", x, mid);
            return;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Phan tu %d khong ton tai.\n", x);
}
int main(){
	int arr[100];
	int size;
	int choose;
	do{
		printf("\n\n-----------------------MENU-----------------------\n");
		printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
		printf("2. In ra gia tri cac phan tu dang quan ly\n");
		printf("3. Them mot phan tu vao vi tri chi dinh\n");
		printf("4. Sua mot phan tu o vi tri chi dinh\n");
		printf("5. Xoa mot phan tu o vi tri chi dinh\n");
		printf("6. Sap xep cac phan tu (Khi lua chon menu cha thi hien thi menu con)\n");
		printf("7. Tim kiem phan tu nhap vao\n");
		printf("8. Thoat\n");
		printf("Moi ban chon case: ");
		scanf("%d",&choose);
		
		switch(choose){
			case 1: {
				printf("moi ban nhap so luong phan tu:");
				scanf("%d",&size);
				addAllItem(arr,size);
				break;
			}
			case 2: {
				showItem(arr,size);
				break;
			}
			case 3: {
				addItem(arr,size);
				break;
			}
			case 4: {
				fixItem(arr,size);
				break;
			}
			case 5: {
				deleteItem(arr,size);
				break;
			}
			case 6: {
				int pick;
				printf("1. Giam dan\n");
				printf("2. Tang dan\n");
				printf("Moi ban chon phuong thuc sap xep: ");
				scanf("%d", &pick);
				if(pick==1){
					reduce(arr,size);
				}else{
					increase(arr,size);
				}
				break;
			}
			case 7: {
				int pick;
				int x;
				printf("1. Tim kiem tuyen tinh\n");
				printf("2. Tim kiem nhi phan\n");
				printf("Moi ban chon phuong thuc sap xep: ");
				scanf("%d", &pick);
				printf("Nhap so can tim kiem: ");
				scanf("%d",&x);
				if(pick==1){
					linearSearch(arr,size,x);
				}else{
					binarySearch(arr,size,x);
				}
				break;
			}
			case 8: {
				printf("Thoat");
				break;
			}
			default: {
				printf("Khong hop le");
				break;
			}
		}
	}while(choose!=8);
	return 0;
}
