using System;
using System.Linq;
using System.Windows.Forms;
using System.Xml.Linq;

namespace Valid
{
    public partial class Form1 : Form
    {
        string path = @"..\..\bangdiem.xml";
        XDocument doc;

        public Form1()
        {
            InitializeComponent();
        }

        // 3b. Load dữ liệu lên lưới
        void LoadData()
        {
            doc = XDocument.Load(path);
            dgvBangDiem.Rows.Clear();
            int stt = 1;

            foreach (var sv in doc.Descendants("sinhvien"))
            {
                dgvBangDiem.Rows.Add(
                    stt++,
                    (string)sv.Attribute("masv"),
                    (string)sv.Attribute("monhoc"),
                    (string)sv.Element("diemlan1"),
                    (string)sv.Element("diemlan2")
                );
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Gắn sự kiện cho bảng và các nút Sửa, Xóa, Thoát
            dgvBangDiem.CellClick += dgvBangDiem_CellClick;
            btnSua.Click += btnSua_Click;
            btnXoa.Click += btnXoa_Click;
            btnThoat.Click += btnThoat_Click;

            if (cbMonHoc.Items.Count == 0)
                cbMonHoc.Items.AddRange(new string[] { "Lập trình Windows", "Lập trình Java", "Cơ sở dữ liệu" });
            cbMonHoc.SelectedIndex = 0;

            LoadData();
        }

        // 3c. Nút THÊM (Có kiểm tra chống trùng mã)
        private void btnThem_Click(object sender, EventArgs e)
        {
            var sv = doc.Descendants("sinhvien").FirstOrDefault(x => (string)x.Attribute("masv") == txtMaSV.Text);
            if (sv != null)
            {
                MessageBox.Show("Mã sinh viên này đã tồn tại!");
                return;
            }

            doc.Root.Add(new XElement("sinhvien",
                new XAttribute("masv", txtMaSV.Text),
                new XAttribute("monhoc", cbMonHoc.Text),
                new XElement("diemlan1", txtDiemLan1.Text),
                new XElement("diemlan2", txtDiemLan2.Text)
            ));

            doc.Save(path);
            LoadData();
            MessageBox.Show("Thêm thành công!");
        }

        // 3d. Bấm vào dòng trên lưới hiển thị lên ô nhập
        private void dgvBangDiem_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0 && dgvBangDiem.Rows[e.RowIndex].Cells[1].Value != null)
            {
                var r = dgvBangDiem.Rows[e.RowIndex];
                txtMaSV.Text = r.Cells[1].Value.ToString();
                cbMonHoc.Text = r.Cells[2].Value.ToString();
                txtDiemLan1.Text = r.Cells[3].Value.ToString();
                txtDiemLan2.Text = r.Cells[4].Value.ToString();
            }
        }

        // 3e. Nút SỬA: Tìm rồi set giá trị mới
        private void btnSua_Click(object sender, EventArgs e)
        {
            var sv = doc.Descendants("sinhvien").FirstOrDefault(x => (string)x.Attribute("masv") == txtMaSV.Text);
            if (sv != null)
            {
                sv.SetAttributeValue("monhoc", cbMonHoc.Text);
                sv.SetElementValue("diemlan1", txtDiemLan1.Text);
                sv.SetElementValue("diemlan2", txtDiemLan2.Text);

                doc.Save(path);
                LoadData();
                MessageBox.Show("Sửa thành công!");
            }
        }

        // 3f. Nút XÓA: Tìm rồi gọi Remove()
        private void btnXoa_Click(object sender, EventArgs e)
        {
            var sv = doc.Descendants("sinhvien").FirstOrDefault(x => (string)x.Attribute("masv") == txtMaSV.Text);
            if (sv != null)
            {
                sv.Remove();
                doc.Save(path);
                LoadData();
                MessageBox.Show("Xóa thành công!");
            }
        }

        // Nút THOÁT
        private void btnThoat_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void dgvBangDiem_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}