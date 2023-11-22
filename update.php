<?php
include("connect.php");

$id = $_GET['id'] ?? '';

if ($id != '') {
    // Tìm nạp dữ liệu hiện có cho ID nhà xuất bản được chỉ định
    $sql = 'select * from publisher where pub_id = ?';
    $stm = $conn->prepare($sql);
    $stm->execute([$id]);
    $existingData = $stm->fetch(PDO::FETCH_ASSOC);

    if ($existingData) {
        // Hiển thị form để chỉnh sửa
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            // Xử lý việc gửi biểu mẫu để cập nhật bản ghi
            $name = $_POST['name'] ?? '';

            if (!empty($name)) {
                // Cập nhật bản ghi vào cơ sở dữ liệu
                $sql = 'update publisher set pub_name = ? where pub_id = ?';
                $stm = $conn->prepare($sql);
                $stm->execute([$name, $id]);

                header('location:index.php');
                exit();
            } else {
                echo "Vui lòng cung cấp tên nhà xuất bản hợp lệ.";
            }
        }
?>
        <form action="update.php?id=<?php echo $existingData['pub_id']; ?>" method="post">
            <input type="hidden" name="id" value="<?php echo $existingData['pub_id']; ?>">
            Mã nhà xuất bản <input type="text" name="name" value="<?php echo $existingData['pub_name']; ?>"> <br>
            <input type="submit" value="Cập nhật">
        </form>
<?php
    } else {
        echo "Không tìm thấy bản ghi.";
    }
} else {
    echo "ID nhà xuất bản không hợp lệ.";
}
?>