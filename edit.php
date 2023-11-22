<?php
include("connect.php");

$pub_id = $_GET['id'] ?? '';

if ($pub_id != '') {
    $sql = 'select * from publisher where pub_id = ?';
    $stm = $conn->prepare($sql);
    $stm->execute([$pub_id]);
    $data = $stm->fetch(PDO::FETCH_ASSOC);

    if (!$data) {
        die('Publisher not found');
    }
} else {
    die('Invalid publisher ID');
}
?>

<form action="update.php" method="post">
    Mã nhà xuất bản <input type="text" name="id" value="<?php echo $data['pub_id']; ?>" readonly> <br>
    Tên nhà xuất bản <input type="text" name="name" value="<?php echo $data['pub_name']; ?>"> <br>
    <input type="submit" value="Cập nhật">
</form>
