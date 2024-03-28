<?php
/**
 * This file is used to retrieve all the appointments from the database according to today's date
 *
 * @author Sara Benali
 * @date 27-03-2024
 */
require 'connection_database.php';

if ($_SERVER["REQUEST_METHOD"] === "GET" && isset($dbConnection)) {
    $query = "SELECT * FROM Appointment WHERE DATE(date_time_appointment) = CURDATE();";
    $query_run = mysqli_query($dbConnection, $query);
    if ($query_run){
        $res = mysqli_fetch_all($query_run, MYSQLI_ASSOC);
        echo json_encode($res);
    }else{
        echo json_encode(array("success" => false, "error" => $dbConnection->error, "message" => "No connection with database"));
    }
    $dbConnection->close();
}
