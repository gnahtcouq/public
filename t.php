<form action="cau1.php" method='post' enctype="multipart/form-data">
    MSSV: <input type="text" name="masv01"> <br>
    Họ tên <input type="text" name="hoten01"> <br>
    Giới tính <input type="radio" name="gioitinh01" value='1'>Nam 
        <input type="radio" name="gioitinh01" value='2'>Nữ<br>
    Sở thích <input type="checkbox" name="sothich01[]" value='1'>Thể thao
    <input type="checkbox" name="sothich01[]" value='2'>Du lịch <br>
    Hình đại diện <input type="file" name="img" id=""> <br>
    <input type="submit" value="Gửi">
</form>
<?php 
//Hien thi thong tin vua nhap tai day
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Xử lý và lấy dữ liệu từ form
    $mssv = isset($_POST['masv01']) ? trim($_POST['masv01']) : '';
    $hoten = isset($_POST['hoten01']) ? trim($_POST['hoten01']) : '';
    $gioitinh = isset($_POST['gioitinh01']) ? $_POST['gioitinh01'] : '';
    $sothich = isset($_POST['sothich01']) ? $_POST['sothich01'] : [];
    
    // Kiểm tra thông tin hợp lệ
    if (!empty($mssv) && !empty($hoten) && !empty($gioitinh)) {
        // Kiểm tra giới tính
        $gioitinh_text = ($gioitinh == 1) ? 'Nam' : 'Nu';
        
        // Hiển thị thông tin
        echo "MSSV: $mssv <br>";
        echo "Họ tên: $hoten <br>";
        echo "Giới tính: $gioitinh_text <br>";
        
        // Hiển thị sở thích
        echo "Sở thích: ";
        foreach ($sothich as $st) {
            if ($st == 1) echo "Thể thao";
            if ($st == 2) echo "Du lịch";
        }
        echo "<br>";
        
        // Xử lý file ảnh nếu có
        if ($_FILES['img']['error'] == 0) {
            $upload_dir = 'hinh/';
            $upload_file = $upload_dir . basename($_FILES['img']['name']);
            move_uploaded_file($_FILES['img']['tmp_name'], $upload_file);
            echo "Hình đại diện: <img src='$upload_file' alt='Hình đại diện'><br>";
        }
    } else {
        echo "Vui lòng nhập đầy đủ thông tin!";
    }
}
?>
