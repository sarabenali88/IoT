<?php
require 'connection_database.php';

    if ($_SERVER["REQUEST_METHOD"] === "DELETE" && isset($dbConnection)) {
        $appointment_id = isset($_GET['appointment_id']) ? $_GET['appointment_id'] : null;

        if ($appointment_id !== null) {
            $query = "DELETE FROM Appointment WHERE appointment_id = ?";
            $statement = mysqli_prepare($dbConnection, $query);
            if ($statement) {
                mysqli_stmt_bind_param($statement, 'i', $appointment_id);
                if (mysqli_stmt_execute($statement))
                echo json_encode(["message" => "Successfully deleted appointment"]);
            } else {
                echo json_encode(["success" => false, "error" => "Failed to delete appointment"]);
            }
        }
    }
