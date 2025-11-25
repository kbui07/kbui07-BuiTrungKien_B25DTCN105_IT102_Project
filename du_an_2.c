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
struct Account acc[100]= {
	{"AC1001", "Nguyen Van A", "0987654321", 5000000, 1},
    {"AC1002", "Tran Thi B",  "0912345678", 12000000, 1},
    {"AC1003", "Le Van C",    "0935123456", 8500000, 0}, 
    {"AC1004", "Pham Thi D",  "0909988776", 3000000, 1},
    {"AC1005", "Hoang Van E", "0977554466", 20000000, 1}
};
int account = 5;
  
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
    getchar();
    printf("Nhap ma tai khoan: ");
    fgets(a.accountId,sizeof(a.accountId),stdin);
    a.accountId[strcspn(a.accountId, "\n")] = 0;
    
    //Kiem tra ID
    if (checkID(a.accountId)) {
        printf("Loi xac thuc du lieu\n\n");
        return;
    }
    
    //Kiem tra mang day
    if (account >= 100) {
        printf("Mang day\n\n");
        return;
    }
    while (1) {
        printf("Nhap ho va ten: ");
        fgets(a.fullName, sizeof(a.fullName), stdin);
        a.fullName[strcspn(a.fullName, "\n")] = 0;
        if (strlen(a.fullName) == 0) {
            printf("Khong duoc de trong. Vui long nhap lai.\n");
        } else break;
    }
    
    while (1) {
        printf("Nhap so dien thoai: ");
        fgets(a.phone, sizeof(a.phone), stdin);
        a.phone[strcspn(a.phone, "\n")] = 0;
        if (strlen(a.phone) == 0) {
            printf("Khong duoc de trong. Vui long nhap lai.\n");
        } else break;
    }
    
    //Gan gia tri
    a.balance = 0;
    a.status = 1;
    acc[account++] = a;
    printf("Them tai khoan thanh cong.\n\n");
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
        printf("Khong tim thay tai khoan\n\n");
        return;
    }
    getchar();
    while (1) {
        printf("Nhap ho ten moi: ");
        fgets(acc[index].fullName, sizeof(acc[index].fullName), stdin);
        acc[index].fullName[strcspn(acc[index].fullName, "\n")] = 0;
        int duplicate = 0;
        for (int i = 0; i < account; i++) {
            if (i != index && strcmp(acc[i].fullName, acc[index].fullName) == 0) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate) {
            printf("Ho ten da ton tai. Vui long nhap lai.\n");
        } else break;
    }
    
    while (1) {
        printf("Nhap so dien thoai moi: ");
        fgets(acc[index].phone, sizeof(acc[index].phone), stdin);
        acc[index].phone[strcspn(acc[index].phone, "\n")] = 0;
        int duplicate = 0;
        for (int i = 0; i < account; i++) {
            if (i != index && strcmp(acc[i].phone, acc[index].phone) == 0) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate) {
            printf("So dien thoai da ton tai. Vui long nhap lai.\n");
        } else break;
    }
    printf("Cap nhat thanh cong.\n\n");
}

//F03
void lockAccount() {
	char id[20];
	while (1) {
		getchar();
	    printf("Nhap ma tai khoan can khoa: ");
	    fgets(id,sizeof(id),stdin);
		id[strcspn(id,"\n")] = 0;
	
    	int index = -1;
    	//Tim tai khoan theo ID
	    for (int i=0;i<account;i++) {
    	    if (strcmp(acc[i].accountId,id) == 0) {
    		   index = i;
    	    break;
		}
	}
	if (index == -1) {
		printf("Tai khoan khong ton tai!!\nVui long nhap lai!!");
		continue;
	    }
    //Xac nhan khoa
    char confirm[3];
    printf("Ban co muon xoa tai khoan nay (y/n): ");
    fgets(confirm,sizeof(confirm),stdin);
    confirm[strcspn(confirm,"\n")] = 0;
    if (confirm[0]=='y' || confirm[0]=='Y') {
    	acc[index].status = 0;
    	printf("Khoa tai khoan thanh cong!!\n");
	} else {
		printf("Huy thao tac!!\n");
	}
	break;
  }
}

//F04
void searchAccount() {
    char keyword[50];
    getchar();
    printf("Nhap tu khoa tim kiem (ID hoac Ten): ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < account; i++) {
        //Tìm theo ID
        if (strcmp(acc[i].accountId,keyword) == 0) {
            printf("ID: %s | Ten: %s | SDT: %s | So du: %f | Trang thai: %s\n",
                   acc[i].accountId,acc[i].fullName,acc[i].phone,
                   acc[i].balance,acc[i].status == 1? "Active" : "Locked");
            found = 1;
            continue;
        }

        //Tìm theo tên
        if (strstr(acc[i].fullName,keyword) != NULL) {
            printf("ID: %s | Ten: %s | SDT: %s | So du: %f | Trang thai: %s\n",
                acc[i].accountId,acc[i].fullName,acc[i].phone,
                acc[i].balance,acc[i].status == 1? "Active" : "Locked");
            found = 1;
        }
    }

    if (!found) {
        printf("Khong co ket qua phu hop!\n\n");
    } else {
        printf("Ket thuc tim kiem!\n\n");
    }
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
            	lockAccount();
                break;

            case 4:
            	searchAccount();
                break;

            case 9:
                printf("Thoat chuong trinh...\n");
                break;
            default:
                printf(" Lua chon khong hop le!\n\n");
        }
    } while(choice != 9);
    return 0;
}
