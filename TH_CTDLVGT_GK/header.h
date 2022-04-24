#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct Bst {
  int data;
  Bst* left, * right;
};
typedef struct Bst BST;

void init_BST(BST*& root);
BST* getNode_BST(int x);
void themNodeVaoCay_BST(BST*& root, int x);
void LNR_BST(BST* root);
void timPhanTuTheMang_BST(BST*& root, BST*& p);
void xoaNodeTrongCay_BST(BST*& root, int x);
BST* timKiemNode_BST(BST* root, int x);
void xoayTrai_BST(BST*& root);
void xoayPhai_BST(BST*& root);
int tinhChieuCaoCuaCay_BST(BST* root);
int tinhTongCacNutChan_BST(BST* root);
int kiemtraSNT_BST(int n);
int demSoLuongSoNguyenTo_BST(BST* root);
struct Avl {
  int data, thuTuDuyet;
  struct Avl* left, * right;
  struct Avl* cha;
};
typedef struct Avl AVL;

void init_AVL(AVL*& root);
AVL* getNode_AVL(int x);
void quayTrai_AVL_AVL(AVL*& root);
void quayPhai_AVL(AVL*& root);
int themNodeVaoCay_AVL(AVL*& root, int x);
int tinhChieuCaoCay_AVL(AVL* root);
int canBangNode_AVL(AVL*& root);
void NLR_AVL(AVL* root);
