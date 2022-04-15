#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct Node {
	int data;
	Node* left, *right;
};
typedef struct Node NODE;

struct cayAVL {
	int data;
	cayAVL* left;
	cayAVL* right;
	int height;
};
typedef struct cayAVL AVL;


void khoiTao(NODE*& root);
NODE* taoNode(int x);
void themNode(NODE*& root, int x);
void NLR(NODE* root);
void phanTuTheMang(NODE*& root, NODE*& p);
void xoaNode(NODE*& root, int x);
int chieuCaoCay(NODE* root);
int tongNutChan(NODE* root);
int laSNT(int n);
int demSoLuongSoNguyenTo(NODE* root);

void khoiTao_AVL(AVL*& root);
int getHeight(AVL* root);
AVL* rightRotate(AVL* root);
AVL* leftRotate(AVL* root);
AVL* insert(AVL* root, int value);

int main() {
	NODE* root;
	khoiTao(root);
	int i = 1;
	while (true) {
		int x;
		cout << "\nNhap vao gia tri cua Node thu (nhap so am de ket thuc) " << i++ << ": ";
		cin >> x;
		if (x < 0)
			break;
		themNode(root, x);
	}
	cout << "\nNLR: ";
	NLR(root);
	xoaNode(root, 40);
	cout << "\nCay xoa khi xoa node 40 la  ";
	NLR(root);
	cout << "\nCay co chieu cao la " << chieuCaoCay(root);
	cout << "\nTong cac nut chan la " << tongNutChan(root);
	cout << "\nSo luong so nguyen la " << demSoLuongSoNguyenTo(root);

	AVL* tree;
	khoiTao_AVL(tree);
	int n = 0;
	do {
		cout << "\nNhap vao so luong Node cua cay AVL: ";
		cin >> n;
		if (n < 0)
			cout << "\nSo luong phai la so duong. Xin kiem tra lai";
	} while (n < 0);
	for (int i = 1; i <= n; ++i) {
		int x;
		cout << "\nNhap vao gia tri cua Node thu " << i << ": ";
		cin >> x;
		insert(tree, x);
	}

	return 0;
}

void khoiTao(NODE*& root) {
	root = NULL;
}

NODE* taoNode(int x) {
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->left = p->right = NULL;
	return p;
}

void themNode(NODE*& root, int x) {
	if (root != NULL) {
		if (x > root->data)
			themNode(root->right, x);
		else if (x < root->data)
			themNode(root->left, x);
	}
	else
		root = taoNode(x);
}

void NLR(NODE* root) {
	if (root != NULL) {
		cout << " " << root->data;
		NLR(root->left);
		NLR(root->right);
	}
}

void phanTuTheMang(NODE*& root, NODE*& p) {
	if (root->right != NULL)
		phanTuTheMang(root->right, p);
	else {
		p->data = root->data;
		p = root;
		root = root->left;
	}
}

void xoaNode(NODE*& root, int x) {
	if (root == NULL)
		return;
	if (x > root->data)
		xoaNode(root->right, x);
	else if (x < root->data)
		xoaNode(root->left, x);
	else {
		NODE* p = root;
		if (p->left == NULL)
			root = p->right;
		else if (p->right == NULL)
			root = p->left;
		else
			phanTuTheMang(root->left, p);
		delete p;
	}
}

NODE* timKiemNode(NODE* root, int x) {
	if (root == NULL)
		return NULL;
	if (x > root->data)
		return timKiemNode(root->right, x);
	else if (x < root->data)
		return timKiemNode(root->left, x);
	else
		return root;
}

int chieuCaoCay(NODE* root) {
	if (root == NULL)
		return 0;
	int left = chieuCaoCay(root->left);
	int right = chieuCaoCay(root->right);

	return left > right ? left + 1 : right + 1;
}

int tongNutChan(NODE* root) {
	queue<NODE*> q;
	if (root != NULL)
		q.push(root);
	int sum = 0;
	while (!q.empty()) {
		NODE* p = q.front();
		if (p->data % 2 == 0)
			sum += p->data;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return sum;
}

int laSNT(int n) {
	int dem = 0;
	for (int i = 1; i <= n; i++)
		if (n%i == 0)
			dem++;
	if (dem == 2)
		return 1;
	return 0;
}

int demSoLuongSoNguyenTo(NODE* root) {
	queue<NODE*> q;
	if (root != NULL)
		q.push(root);
	int dem = 0;
	while (!q.empty()) {
		NODE* p = q.front();
		if (laSNT(p->data) == 1)
			dem++;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return dem;
}

void khoiTao_AVL(AVL*& root) {
	root = NULL;
}

int getHeight(AVL* root) {
	if (root == NULL)
		return 0;
	return 1 + max(getHeight(root->left), getHeight(root->right));
}

AVL* rightRotate(AVL* root) {
	AVL* x = root->left;
	root->left = x->right;
	x->right = root;
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	x->height = 1 + max(getHeight(x->left), getHeight(x->right));
	return x;
}

AVL* leftRotate(AVL* root) {
	AVL* y = root->right;
	root->right = y->left;
	y->left = root;
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	y->height = 1 + max(getHeight(y->left), getHeight(y->right));
	return y;
}

AVL* insert(AVL* root, int value) {
	if (root == NULL)
		return new AVL{ value, NULL, NULL, 1 };
	if (value > root->data)
		root->right = insert(root->right, value);
	else if (value < root->data)
		root->left = insert(root->left, value);
	else
		return root;
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	int valBalance = getHeight(root->left) - getHeight(root->right);
	if (valBalance > 1 && value < root->left->data)
		return rightRotate(root);
	if (valBalance < -1 && value > root->right->data)
		return leftRotate(root);
	if (valBalance > 1 && value > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (valBalance < -1 && value < root->right->data) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
