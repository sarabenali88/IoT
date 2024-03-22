<?php
require 'connection_database.php';

/**
 * This file is used to create a DELETE request to the database by using a DELETE query
 *
 * @author Sara Benali
 */

    if ($_SERVER["REQUEST_METHOD"] === "DELETE") {
        $appointment_id = isset($_GET['appointment_id']) ? $_GET['appointment_id'] : null;
        define('HTTP_STATUS_OK', 200);
        define('HTTP_STATUS_INTERNAL_SERVER_ERROR', 500);
        if (isset($dbConnection)) {
            echo $appointment_id;
            $query = $dbConnection->prepare("DELETE FROM Appointment WHERE appointment_id = ?");
            $query->bind_param("i", $appointment_id);
            if ($query->execute()) {
                http_response_code(HTTP_STATUS_OK);
                echo json_encode(["message" => "Successfully deleted appointment"]);
            } else {
                http_response_code(HTTP_STATUS_INTERNAL_SERVER_ERROR);
                echo json_encode(["success" => false, "error" => $dbConnection->error]);
            }
        }
    }
