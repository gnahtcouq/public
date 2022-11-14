using System;
using System.Collections.Generic;
using System.Text;

namespace bai6 {
    class CKhoiNangKhieu : CThiSinh {
        protected double m_DiemToan;
        protected double m_DiemNangKhieu;
        public double DiemToan {
            get { return m_DiemToan; }
            set { m_DiemToan = value; }
        }
        public double DiemNangKhieu {
            get { return m_DiemNangKhieu; }
            set { m_DiemNangKhieu = value; }
        }
        public CKhoiNangKhieu() : base() {
            m_DiemToan = 0;
            m_DiemNangKhieu = 0;
        }
        public CKhoiNangKhieu(string ma, string ht, double toan, double nangkhieu) : base(ma,ht) {
            m_DiemToan = toan;
            m_DiemNangKhieu = nangkhieu;
        }
        public override double TongDiem() {
            return m_DiemToan + m_DiemNangKhieu * 2;
        }
        public override KieuKetQua KetQua() {
            if (TongDiem() >= 17)
                return KieuKetQua.Dat;
            else
                return KieuKetQua.KhongDat;
        }
        public override bool laKhoiA() {
            return false;
        }
        public override bool laKhoiNangKhieu() {
            return true;
        }
    }
}
