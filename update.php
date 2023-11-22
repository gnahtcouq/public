<?php
include("connect.php");

$pub_id = $_POST['id'] ?? '';
$pub_name = $_POST['name'] ?? '';

if ($pub_id != '') {
    $sql = 'update publisher set pub_name = ? where pub_id = ?';
    $stm = $conn->prepare($sql);
    $stm->execute([$pub_name, $pub_id]);
}
header('location:index.php');
