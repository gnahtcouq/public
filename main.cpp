#include "header.h"

extern int maTran[MAX][MAX];
extern int D[MAX][MAX];
extern int P[MAX][MAX];
extern int soNut;

int main() {
	int chon, x, y, i, j, ts, choice;
	char c;
	int p, q, r, dinh;
	int ngan, duongDi[MAX];
	soNut = 0;
	do {
		cout << "\n1. Tao do thi moi";
		cout << "\n2. Them mot nut";
		cout << "\n3. Xoa mot nut";
		cout << "\n4. Them mot cung";
		cout << "\n5. Xoa mot cung";
		cout << "\n6. Xoa toan bo do thi";
		cout << "\n7. Bac cua mot dinh vao";
		cout << "\n8. Bac cua mot dinh ra";
		cout << "\n9. Dem so nut";
		cout << "\n10. Tim duong di ngan nhat (Floyd)";
		cout << "\n11. Tim duong di ngan nhat (Dijkstra)";
		cout << "\n12. Tim kiem nut";
		cout << "\n13. Hien thi canh ke do thi";
		cout << "\n14. Duyet do thi";
		cout << "\n0. Thoat";
		cout << "\nChon chuc nang ban can: ";
		cin >> chon;
		switch (chon) {
		case 1:
			cout << "\nDo thi moi co bao nhieu nut = ";
			cin >> soNut;
			init();
			docMaTran();
			while (true) {
				cout << "Nhap x, y lon hon " << soNut << " de thoat" << endl;
				cout << "Nhap nut dau x = ";
				cin >> x;
				cout << "Nhap nut cuoi y = ";
				cin >> y;
				if (x < soNut && y < soNut) {
					cout << "Trong so cua cung (" << x << "," << y << ") = ";
					cin >> ts;
					taoCung(x, y, ts);
				}
				else
					break;
			}
			ghiMaTran();
			break;
		case 2:
			cout << "\nThem mot nut moi";
			if (soNut < MAX) {
				docMaTran();
				soNut++;
				cout << "\nSo nut hien tai = " << soNut;
				for (int i = 0; i < soNut - 1; i++)
					maTran[i][soNut - 1] = -1;
				for (int i = 0; i < soNut - 1; i++)
					maTran[soNut - 1][i] = -1;
				ghiMaTran();
			}
			else
				cout << "\nKhong the them nut moi";
			break;
		case 3:
			cout << "\nXoa mot nut da co trong do thi";
			if (soNut < MAX) {
				docMaTran();
				soNut--;
				cout << "\nSo nut hien tai = " << soNut;
				ghiMaTran();
			}
			else
				cout << "\nKhong the xoa nut";
			break;
		case 4:
			docMaTran();
			cout << "\nNhap cung can them x = ";
			cin >> x;
			cout << "\nNhap cung can them y = ";
			cin >> y;
			if (x > soNut && y > soNut)
				cout << "\nKhong hop le";
			else {
				cout << "Trong so cua cung (" << x << "," << y << ") = ";
				cin >> ts;
				maTran[x][y] = ts;
			}
			ghiMaTran();
			break;
		case 5:
			cout << "\nNhap cung can xoa x = ";
			cin >> x;
			cout << "\nNhap cung can xoa y = ";
			cin >> y;
			docMaTran();
			xoaCung(x, y);
			ghiMaTran();
			break;
		case 6:
			cout << "\nBan co chac khong?";
			cin >> c;
			if (c == 'c' || c == 'C') {
				init();
				soNut = 0;
			}
			break;
		case 7:
			docMaTran();
			cout << "\nBac cua mot dinh co cung vao";
			cout << "\nNhap dinh can biet = ";
			cin >> dinh;
			cout << "\nBac cua dinh " << dinh << " = " << bacDinhVao(dinh);
			break;
		case 8:
			docMaTran();
			cout << "\nBac cua mot dinh co cung ra";
			cout << "\nNhap dinh can biet = ";
			cin >> dinh;
			cout << "\nBac cua dinh " << dinh << " = " << bacDinhRa(dinh);
			break;
		case 9:
			cout << "\nSo nut co tren do thi la = " << soNut;
			break;
		case 10:
			docMaTran();
			cout << "\nNhap nut di x = ";
			cin >> x;
			cout << "\nNhap nut den y = ";
			cin >> y;
			if (x >= soNut || y >= soNut)
				cout << "Khong hop le";
			else {
				floyd();
				cout << "\nChieu dai ngan nhat tu " << x << " den nut " << y << " la " << D[x][y];
				cout << "\nLo trinh duong di: ";
				inLoTrinh(x, y);
			}
			break;
		case 11:
			docMaTran();
			cout << "\nNhap nut di x = ";
			cin >> x;
			cout << "\nNhap nut den y = ";
			cin >> y;
			dijkstra(x, y, &ngan, duongDi);
			cout << "\nDuong di ngan nhat tu " << x << " den nut " << y << " la " << ngan;
			cout << "\nLo trinh ";
			i = y;
			while (i != x) {
				cout << i << " <- ";
				i = duongDi[i];
			}
			cout << x;
			break;
		case 12:
			cout << "\nNhap nut muon tim: ";
			cin >> choice;
			if (choice >= 0 && choice < soNut)
				cout << "\nTim thay nut " << choice;
			else
				cout << "\nKhong tim thay";
			break;
		case 13:
			for (int i = 0; i < soNut; i++) {
				for (int j = 0; j < soNut; j++)
					if (maTran[i][j] != 0 && maTran[i][j] != -1)
						cout << "\nSo canh ke cua " << i << " la " << j;
				cout << endl;
			}
			break;
		case 14:
			cout << "\nXem ma tran";
			docMaTran();
			xemMaTran();
			break;
		}
	} while (chon != 0);

	return 0;
}