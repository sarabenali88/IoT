<?php
if (isset($_POST)){
    $data = file_get_contents("php://input");
    $appointment =  json_decode($data, true);
    echo json_encode($appointment);
}