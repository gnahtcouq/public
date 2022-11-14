using System;
using System.Collections.Generic;
using System.Text;

namespace bai6 {
    public class CKhoiA:CThiSinh {
        protected double m_DiemToan;
        protected double m_DiemLy;
        protected double m_DiemHoa;
        public double DiemToan {
            get { return m_DiemToan; }
            set { m_DiemToan = value; }
        }
        public double DiemLy {
            get { return m_DiemLy; }
            set { m_DiemLy = value; }
        }
        public double DiemHoa {
            get { return m_DiemHoa; }
            set { m_DiemHoa = value; }
        }
        public CKhoiA() : base() {
            m_DiemToan = 0;
            m_DiemLy = 0;
            m_DiemHoa = 0;
        }
        public CKhoiA(string ma, string ht, double toan, double ly, double hoa) : base (ma, ht) {
            m_DiemToan = toan;
            m_DiemLy = ly;
            m_DiemHoa = hoa;
        }

        public override double TongDiem() {
            return m_DiemToan + m_DiemLy + m_DiemHoa;
        }
        public override KieuKetQua KetQua() {
            if (TongDiem() >= 18.5)
                return KieuKetQua.Dat;
            else
                return KieuKetQua.KhongDat;
        }
        public override bool laKhoiA() {
            return true;
        }
        public override bool laKhoiNangKhieu() {
            return false;
        }
    }
}
