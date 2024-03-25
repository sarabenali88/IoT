# API reference

### POST
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
https://benalis2.loca.lt/insert_data.php

### GET
_**Parameters**_

None

_**Body**_

| Required | Data | 
|----------|------|
| No       | None |
| No       | None |

_**Response**_

| HTTP code | Content-type     | Response |
|-----------|------------------|----------|
| 200       | application/json | JSON     |

_**URL link**_
https://benalis2.loca.lt/get_data.php

### DELETE

_**Parameters**_

| Name           | Type     | Data type | Description             |
|----------------|----------|-----------|-------------------------|
| appointment_id | required | int       | id of the appointment   |

_**Body**_

| Required | Data | 
|----------|------|
| No       | None |
| No       | None |

_**Response**_

| HTTP code | Content-type       | Response                                                                  |
|-----------|--------------------|---------------------------------------------------------------------------|
| 200       | "application/json" | {"success": true, "message": "Successfully deleted appointment"           | 
| 500       | "application/json" | {"success": false, "message": "No connection with database,  "error": ""} |

_**URL link**_
https://benalis2.loca.lt/delete_data.php