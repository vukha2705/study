#include<stdc/bits++.h>

using namespace std;

typedef struct tagSinhVien{
	char MSSV[10];
	char HoTen[30];
	float Diem;
	} SinhVien;

typedef struct tagNode {
	SinhVien Data;
	struct tagNode *pNext;
	} Node, *PNODE;

void ThemSinhVienCuoi(SinhVien sv){
	PNODE newNode = (PNODE)malloc(sizeof(Node));
	if(Node = nullptr){
		printf("Khong du bo nho");
		return;
	}
	newNode->Data = sv;
	newNode->pNext = sv;
	
	if(pHead == nullptr){
		pHead = newNode;
	} else {
		PNODE current = head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->next = newNode;
	}
}

void InSinhVienDiem5(){
	PNODE current = pHead;
	while(current != nullptr) {
		if(current->Data.Diem < 5) {
			cout << current->Data.MSSV << current->Data.Hoten << current->Data.Diem;
		}
		current = current->pNext;
	}
}

void sapxepgiamdantheodiem(){
	int swapped;
	PNODE current;
	PNODE last = nullptr;

	if(pHead = nullptr){
		return;
	}
	do {
		swapped = 0;
		current = pHead;

		while(current->pNext != last){
			if(current->Data.Diem < current->pNext->Data.Diem){
				SinhVien temp = current->Data;
				current->Data = current->pNext->Data;
				current->pNext->Data = temp;
				swapped = 1;
			}
			current = current->pNext;
		}
		last = current;
	} while(swapped);
}
void InDanhSachSinhVien(){
	Node* current = head;
	while(current != nullptr) {
		cout << current->Data.MSSV << " - " << current->Data.HoTen << " - " << current->Data.Diem << endl;
		current = current->pNext;
	}
}

//Ham tim phan tu co khoa x tren cay 
Node* search(Node* root, int x) {
	while(root != nullptr) {
		if(root->key == x) {
			return root;
		} else if(root->key > x) {
			root = root->left;
		} else {
			root = root->right;
		}
	}
	return nullptr;
}
