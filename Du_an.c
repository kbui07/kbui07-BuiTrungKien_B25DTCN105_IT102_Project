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
	}while(choice != 9);
	switch (choice) {
		case 1:
			break;
			
		case 2:
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
	return 0;
}
