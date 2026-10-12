<?xml version="1.0" encoding="UTF-8"?>
<?xml-stylesheet type="text/xsl" href="NhanVien.xslt"?>
<DanhSachNhanVien xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
                  xsi:noNamespaceSchemaLocation="NhanVien.xsd">
    <NhanVien>
        <MaNV>nv01</MaNV>
        <HoTen>
            <HoDem>Trần Đức</HoDem>
            <Ten>Minh</Ten>
        </HoTen>
        <GioiTinh>Nam</GioiTinh>
        <NgaySinh>12-03-1998</NgaySinh>
        <MaPhong>HCKT01</MaPhong>
        <Luong>9500000</Luong>
    </NhanVien>
    <NhanVien>
        <MaNV>nv02</MaNV>
        <HoTen>
            <HoDem>Nguyễn Thị</HoDem>
            <Ten>Hương</Ten>
        </HoTen>
        <GioiTinh>Nữ</GioiTinh>
        <NgaySinh>06-11-1999</NgaySinh>
        <MaPhong>NHNS02</MaPhong>
        <Luong>10500000</Luong>
    </NhanVien>
    <NhanVien>
        <MaNV>nv03</MaNV>
        <HoTen>
            <HoDem>Lê Văn</HoDem>
            <Ten>Bình</Ten>
        </HoTen>
        <GioiTinh>Nam</GioiTinh>
        <NgaySinh>21-07-1997</NgaySinh>
        <MaPhong>KDTO03</MaPhong>
        <Luong>8000000</Luong>
    </NhanVien>
    <NhanVien>
        <MaNV>nv04</MaNV>
        <HoTen>
            <HoDem>Phạm Ngọc</HoDem>
            <Ten>Anh</Ten>
        </HoTen>
        <GioiTinh>Nữ</GioiTinh>
        <NgaySinh>15-05-2000</NgaySinh>
        <MaPhong>HCKT01</MaPhong>
        <Luong>9000000</Luong>
    </NhanVien>
    <NhanVien>
        <MaNV>nv05</MaNV>
        <HoTen>
            <HoDem>Đỗ Quốc</HoDem>
            <Ten>Tuấn</Ten>
        </HoTen>
        <GioiTinh>Nam</GioiTinh>
        <NgaySinh>08-09-1998</NgaySinh>
        <MaPhong>KDTO03</MaPhong>
        <Luong>11200000</Luong>
    </NhanVien>
    <NhanVien>
        <MaNV>nv06</MaNV>
        <HoTen>
            <HoDem>Vũ Thu</HoDem>
            <Ten>Trang</Ten>
        </HoTen>
        <GioiTinh>Nữ</GioiTinh>
        <NgaySinh>24-12-2001</NgaySinh>
        <MaPhong>NHNS02</MaPhong>
        <Luong>8800000</Luong>
    </NhanVien>
</DanhSachNhanVien>


<?xml version="1.0" encoding="UTF-8"?>

<xs:schema
    xmlns:xs="http://www.w3.org/2001/XMLSchema">

    <!-- MaNV: nv + 2 chu so -->
    <xs:simpleType name="KieuMaNV">
        <xs:restriction base="xs:string">
            <xs:pattern value="nv[0-9]{2}"/>
        </xs:restriction>
    </xs:simpleType>

    <!-- GioiTinh: Nam hoac Nữ -->
    <xs:simpleType name="KieuGioiTinh">
        <xs:restriction base="xs:string">
            <xs:enumeration value="Nam"/>
            <xs:enumeration value="Nữ"/>
        </xs:restriction>
    </xs:simpleType>

    <!-- NgaySinh: DD-MM-YYYY -->
    <xs:simpleType name="KieuNgaySinh">
        <xs:restriction base="xs:string">
            <xs:pattern value="[0-9]{2}-[0-9]{2}-[0-9]{4}"/>
        </xs:restriction>
    </xs:simpleType>

    <!-- MaPhong: 4 chu hoa + 2 chu so -->
    <xs:simpleType name="KieuMaPhong">
        <xs:restriction base="xs:string">
            <xs:pattern value="[A-Z]{4}[0-9]{2}"/>
        </xs:restriction>
    </xs:simpleType>

    <!-- Luong: so nguyen lon hon 0 -->
    <xs:simpleType name="KieuLuong">
        <xs:restriction base="xs:integer">
            <xs:minExclusive value="0"/>
        </xs:restriction>
    </xs:simpleType>

    <!-- Cau truc danh sach nhan vien -->
    <xs:element name="DanhSachNhanVien">
        <xs:complexType>
            <xs:sequence>

                <xs:element name="NhanVien"
                            minOccurs="1"
                            maxOccurs="unbounded">

                    <xs:complexType>
                        <xs:sequence>

                            <xs:element name="MaNV"
                                        type="KieuMaNV"/>

                            <xs:element name="HoTen">
                                <xs:complexType>
                                    <xs:sequence>
                                        <xs:element name="HoDem"
                                                    type="xs:string"/>
                                        <xs:element name="Ten"
                                                    type="xs:string"/>
                                    </xs:sequence>
                                </xs:complexType>
                            </xs:element>

                            <xs:element name="GioiTinh"
                                        type="KieuGioiTinh"/>

                            <xs:element name="NgaySinh"
                                        type="KieuNgaySinh"/>

                            <xs:element name="MaPhong"
                                        type="KieuMaPhong"/>

                            <xs:element name="Luong"
                                        type="KieuLuong"/>

                        </xs:sequence>
                    </xs:complexType>

                </xs:element>

            </xs:sequence>
        </xs:complexType>
    </xs:element>

</xs:schema>

<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:output method="html" encoding="UTF-8"/>

    <xsl:template match="/">
        <html>
            <head>
                <meta charset="UTF-8"/>
                <title>Danh sach nhan vien</title>
            </head>

            <body>
                <h2>DANH SÁCH NHÂN VIÊN</h2>

                <table border="1" cellpadding="8">

                    <tr>
                        <th>STT</th>
                        <th>MaNV</th>
                        <th>HoTen</th>
                        <th>GioiTinh</th>
                        <th>NgaySinh</th>
                        <th>MaPhong</th>
                        <th>Luong</th>
                    </tr>

                    <xsl:for-each select="DanhSachNhanVien/NhanVien">

                        <xsl:sort select="HoTen/Ten"
                                  order="ascending"
                                  data-type="text"
                                  lang="vi"/>

                        <tr>
                            <td>
                                <xsl:value-of select="position()"/>
                            </td>

                            <td>
                                <xsl:value-of select="MaNV"/>
                            </td>

                            <td>
                                <xsl:value-of select="concat(HoTen/HoDem, ' ', HoTen/Ten)"/>
                            </td>

                            <td>
                                <xsl:value-of select="GioiTinh"/>
                            </td>

                            <td>
                                <xsl:value-of select="concat(substring(NgaySinh, 1, 2), '/', substring(NgaySinh, 4, 2), '/', substring(NgaySinh, 7, 4))"/>
                            </td>

                            <td>
                                <xsl:value-of select="MaPhong"/>
                            </td>

                            <td>
                                <xsl:value-of select="Luong"/>
                            </td>
                        </tr>

                    </xsl:for-each>

                </table>
            </body>
        </html>
    </xsl:template>

</xsl:stylesheet>