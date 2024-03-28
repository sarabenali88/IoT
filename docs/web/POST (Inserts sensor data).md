
_**Parameters**_

None

_**Body**_

| Required | Data    | 
|----------|---------|
| Yes      | "light" |

_**Response**_

| HTTP code | Content-type       | Response                                                                 |
|-----------|--------------------|--------------------------------------------------------------------------|
| 201       | "application/json" | {"success": true, "message" => "Sensor data inserted successfully"       | 
| 500       | "application/json" | {"success": false, "message": "No connection with database, "error": ""} |


_**URL link**_

```
https://benalis2.loca.lt/insert_sensor_data.php
```