<?php
require 'connection_database.php';

if ($_SERVER["REQUEST_METHOD"] === "GET" && isset($dbConnection)) {
    $query = "SELECT * FROM Appointment";
    $query_run = mysqli_query($dbConnection, $query);

    if ($query_run){
        $res = mysqli_fetch_all($query_run, MYSQLI_ASSOC);
        echo json_encode($res);
    }
}