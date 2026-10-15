namespace DotNET
{
    internal class DienThoai
    {
        public string maDT { get; set; }
        public string tenDT { get; set; }
        public double giaBan { get; set; }
        public string hangSX { get; set; }

        public DienThoai()
            : this("", "", 0, "")
        {

        }

        public DienThoai(string maDT, string tenDT, double giaBan, string hangSX)
        {
            this.maDT = maDT;
            this.tenDT = tenDT;
            this.giaBan = giaBan;
            this.hangSX = hangSX;
        }

        public virtual double TinhGia()
        {
            return giaBan;
        }
    }
}


using System;

namespace DotNET
{
    internal class DienThoaiGiam : DienThoai
    {
        public float phanTramGiam { get; set; }

        public DienThoaiGiam()
        {
        }

        public DienThoaiGiam(string maDT, string tenDT, double giaBan,
            string hangSX, float phanTramGiam)
            : base(maDT, tenDT, giaBan, hangSX)
        {
            this.phanTramGiam = phanTramGiam;
        }

        public void NhapThongTin()
        {
            maDT = NhapChuoi("Nhap ma dien thoai: ");
            tenDT = NhapChuoi("Nhap ten san pham: ");

            double gia;
            do
            {
                Console.Write("Nhap gia ban goc (>= 0): ");
            }
            while (!double.TryParse(Console.ReadLine(), out gia)
                || double.IsNaN(gia) || double.IsInfinity(gia) || gia < 0);
            giaBan = gia;

            hangSX = NhapChuoi("Nhap hang san xuat: ");

            float giam;
            do
            {
                Console.Write("Nhap phan tram giam (0 - 100): ");
            }
            while (!float.TryParse(Console.ReadLine(), out giam)
                || float.IsNaN(giam) || float.IsInfinity(giam)
                || giam < 0 || giam > 100);
            phanTramGiam = giam;
        }

        private static string NhapChuoi(string thongBao)
        {
            string giaTri;
            do
            {
                Console.Write(thongBao);
                giaTri = (Console.ReadLine() ?? "").Trim();
            }
            while (giaTri.Length == 0);
            return giaTri;
        }

        public override double TinhGia()
        {
            return giaBan * (1 - phanTramGiam / 100.0);
        }

        public string LoaiGiam()
        {
            if (phanTramGiam > 30)
                return "Sieu sale";
            if (phanTramGiam >= 10)
                return "Khuyen mai";
            return "Binh thuong";
        }

        public static void HienThiTieuDe()
        {
            Console.WriteLine("{0,-12} {1,-25} {2,-15} {3,18} {4,10} {5,18} {6,-12}",
                "Ma DT", "Ten san pham", "Hang SX", "Gia ban goc", "Giam (%)", "Gia sau giam", "Xep loai");
        }

        public void HienThi()
        {
            Console.WriteLine("{0,-12} {1,-25} {2,-15} {3,18:N2} {4,10} {5,18:N2} {6,-12}",
                maDT, tenDT, hangSX, giaBan, phanTramGiam, TinhGia(), LoaiGiam());
        }
    }
}


using System;
using System.Collections.Generic;

namespace DotNET
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<DienThoaiGiam> danhSach = new List<DienThoaiGiam>();

            while (true)
            {
                Console.WriteLine("\n========== QUAN LY DIEN THOAI ==========");
                Console.WriteLine("1. Them dien thoai moi");
                Console.WriteLine("2. Hien thi tat ca theo gia sau giam tang dan");
                Console.WriteLine("3. Liet ke dien thoai theo muc gia toi da");
                Console.WriteLine("4. Tim kiem theo ma dien thoai");
                Console.WriteLine("0. Thoat");
                Console.Write("Chon chuc nang: ");

                string luaChon = Console.ReadLine();
                if (luaChon == null)
                    return;

                switch (luaChon.Trim())
                {
                    case "1":
                        ThemDienThoai(danhSach);
                        break;
                    case "2":
                        List<DienThoaiGiam> danhSachSapXep = new List<DienThoaiGiam>(danhSach);
                        SapXepTheoGia(danhSachSapXep);
                        HienThiDanhSach(danhSachSapXep);
                        break;
                    case "3":
                        LocTheoGia(danhSach);
                        break;
                    case "4":
                        TimTheoMa(danhSach);
                        break;
                    case "0":
                        Console.WriteLine("Da thoat chuong trinh.");
                        return;
                    default:
                        Console.WriteLine("Lua chon khong hop le. Vui long chon tu 0 den 4.");
                        break;
                }
            }
        }

        private static void ThemDienThoai(List<DienThoaiGiam> danhSach)
        {
            DienThoaiGiam dienThoai = new DienThoaiGiam();
            dienThoai.NhapThongTin();

            foreach (DienThoaiGiam dt in danhSach)
            {
                if (string.Equals(dt.maDT, dienThoai.maDT, StringComparison.OrdinalIgnoreCase))
                {
                    Console.WriteLine("Ma dien thoai da ton tai. Khong them vao danh sach.");
                    return;
                }
            }

            danhSach.Add(dienThoai);
            Console.WriteLine("Them dien thoai thanh cong.");
        }

        private static void SapXepTheoGia(List<DienThoaiGiam> danhSach)
        {
            danhSach.Sort((a, b) => a.TinhGia().CompareTo(b.TinhGia()));
        }

        private static void HienThiDanhSach(List<DienThoaiGiam> danhSach)
        {
            if (danhSach.Count == 0)
            {
                Console.WriteLine("Khong co dien thoai nao de hien thi.");
                return;
            }

            DienThoaiGiam.HienThiTieuDe();
            foreach (DienThoaiGiam dienThoai in danhSach)
                dienThoai.HienThi();
        }

        private static void LocTheoGia(List<DienThoaiGiam> danhSach)
        {
            double giaToiDa;
            do
            {
                Console.Write("Nhap muc gia toi da (>= 0): ");
            }
            while (!double.TryParse(Console.ReadLine(), out giaToiDa)
                || double.IsNaN(giaToiDa) || double.IsInfinity(giaToiDa)
                || giaToiDa < 0);

            List<DienThoaiGiam> ketQua = new List<DienThoaiGiam>();
            foreach (DienThoaiGiam dienThoai in danhSach)
            {
                if (dienThoai.TinhGia() <= giaToiDa)
                    ketQua.Add(dienThoai);
            }

            SapXepTheoGia(ketQua);
            HienThiDanhSach(ketQua);
        }

        private static void TimTheoMa(List<DienThoaiGiam> danhSach)
        {
            Console.Write("Nhap ma dien thoai can tim: ");
            string maCanTim = (Console.ReadLine() ?? "").Trim();
            foreach (DienThoaiGiam dienThoai in danhSach)
            {
                if (string.Equals(dienThoai.maDT, maCanTim, StringComparison.OrdinalIgnoreCase))
                {
                    DienThoaiGiam.HienThiTieuDe();
                    dienThoai.HienThi();
                    return;
                }
            }

            Console.WriteLine("Khong tim thay dien thoai co ma nay.");
        }
    }
}
