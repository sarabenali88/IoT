In this file I will be explaining the API endpoints that I have created.

## POST 

This POST method sends the date, time and name of the appointment to the database.

First, I add the php file for the database connection, because you can't make a request to the database without a
connection:
```injectablephp
require 'connection_database.php';

```

Next, I check if the server request method is a POST method and if it is then I read the POST data and I decode the data
by using  json.decode(). I use the decode method, because I sent my data as a JSON object. I also added constants of HTTP
code that I will be sending with in the code.
```injectablephp
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $data = file_get_contents("php://input");
    $appointment = json_decode($data, true);
    define('HTTP_STATUS_CREATED', 201);
    define('HTTP_STATUS_INTERNAL_SERVER_ERROR', 500);
```
Next, I check if the appointment is not null, if it's not then it means that it contains valid data and I can proceed to
retrieve the values of the keys and assign them to the variables.
```injectablephp
if ($appointment !== null) {
        $dateTimeAppointment = $appointment["dateTimeAppointment"];
        $name = $appointment["name"];
```
Lastly, I check if there is a connection with the database and if there is I create an INSERT query as a prepared statement
to prevent SQL injection, to insert the data into the Appointment table. I bind the parameters (the question marks) with
the data I want to send. If the query is executed , I send a JSON object with a single key back with a message and
otherwise an error. I also send an HTTP code of 201 if the query is executed and an HTTP code of 500 if something went wrong.
```injectablephp
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
                $dbConnection->close();
        }
    }
}
```

Lastly, I close the connection.

```injectablephp
    $dbConnection->close();
```

## POST (POST request for the LDR sensor data)
This POST method is used to insert the data from the LDR light value when it's dark.

First, I add the php file for the database connection, because you can't make a request to the database without a
connection:
```injectablephp
require 'connection_database.php';
```

To read data from the request from the API I use the $_POST. I then encode the data into a JSON object. I also added HTTP
response code I will be sending for when the query is being executed.
```injectablephp
$light = $_POST["light"];
echo json_encode(array("light" => $light));

const HTTP_STATUS_CREATED = 201;
const HTTP_STATUS_INTERNAL_SERVER_ERROR = 500;
```

Next, I check for the database connection and I created a query that inserts the light value into the table Sensor, and
the date and time for when the value is read and inserted.
```injectablephp
if (isset($dbConnection)) {
    $insertQuery = $dbConnection->prepare("INSERT INTO `Sensor` (`light`, `date_time`) VALUES (" . $light . ", NOW())");
```

Next, I check if the query is executed and if it is then the message will be sent and the HTTP code 201 and if not, another
message will be sent with the HTTP code 500. 

```injectablephp
if ($insertQuery->execute()) {
        http_response_code(HTTP_STATUS_CREATED);
        echo json_encode(array("succes" => true, "message" => "Sensor data inserted succesfully"));
    } else {
        http_response_code(HTTP_STATUS_INTERNAL_SERVER_ERROR);
        echo json_encode(array("success" => false, "error" => $dbConnection->error, "message" => "No connection with database"));
    }
```

Lastly, I close the connection.

```injectablephp
    $dbConnection->close();
```
## GET (GET request for all the appointments)

This GET method retrieves the date, time and name of the appointments from the database.

First, I add the php file for the database connection, because you can't make a request to the database without a
connection:
```injectablephp
require 'connection_database.php';

```
Next, I check if the server request method is a GET method, and then I also immediately check for a database connection.
I then proceed to create a SELECT query where I select all the data from the Appointment table. Then the query is being
executed with the given query and database connection. I also added constants of HTTP code that I will be sending with
in the code.
```injectablephp
if ($_SERVER["REQUEST_METHOD"] === "GET" && isset($dbConnection)) {
    $query = "SELECT * FROM Appointment";
    $query_run = mysqli_query($dbConnection, $query);
    define('HTTP_STATUS_OK', 200);
    define('HTTP_STATUS_INTERNAL_SERVER_ERROR', 500);
```

Lastly, I check if the query is executed and if it is I fetch all the rows from the Appointment table. After that, the
fetched data is encoded into a JSON format. Then the JSON-encoded data is sent back to the client by using echo. If it
didn't execute, an error will be sent back to the client. I also send an HTTP code of 200 if the query is executed and 
an HTTP code of 500 if something went wrong.

```injectablephp
if ($query_run){
        $res = mysqli_fetch_all($query_run, MYSQLI_ASSOC);
        http_response_code(HTTP_STATUS_OK);
        echo json_encode($res);
    }else{
        http_response_code(HTTP_STATUS_INTERNAL_SERVER_ERROR);
        echo json_encode(array("success" => false, "message" => "No connection with database",
         "error" => $dbConnection->error));
    }
        $dbConnection->close();
}
```
Lastly, I close the connection.

```injectablephp
    $dbConnection->close();
```

## GET (GET request for the appointments according to the date)

This GET method retrieves all the dates according to what date it is. 


First, I add the php file for the database connection, because you can't make a request to the database without a
connection:
```injectablephp
require 'connection_database.php';

```

Next, I check if the server request method is a GET method, and then I also immediately check for a database connection.
I then proceed to create a SELECT query where I select all the data from the Appointment table according to "today's date".
So today alle the appointments are selected from today, tomorrow from tomorrow and so on. Then the query is being
executed with the given query and database connection. I also added constants of HTTP code that I will be sending with
in the code.
```injectablephp
if ($_SERVER["REQUEST_METHOD"] === "GET" && isset($dbConnection)) {
    $query = "SELECT * FROM Appointment WHERE DATE(date_time_appointment) = CURDATE();";
    $query_run = mysqli_query($dbConnection, $query);
    define('HTTP_STATUS_OK', 200);
    define('HTTP_STATUS_INTERNAL_SERVER_ERROR', 500);
```

Lastly, I check if the query is executed and if it is I fetch all the rows from the Appointment table. After that, the
fetched data is encoded into a JSON format. Then the JSON-encoded data is sent back to the client by using echo. If it
didn't execute, an error will be sent back to the client. I also send an HTTP code of 200 if the query is executed and
an HTTP code of 500 if something went wrong.

```injectablephp
if ($query_run){
        $res = mysqli_fetch_all($query_run, MYSQLI_ASSOC);
        http_response_code(HTTP_STATUS_OK);
        echo json_encode($res);
    }else{
        http_response_code(HTTP_STATUS_INTERNAL_SERVER_ERROR);
        echo json_encode(array("success" => false, "message" => "No connection with database",
         "error" => $dbConnection->error));
    }
        $dbConnection->close();
}
```

Lastly, I close the connection.

```injectablephp
    $dbConnection->close();
```

## DELETE 

This DELETE method deletes the date, time and name of the selected appointment from the database.

First, I add the php file for the database connection, because you can't make a request to the database without a
connection:
```injectablephp
require 'connection_database.php';

```

Next, I check if the server request method is a DELETE method and if it is a GET request will be made for the
appointment_id. If the appointment_id is present in the url, it will be stored and if it's not null will be assigned to
the appointment_id. I also added constants of HTTP code that I will be sending with in the code.

```injectablephp
 if ($_SERVER["REQUEST_METHOD"] === "DELETE") {
        $appointment_id = isset($_GET['appointment_id']) ? $_GET['appointment_id'] : null;
        define('HTTP_STATUS_OK', 200);
        define('HTTP_STATUS_INTERNAL_SERVER_ERROR', 500);
```
Next, I check if there is a connection with the database and if there is I create a DELETE query with a WHERE clause as
a prepared statement to prevent SQL injection, to delete the selected appointment from the Appointment table. I bind the
parameters (the question mark) with the data I want to send.
```injectablephp
if (isset($dbConnection)) {
            echo $appointment_id;
            $query = $dbConnection->prepare("DELETE FROM Appointment WHERE appointment_id = ?");
            $query->bind_param("i", $appointment_id);
```

Lastly, If the query is executed , I send a JSON object with a single key back with a message back to the client
and otherwise an error. I also send an HTTP code of 200 if the query is executed and an HTTP code of 500 if something 
went wrong.

```injectablephp
 if ($query->execute()) {
                http_response_code(HTTP_STATUS_OK);
                echo json_encode(["message" => "Successfully deleted appointment"]);
            } else {
                http_response_code(HTTP_STATUS_INTERNAL_SERVER_ERROR);
                echo json_encode(["success" => false, "message" => "No connection with database", 
                "error" => $dbConnection->error]);
            }
                $dbConnection->close();
        }
    }
```

Lastly, I close the connection.

```injectablephp
    $dbConnection->close();
```