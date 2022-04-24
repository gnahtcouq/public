int main() {
  BST* root;
  init_BST(root);
  int a[] = { 20,30,25,10,35,32,38,40,34,28,18,15,5,22 };
  int n = sizeof(a) / sizeof(a[0]);
  cout << "\nCau 1. BST";
  for (int i = 0; i < n; ++i)
    themNodeVaoCay_BST(root, a[i]);
  cout << "\nNLR: ";
  LNR_BST(root);

  xoaNodeTrongCay_BST(root, 15);
  cout << "\nNLR sau khi xoa Node 15: ";
  LNR_BST(root);

  cout << "\nNLR sau khi xoay trai Node 20: ";
  BST* xt = timKiemNode_BST(root, 20);
  xoayTrai_BST(xt);
  LNR_BST(root);

  cout << "\nNLR sau khi xoay phai Node 10: ";
  BST* xp = timKiemNode_BST(root, 10);
  xoayPhai_BST(xp);
  LNR_BST(root);



  int chieuCaoCay = tinhChieuCaoCuaCay_BST(root);
  cout << "\nCay co chieu cao = " << chieuCaoCay;
  int tongNutChan = tinhTongCacNutChan_BST(root);
  cout << "\nTong cac nut chan = " << tongNutChan;
  int demNguyenTo = demSoLuongSoNguyenTo_BST(root);
  cout << "\nSo luong so nguyen to = " << demNguyenTo;

  AVL* nut;
  init_AVL(nut);
  cout << "\n\n\nCau 2. AVL";
  int b[] = { 1,2,3,4,5,6,7,8,9 };
  int m = sizeof(b) / sizeof(b[0]);
  for (int i = 0; i < m; ++i)
    themNodeVaoCay_AVL(nut, b[i]);
  cout << "\nNLR: ";
  NLR_AVL(nut);

  system("pause");
  return 0;
}
