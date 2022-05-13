void dijkstra(int nutDi, int nutDen, int* ngan, int duongDi[]) {
  int i, k, kc, nutHienTai, min, kcMoi;
  int tapNut[MAXNODES];
  int kcNgan[MAXNODES];

  for (i = 0; i < soNut; ++i) {
    tapNut[i] = FALSE;
    kcNgan[i] = VOCUNG;
  }
  tapNut[nutDi] = TRUE;
  kcNgan[nutDi] = 0;
  nutHienTai = nutDi;
  while (nutHienTai != nutDen) {
    min = VOCUNG;
    kc = kcNgan[nutHienTai];
    for (i = 0; i < soNut; i++) {
      if (tapNut[i] == FALSE) {
        kcMoi = kc + trongSo[nutHienTai][i];
        if (kcMoi < kcNgan[i]) {
          kcNgan[i] = kcMoi;
          duongDi[i] = nutHienTai;
        }
        if (kcNgan[i] < min) {
          min = kcNgan[i];
          k = i;
        }
      }
    }
    nutHienTai = k;
    tapNut[nutHienTai] = TRUE;
  }
  *ngan = kcNgan[nutDen];
}
