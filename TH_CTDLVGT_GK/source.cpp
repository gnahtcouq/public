#include "header.h"

void init_BST(BST*& root) {
  root = NULL;
}

BST* getNode_BST(int x) {
  BST* p = new BST;
  if (p == NULL)
    return NULL;
  p->data = x;
  p->left = p->right = NULL;
  return p;
}

void themNodeVaoCay_BST(BST*& root, int x) {
  if (root != NULL) {
    if (x > root->data)
      themNodeVaoCay_BST(root->right, x);
    else if (x < root->data)
      themNodeVaoCay_BST(root->left, x);
  }
  else
    root = getNode_BST(x);
}

void LNR_BST(BST* root) {
  if (root != NULL) {
    LNR_BST(root->left);
    cout << " " << root->data;
    LNR_BST(root->right);
  }
}

void timPhanTuTheMang_BST(BST*& root, BST*& p) {
  if (root->right != NULL)
    timPhanTuTheMang_BST(root->right, p);
  else {
    p->data = root->data;
    p = root;
    root = root->left;
  }
}

void xoaNodeTrongCay_BST(BST*& root, int x) {
  if (root == NULL)
    return;
  if (x > root->data)
    xoaNodeTrongCay_BST(root->right, x);
  else if (x < root->data)
    xoaNodeTrongCay_BST(root->left, x);
  else {
    BST* p = root;
    if (p->left == NULL)
      root = p->right;
    else if (p->right == NULL)
      root = p->left;
    else
      timPhanTuTheMang_BST(root->left, p);
    delete p;
  }
}

BST* timKiemNode_BST(BST* root, int x) {
  if (root == NULL)
    return NULL;
  if (x > root->data)
    return timKiemNode_BST(root->right, x);
  else if (x < root->data)
    return timKiemNode_BST(root->left, x);
  else
    return root;
}

void xoayTrai_BST(BST*& root) {
  if (root == NULL || root->right == NULL)
    return;
  BST* p = root->right;
  root->right = p->left;
  p->left = root;
  root = p;
}

void xoayPhai_BST(BST*& root) {
  if (root == NULL || root->left == NULL)
    return;
  BST* p = root->left;
  root->left = p->right;
  p->right = root;
  root = p;
}



int tinhChieuCaoCuaCay_BST(BST* root) {
  if (root == NULL)
    return 0;
  int left = tinhChieuCaoCuaCay_BST(root->left);
  int right = tinhChieuCaoCuaCay_BST(root->right);

  return left > right ? left + 1 : right + 1;
}

int tinhTongCacNutChan_BST(BST* root) {
  queue<BST*> q;
  if (root != NULL)
    q.push(root);
  int sum = 0;
  while (!q.empty()) {
    BST* p = q.front();
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

int kiemtraSNT_BST(int n) {
  if (n < 2)
    return 0;
  else if (n > 2) {
    if (n % 2 == 0)
      return 0;
    for (int i = 3; i <= (int)sqrt((double)n); i += 2) {
      if (n % i == 0)
        return 0;
    }
  }
  return 1;
}

int demSoLuongSoNguyenTo_BST(BST* root) {
  queue<BST*> q;
  if (root != NULL)
    q.push(root);

  int dem = 0;
  while (!q.empty()) {
    BST* p = q.front();
    if (kiemtraSNT_BST(p->data) == 1)
      dem++;
    q.pop();
    if (p->left != NULL)
      q.push(p->left);
    if (p->right != NULL)
      q.push(p->right);
  }
  return dem;
}

void init_AVL(AVL*& root) {
  root = NULL;
}

AVL* getNode_AVL(int x) {
  AVL* p = new AVL;
  if (p == NULL)
    return NULL;
  p->data = x;
  p->left = p->right = NULL;
  p->cha = NULL;
  p->thuTuDuyet = 0;
  return p;
}

void quayTrai_AVL(AVL*& root) {
  AVL* cha = root->cha;
  AVL* pivot = root->right;
  root->right = pivot->left;
  if (pivot->left != NULL)
    pivot->left->cha = root;
  pivot->left = root;
  root->cha = pivot;
  root = pivot;
  root->cha = cha;
}

void quayPhai_AVL(AVL*& root) {
  AVL* cha = root->cha;
  AVL* pivot = root->left;
  root->left = pivot->right;
  if (pivot->right != NULL)
    pivot->right->cha = root;
  pivot->right = root;
  root->cha = pivot;
  root = pivot;
  root->cha = cha;
}

int themNodeVaoCay_AVL(AVL*& root, int x) {
  int ketqua;
  if (root != NULL) {
    if (x > root->data)
      ketqua = themNodeVaoCay_AVL(root->right, x);
    else if (x < root->data)
      ketqua = themNodeVaoCay_AVL(root->left, x);
    else
      return 0;
  }
  else {
    AVL* con = getNode_AVL(x);
    if (con == NULL)
      return -1;
    root = con;
    return 1;
  }

  if (ketqua == 1) {
    int kq = canBangNode_AVL(root);
    if (kq == 1)
      return 2;
    else if (kq == 0)
      return 1;
  }
}

int tinhChieuCaoCay_AVL(AVL* root) {
  if (root == NULL)
    return 0;
  int left = tinhChieuCaoCay_AVL(root->left);
  int right = tinhChieuCaoCay_AVL(root->right);
  return left > right ? left + 1 : right + 1;
}

int canBangNode_AVL(AVL*& root) {
  int chieucaocontrai = 0;
  int chieucaoconphai = 0;
  if (root->left != NULL)
    chieucaocontrai = tinhChieuCaoCay_AVL(root->left);
  if (root->right != NULL)
    chieucaoconphai = tinhChieuCaoCay_AVL(root->right);
  if (abs(chieucaocontrai - chieucaoconphai) > 1) {
    if (chieucaocontrai > chieucaoconphai) {
      int chieucaocontrai_2 = 0;
      int chieucaoconphai_2 = 0;
      if (root->left->left != NULL)
        chieucaocontrai_2 = tinhChieuCaoCay_AVL(root->left->left);
      if (root->left->right != NULL)
        chieucaoconphai_2 = tinhChieuCaoCay_AVL(root->left->right);
      if (chieucaocontrai_2 >= chieucaoconphai_2)
        quayPhai_AVL(root);
      else {
        quayTrai_AVL(root->left);
        quayPhai_AVL(root);
      }
    }
    else {
      int chieucaocontrai_2 = 0;
      int chieucaoconphai_2 = 0;
      if (root->right->left != NULL)
        chieucaocontrai_2 = tinhChieuCaoCay_AVL(root->right->left);
      if (root->right->right != NULL)
        chieucaoconphai_2 = tinhChieuCaoCay_AVL(root->right->right);
      if (chieucaoconphai_2 >= chieucaocontrai_2)
        quayTrai_AVL(root);
      else {
        quayPhai_AVL(root->right);
        quayTrai_AVL(root);
      }
    }
    return 1;
  }
  return 0;
}

void NLR_AVL(AVL* root) {
  if (root != NULL) {
    cout << " " << root->data;
    NLR_AVL(root->left);
    NLR_AVL(root->right);
  }
}
