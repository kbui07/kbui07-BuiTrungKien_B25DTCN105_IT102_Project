#include <stdio.h>
#include <string.h>

struct Account {
	char accountId[20];
	char fullName[50];
	char phone[15];
	double balance;
	int status;
};

struct Transaction {
	char transId[20];
	char senderId[20];
	char receiverId[20];
	double amount;
	char type[10];
	char date[20];
};

//Mang luu tai khoan
struct Account acc[100];
int account = 0;

//Ham kiem tra ID
int checkID(char id[]) {
	for (int i=0;i<account;i++) {
		if (strcmp(acc[i].accountId,id)==0) {
			return 1;
		}
	}
	return 0;
}

//F01
void addAccount() {
	struct Account a;
	printf("Nhap ma tai khoan: ");
	scanf("%s",&a.accountId);
//Kiem tra ID
	if (checkID(a.accountId)) {
		printf("Ma da ton tai!\n\n");
	return;
    }
    getchar();
    printf("Nhap ho va ten: ");
    fgets(a.fullName,sizeof(a.fullName),stdin);
    a.fullName[strcspn(a.fullName, "\n")]=0;
    printf("Nhap so dien thoai: ");
    scanf("%s",a.phone);
//Gan gia ti
    a.balance=0;
    a.status=1;
    acc[account++]=a;
    printf("Them tai khoan thanh cong!\n\n");
}

//F02
void updateAccount() {
    char id[20];
    printf("Nhap ma tai khoan can cap nhat: ");
    scanf("%s", id);
    int index = -1;
//Tim theo ID
    for (int i = 0; i < account; i++) {
        if (strcmp(acc[i].accountId, id) == 0) {
            index = i;
            break;
        }
    }
//Khong ton tai
    if (index == -1) {
        printf("Tai khoan khong ton tai!\n\n");
        return;
    }
    getchar();
// Cap nhat
    printf("Nhap ho ten moi: ");
    fgets(acc[index].fullName, sizeof(acc[index].fullName), stdin);
    acc[index].fullName[strcspn(acc[index].fullName, "\n")] = 0;
    printf("Nhap so dien thoai moi: ");
    scanf("%s", acc[index].phone);
    printf("Cap nhat thong tin thanh cong!\n\n");
}

int main() {
	int choice;
	do{
		printf("|===============MENU===============|\n");
		printf("|1. Them moi tai khoan             |\n");
		printf("|2. Cap nhat thong tin             |\n");
		printf("|3. Quan ly trang thai (Khoa/Xoa)  |\n");
		printf("|4. Tra cuu                        |\n");
		printf("|5. Danh sach                      |\n");
		printf("|6. Sap xep danh sach              |\n");
		printf("|7. Giao dich chuyen khoan         |\n");
		printf("|8. Lich su giao dich              |\n");
		printf("|9. Thoat chuong trinh             |\n");
		printf("|==================================|\n");
		printf("Moi ban nhap chuc nang: ");
		scanf("%d",&choice);
		printf("\n");
	switch (choice) {
		case 1:
			addAccount();
			break;
			
		case 2:
			updateAccount();
			break;
			
		case 3:
			break;
			
		case 4:
			break;
			
		case 9:
            printf("Thoat chuong trinh...\n");
            break;
        default:
            printf("? Lua chon khong hop le!\n\n");
	}
  }while(choice != 9);
	return 0;
}
