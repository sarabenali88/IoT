<?php

/**
 * This file is used to insert the data from the LDR sensor into the database
 *
 * @author Sara Benali
 * @date 28-03-2024
 */
require('connection_database.php');

$light = $_POST["light"];
echo json_encode(array("light" => $light));

const HTTP_STATUS_CREATED = 201;
const HTTP_STATUS_INTERNAL_SERVER_ERROR = 500;

if (isset($dbConnection)) {
    $insertQuery = $dbConnection->prepare("INSERT INTO `Sensor` (`light`, `date_time`) VALUES (" . $light . ", NOW())");
    if ($insertQuery->execute()) {
        http_response_code(HTTP_STATUS_CREATED);
        echo json_encode(array("succes" => true, "message" => "Sensor data inserted successfully"));
    } else {
        http_response_code(HTTP_STATUS_INTERNAL_SERVER_ERROR);
        echo json_encode(array("success" => false, "error" => $dbConnection->error, "message" => "No connection with database"));
    }
    $dbConnection->close();
}
