<?php
require 'connection_database.php';

/**
 * This file is used to create a GET request from the database by using a SELECT query
 *
 * @author Sara Benali
 */

if ($_SERVER["REQUEST_METHOD"] === "GET" && isset($dbConnection)) {
    $query = "SELECT * FROM Appointment";
    $query_run = mysqli_query($dbConnection, $query);
    define('HTTP_STATUS_OK', 200);
    define('HTTP_STATUS_INTERNAL_SERVER_ERROR', 500);
    if ($query_run){
        $res = mysqli_fetch_all($query_run, MYSQLI_ASSOC);
        http_response_code(HTTP_STATUS_OK);
        echo json_encode($res);
    }else{
        http_response_code(HTTP_STATUS_INTERNAL_SERVER_ERROR);
        echo json_encode(array("success" => false, "error" => $dbConnection->error));
    }
}