#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    {"AC1005", "Hoang Van E", "0977554466", 20000000, 1},
    {"AC1006", "Truong Van F", "092341356", 50000000, 0},
    {"AC1007", "Tran Minh G", "0962351345", 32000000, 1},
    {"AC1008", "Duong Minh H", "0961254131", 5400000, 0},
    {"AC1009", "Bui Van I", "0981245754", 990000000, 1}
};
int account = 9;
  
void addAccount();
void updateAccount();
void lockAccount();
void searchAccount();
void listAccountPagination();
void sortAccount();
void transferMoney();
void toLowerStr(char s[]);

int main() {
    int choice;
    do{
        printf("|===============MENU===============|\n");
        printf("|1. Them moi tai khoan             |\n");
        printf("|2. Cap nhat thong tin             |\n");
        printf("|3. Quan ly trang thai (Khoa/Xoa)  |\n");
        printf("|4. Tra cuu                        |\n");
        printf("|5. Danh sach (Phan trang)         |\n");
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

            case 5:
            	listAccountPagination();
            	break;
            
            case 6:
            	sortAccount();
            	break;
            	
            case 7:
            	transferMoney();
            	break;
            	
            case 8:
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
        fgets(a.fullName,sizeof(a.fullName),stdin);
        a.fullName[strcspn(a.fullName, "\n")] = 0;
        if (strlen(a.fullName) == 0) {
            printf("Khong duoc de trong. Vui long nhap lai.\n");
        } else break;
    }
    
while (1) {
    printf("Nhap so dien thoai: ");
    fgets(a.phone,sizeof(a.phone),stdin);
    a.phone[strcspn(a.phone, "\n")] = 0;
    if (strlen(a.phone) == 0) {
        printf("Khong duoc de trong. Vui long nhap lai.\n");
        continue;
    }
    
    //Kiem tra 10 so
    if (strlen(a.phone) != 10) {
        printf("So dien thoai phai dung 10 ky tu. Vui long nhap lai.\n");
        continue;
    }
    
    //Kiem tra trung sdt
    int duplicate = 0;
    for (int i = 0; i < account; i++) {
        if (strcmp(acc[i].phone, a.phone) == 0) {
            duplicate = 1;
            break;
        }
    }
    if (duplicate) {
        printf("So dien thoai da ton tai. Vui long nhap lai.\n");
    } else {
        break;
    }
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
    int index = -1;

    getchar();
    while (1) {
        printf("Nhap ma tai khoan: ");
        fgets(id,sizeof(id),stdin);
        id[strcspn(id, "\n")]=0;
        if (strlen(id)==0) {
            printf("Khong duoc de trong. Vui long nhap lai.\n");
            continue;
        }

        //Tim tai khoan
        index=-1;
        for (int i=0;i<account;i++) {
            if (strcmp(acc[i].accountId,id)==0) {
                index=i;
                break;
            }
        }

        if (index==-1) {
            printf("Ma tai khoan khong ton tai. Vui long nhap lai.\n");
            continue;
        }

        break;
    }

    char temp[100];

    //Cap nhat ten
    while (1) {
        printf("Nhap ho ten moi (Enter = giu nguyen): ");
        fgets(temp,sizeof(temp),stdin);
        temp[strcspn(temp, "\n")]=0;
        //Enter giu nguyen
        if (strlen(temp) == 0) 
		    break; 
        //Kiem tra trung ten
        int duplicate=0;
        for (int i=0;i<account;i++) {
            if (i!=index && strcmp(acc[i].fullName,temp) == 0) {
                duplicate=1;
                break;
            }
        }

        if (duplicate) {
            printf("Ho ten da ton tai. Vui long nhap lai.\n");
        } else {
            strcpy(acc[index].fullName,temp);
            break;
        }
    }

    //Cap nhat sdt
    while (1) {
        printf("Nhap so dien thoai moi (Enter = giu nguyen): ");
        fgets(temp,sizeof(temp),stdin);
        temp[strcspn(temp, "\n")] = 0;
        //Enter giu nguyen
        if (strlen(temp)==0) 
		    break;
        //Kiem tra 10 so
        if (strlen(temp)!=10) {
            printf("So dien thoai phai dung 10 ky tu. Vui long nhap lai.\n");
            continue;
        }
        //Kiem tra trung
        int duplicate=0;
        for (int i=0;i<account;i++) {
            if (i!=index && strcmp(acc[i].phone,temp) == 0) {
                duplicate=1;
                break;
            }
        }
        if (duplicate) {
            printf("So dien thoai da ton tai. Vui long nhap lai.\n");
        } else {
            strcpy(acc[index].phone,temp);
            break;
        }
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
    printf("====Thong tin hien tai====\n");
    printf("ID: %s\n",acc[index].accountId);
    printf("Ten: %s\n",acc[index].fullName);
    printf("SDT: %s\n",acc[index].phone);
    printf("So du: %f\n",acc[index].balance);
    printf("Trang thai: %s\n",acc[index].status == 1 ? "Active" : "Locked");
	    
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

//Ham chuyen chu hoa thanh thuong
void toLowerStr(char s[]) {
	int i=0;
	while(s[i]='\0') {
		if (s[i]>='A' && s[i]<='Z') {
			s[i]=s[i+32];
		}
		i++;
	}
}

//F04
void searchAccount() {
    char keyWord[50];
    char keyLower[50];
    getchar();
    printf("Nhap tu khoa tim kiem (ID hoac Ten): ");
    fgets(keyWord,sizeof(keyWord),stdin);
    keyWord[strcspn(keyWord, "\n")] = 0;
    
    //chuyen keyword->lowercase
    strcpy(keyLower,keyWord);
    toLowerStr(keyLower);

    int found = 0;
    for (int i=0;i<account;i++) {
    	
    	//Tim theo ID
    	char idLower[20];
        strcpy(idLower,acc[i].accountId);
        toLowerStr(idLower);
        if (strcmp(idLower,keyLower)==0) {
            printf("ID: %s | Ten: %s | SDT: %s | So du: %f | Trang thai: %s\n",
                   acc[i].accountId,acc[i].fullName,acc[i].phone,
                   acc[i].balance,acc[i].status == 1? "Active" : "Locked");
            found=1;
            continue;
        }

        //Tìm theo tên
        char nameLower[50];
        strcpy(nameLower,acc[i].fullName);
        toLowerStr(nameLower);
        if (strstr(nameLower,keyLower)!=NULL) {
            printf("ID: %s | Ten: %s | SDT: %s | So du: %f | Trang thai: %s\n",
                acc[i].accountId,acc[i].fullName,acc[i].phone,
                acc[i].balance,acc[i].status == 1? "Active" : "Locked");
            found=1;
        }
    }

    if (!found) {
        printf("Khong co ket qua phu hop!\n\n");
    } else {
        printf("Ket thuc tim kiem!\n\n");
    }
}

//F05
void listAccountPagination() {
	int page_n,page_s=5;
	int start,end;
	while (1) {
	   printf("Nhap so trang: ");
	   scanf("%d",&page_n);
	   //Kiem tra
	   if (page_n<=0) {
            printf("So trang khong hop le! Vui long nhap lai.\n\n");
            continue;
        }
    start=(page_n-1)*page_s;
     //Neu vuot
     if (start>account) {
    	printf("Khong tim thay du lieu cho trang nay! Vui long nhap lai.\n\n");
            continue;
	 }
	break;
   }
    end= start+page_s;
    if (end > account) {
   	end = account;
   }  
    printf("====Trang %d====\n",page_n);
    for (int i = start; i < end; i++) {
        printf("%d. ID: %s | Ten: %s | SDT: %s | So du: %.2f | Trang thai: %s\n",
            i + 1,acc[i].accountId,acc[i].fullName,acc[i].phone,
            acc[i].balance,acc[i].status == 1 ? "Active" : "Locked");
    }
}

//F06
void sortAccount() {
	if (account ==0 ) {
		printf("Khong co du lieu can sap xep");
	return;
	}
	
	int ch;
	printf("1.Sap xep theo so du giam dan\n");
	printf("2.Sap xep theo ten A-Z\n");
	printf("Nhap lua chon: ");
	scanf("%d",&ch);
	
	//Sap xep
	for (int i=0;i<account;i++) {
		for (int j=i+1;j<account;j++) {
			
			//Giam dan
			if (ch == 1) {
				if(acc[i].balance<acc[j].balance) {
					struct Account
					t=acc[i];
					acc[i]=acc[j];
					acc[j]=t;
				}
			}
			
			//Theo ten
			else if (ch == 2) {
				if(strcmp(acc[i].fullName,acc[j].fullName)>0) {
					struct Account 
					t=acc[i];
					acc[i]=acc[j];
					acc[j]=t;
				}
			}
		}
	}
	if (ch<1 || ch>2) {
		printf("Lua chon khong hop le!!\n");
	}
	printf("Da sap xep xong!!\n");
}

//F07
void transferMoney() {
    char senderId[20],receiverId[20];
    double amount;
    int senderIndex=-1, receiverIndex=-1;

    getchar();
    printf("Nhap ID nguoi gui: ");
    fgets(senderId,sizeof(senderId),stdin);
    senderId[strcspn(senderId,"\n")] = 0;
    printf("Nhap ID nguoi nhan: ");
    fgets(receiverId,sizeof(receiverId),stdin);
    receiverId[strcspn(receiverId,"\n")] = 0;

    //senderId va receiverId phai ton tai
    for (int i=0;i<account;i++) {
        if (strcmp(acc[i].accountId,senderId)==0) 
		    senderIndex = i;
        if (strcmp(acc[i].accountId,receiverId)==0) 
		    receiverIndex = i;
    }

    if (senderIndex==-1 || receiverIndex==-1) {
        printf("Loi xac thuc du lieu (ID khong ton tai)\n\n");
        return;
    }

    //Không duoc trùng ID
    if (strcmp(senderId,receiverId)==0) {
        printf("Nguoi gui va nguoi nhan khong duoc trung nhau!\n\n");
        return;
    }

    //Sender phai active
    if (acc[senderIndex].status!=1) {
        printf("Tai khoan gui dang bi khoa, khong the thuc hien giao dich!\n\n");
        return;
    }

    //So tien>0
    printf("Nhap so tien can chuyen: ");
    scanf("%f",&amount);
    if (amount<=0) {
        printf("So tien phai lon hon 0!\n\n");
        return;
    }

    //Sender du tien
    if (amount>acc[senderIndex].balance) {
        printf("So du khong du de thuc hien giao dich!\n\n");
        return;
    }

    acc[senderIndex].balance-=amount;
    acc[receiverIndex].balance+=amount;
    printf("\n===== GIAO DICH THANH CONG =====\n");
    printf("Nguoi gui: %s | So du moi: %f\n", acc[senderIndex].accountId,acc[senderIndex].balance);
    printf("Nguoi nhan: %s | So du moi: %f\n", acc[receiverIndex].accountId,acc[receiverIndex].balance);
}

//F08
void viewTransactionHistory() {
	char targetId[20];
	int index=-1;
	getchar();
	printf("Nhap ma tai khoan can xem lich su: ");
	fgets(targetId,sizeof(targetId),stdin);
	targetId[strcspn(targetId,"\n")]=0;
	
	//Kiem tra tai khoan ton tai
	for (int i=0;i<account;i++) {
		if (strcmp(acc[i].accountId,targetId)==0) {
			index=i;
			break;
		}
	}
	if (index=-1) {
		printf("Loi: Tai khoan khong ton tai!\n");
		return;
	}
}
