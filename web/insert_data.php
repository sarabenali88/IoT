<?php

require 'connection_database.php';

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data = file_get_contents("php://input");
    $appointment = json_decode($data, true);

    if ($appointment !== null) {
        $dateTimeAppointment = $appointment["dateTimeAppointment"];
        $name = $appointment["name"];

        if (isset($dbConnection)) {
            $insertQuery = $dbConnection->prepare("INSERT INTO `Appointment` (`date_time_appointment`, `name`) VALUES (?, ?)");
            $insertQuery->bind_param("ss", $dateTimeAppointment, $name);
            if ($insertQuery->execute()) {
                echo json_encode(array("message" => "Appointment is added succesfully!"));
            } else {
                echo json_encode(array("success" => false, "error" => $dbConnection->error));
            }
        }
    }
}