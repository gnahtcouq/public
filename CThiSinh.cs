using System;
using System.Collections.Generic;
using System.Text;

namespace bai6 {
    public enum KieuKetQua { Dat, KhongDat }
    public class CThiSinh {
        protected string m_MaTS;
        protected string m_Hoten;
        public string MaTS {
            get { return m_MaTS; }
            set { m_MaTS = value; }
        }
        public string Hoten {
            get { return m_Hoten; }
            set { m_Hoten = value; }
        }
        public CThiSinh() {
            m_MaTS = "";
            m_Hoten = "";
        }
        public CThiSinh(string ma, string ht) {
            m_MaTS = ma;
            m_Hoten = ht;
        }
        public virtual double TongDiem() {
            return 0;
        }
        public virtual KieuKetQua KetQua() {
            return KieuKetQua.KhongDat;
        }

        public virtual bool laKhoiA() {
            return false;
        }

        public virtual bool laKhoiNangKhieu() {
            return false;
        }
    }
}
