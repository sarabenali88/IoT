<?php
/**
 * This file is used to for the connection with the database
 *
 * @author Sara Benali
 * @date 7-03-2024
 */
// Make a connection to your database
$hostname = "mariadb";
$username = "root";
$password = "7YKyE8R2AhKzswfN";
$database = "iot";

$dbConnection = new mysqli($hostname, $username, $password, $database);

if ($dbConnection->connect_error) {
    echo json_encode(array("success" => false, "error" => $dbConnection->connect_error));
    exit();
}


