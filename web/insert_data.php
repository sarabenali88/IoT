<?php
/**
 * This file is used to create a POST request to the database by using an INSERT query
 *
 * @author Sara Benali
 */
require 'connection_database.php';


if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data = file_get_contents("php://input");
    $appointment = json_decode($data, true);
    define('HTTP_STATUS_CREATED', 201);
    define('HTTP_STATUS_INTERNAL_SERVER_ERROR', 500);

    if ($appointment !== null) {
        $dateTimeAppointment = $appointment["dateTimeAppointment"];
        $name = $appointment["name"];

        if (isset($dbConnection)) {
            $insertQuery = $dbConnection->prepare("INSERT INTO `Appointment` (`date_time_appointment`, `name`) VALUES (?, ?)");
            $insertQuery->bind_param("ss", $dateTimeAppointment, $name);
            if ($insertQuery->execute()) {
                http_response_code(HTTP_STATUS_CREATED);
                echo json_encode(array("succes" => true, "message" => "Appointment is added succesfully!"));
            } else {
                http_response_code(HTTP_STATUS_INTERNAL_SERVER_ERROR);
                echo json_encode(array("success" => false, "message" => "No connection with database",
                    "error" => $dbConnection->error));
            }
        }
    }
}