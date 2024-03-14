<?php
require 'connection_database.php';

    if ($_SERVER["REQUEST_METHOD"] === "DELETE") {
        $appointment_id = isset($_GET['appointment_id']) ? $_GET['appointment_id'] : null;
        if (isset($dbConnection)) {
            echo $appointment_id;
            $query = $dbConnection->prepare("DELETE FROM Appointment WHERE appointment_id = ?");
            $query->bind_param("s", $appointment_id);
            if ($query->execute()) {
                echo json_encode(["message" => "Successfully deleted appointment"]);
            } else {
                echo json_encode(["success" => false, "error" => "Failed to delete appointment"]);
            }
        }
    }
