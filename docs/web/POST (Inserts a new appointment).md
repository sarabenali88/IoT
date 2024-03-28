
_**Parameters**_

None

_**Body**_

| Required | Data                          | 
|----------|-------------------------------|
| Yes      | "dateTimeAppointment", "name" |

_**Response**_

| HTTP code | Content-type       | Response                                                                 |
|-----------|--------------------|--------------------------------------------------------------------------|
| 201       | "application/json" | {"success": true, "message": "Appointment is added succesfully!"         | 
| 500       | "application/json" | {"success": false, "message": "No connection with database, "error": ""} |

_**URL link**_

```
https://benalis2.loca.lt/insert_data.php
```