<?php
$servername = "IoT";
$username = "root";
$password = "7YKyE8R2AhKzswfN";

// Create connection
$conn = new mysqli($servername, $username, $password);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";


