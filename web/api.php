<?php

 // Make a connection to your database
$dbConnection = new mysqli("mariadb", "root", "password", "iot");

if ($dbConnection->connect_error) {
    echo json_encode(array("success" => false, "error" => $dbConnection->connect_error));
    exit();
}
