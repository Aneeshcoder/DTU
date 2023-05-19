<?php

require_once('connection.php');
$email=$_GET['id'];

$sql="DELETE from TEST_DRIVE where EMAIL='$email'";
$result=mysqli_query($con,$sql);

echo '<script>alert("TEST DRIVE REQUEST DELETED SUCCESFULLY")</script>';
echo '<script> window.location.href = "adminusers.php";</script>';

?>