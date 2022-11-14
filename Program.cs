using System;
using System.Collections.Generic;

namespace bai6 {
    class Program {

        // Cau a
        static int getSoThiSinhKhoiNangkhieu(List<CThiSinh> ds) {
            int count = 0;
            foreach (CThiSinh thiSinh in ds)
                if (thiSinh.laKhoiNangKhieu() == true)
                    count++;
            return count;
        }

        // Cau b
        static List<CThiSinh> getDSThiSinhKhoiA(List<CThiSinh> ds) {
            List<CThiSinh> thiSinh = new List<CThiSinh>();
            foreach (CThiSinh i in ds)
                if (i.laKhoiA() == true)
                    thiSinh.Add(i);
            return thiSinh;
        }

        // Cau c
        static double getDiemLonNhatKhoiA(List<CThiSinh> ds) {
            double max = 0;
            foreach (CThiSinh i in ds)
                if (i.laKhoiA() == true)
                    if (i.TongDiem() > max)
                        max = i.TongDiem();
            return max;
        }
        // Cau d
        static List<CThiSinh> getDSThiSinhDat(List<CThiSinh> ds) {
            List<CThiSinh> tam = new List<CThiSinh>();
            foreach (CThiSinh i in ds)
                if (i.KetQua() == KieuKetQua.Dat)
                    tam.Add(i);
            return tam;
        }

        // Cau e
        static List<CThiSinh> getDSThiSinhNangKhieuKhongDat(List<CThiSinh> ds) {
            List<CThiSinh> tam = new List<CThiSinh>();
            foreach (CThiSinh i in ds)
                if (i.laKhoiNangKhieu() && i.KetQua() == KieuKetQua.KhongDat)
                    tam.Add(i);
            return tam;
        }

        // Cau f

        static void Main(string[] args) {
            List<CThiSinh> ds = new List<CThiSinh>();
            ds.Add(new CKhoiA("DH52", "Thang", 3, 3, 3));
            ds.Add(new CKhoiA("DH53", "Son", 1, 1.5, 2));
            ds.Add(new CKhoiA("DH54", "Lam", 7, 7, 7.5));
            ds.Add(new CKhoiNangKhieu("DH55", "Toan", 10, 0));
            ds.Add(new CKhoiNangKhieu("DH56", "Tuan", 10, 10));
            ds.Add(new CKhoiNangKhieu("DH57", "Tan", 9.5, 10));

            // Cau a
            Console.WriteLine("\nCau a. So thi sinh lop nang khieu = " + getSoThiSinhKhoiNangkhieu(ds));
            // Cau b
            Console.WriteLine("\nCau b. Danh sach thi sinh khoi A");
            Console.WriteLine("\t-------------------------------------");
            Console.WriteLine("\tMaTS" + "\t" + "Ho ten" + "\t" + "Toan" + "\t" + "Ly" + "\t" + "Hoa");
            Console.WriteLine("\t-------------------------------------");
            foreach (CKhoiA thiSinh in getDSThiSinhKhoiA(ds))
                Console.WriteLine("\t" + thiSinh.MaTS + "\t" + thiSinh.Hoten + "\t" + thiSinh.DiemToan + "\t" + thiSinh.DiemLy + "\t" + thiSinh.DiemHoa);
            // Cau c
            Console.WriteLine("\nCau c. Diem thi lon nhat cua khoi A = " + getDiemLonNhatKhoiA(ds));
            // Cau d
            Console.WriteLine("\nCau d. Danh sach thi dat");
            Console.WriteLine("\t-------------------------------------");
            Console.WriteLine("\tMaTS" + "\t" + "Ho ten");
            Console.WriteLine("\t-------------------------------------");
            foreach (CThiSinh thiSinh in getDSThiSinhDat(ds))
                Console.WriteLine("\t" + thiSinh.MaTS + "\t" + thiSinh.Hoten);
            // Cau e
            Console.WriteLine("\nCau e. Danh sach thi sinh nang khieu co ket qua khong dat trong danh sach thi sinh");
            Console.WriteLine("\t-------------------------------------");
            Console.WriteLine("\tMaTS" + "\t" + "Ho ten");
            Console.WriteLine("\t-------------------------------------");
            foreach (CThiSinh thiSinh in getDSThiSinhNangKhieuKhongDat(ds))
                Console.WriteLine("\t" + thiSinh.MaTS + "\t" + thiSinh.Hoten);
            // Cau f

        }
    }
}
