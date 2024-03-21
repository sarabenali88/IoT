<?php
require('connection_database.php');
$light = $_POST["light"];

echo json_encode(array("light" => $light));

if (isset($dbConnection)) {
    $insertQuery = $dbConnection->prepare("INSERT INTO `Sensor` (`light`) VALUES (?)");
    $insertQuery->bind_param("s", $light);
    if ($insertQuery->execute()) {
        echo json_encode(array("succes" => true));
    } else {
        echo json_encode(array("success" => false, "error" => $dbConnection->error));
    }
    $dbConnection->close();
}
