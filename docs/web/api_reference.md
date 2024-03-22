# API reference

### POST

_**Parameters**_

| Name                | Type     | Data type | Description                      |
|---------------------|----------|-----------|----------------------------------|
| dateTimeAppointment | required | String    | Date and time of the appointment |
| name                | required | String    | Name of the appointment          |

_**Response**_

| HTTP code | Content-type       | Response                                                         |
|-----------|--------------------|------------------------------------------------------------------|
| 201       | "application/json" | {"success": true, "message": "Appointment is added succesfully!" | 
| 500       | "application/json" | {"success": false, "error": ""}                                  |


### GET
_**Parameters**_

None

_**Response**_

| HTTP code | Content-type                   | Response           |
|-----------|--------------------------------|--------------------|
| 200       | application/json;charset=UTF-8 | "application/json" |


### DELETE

_**Parameters**_

| Name           | Type     | Data type | Description             |
|----------------|----------|-----------|-------------------------|
| appointment_id | required | int       | id of the appointment   |

_**Response**_

| HTTP code | Content-type       | Response                                                        |
|-----------|--------------------|-----------------------------------------------------------------|
| 200       | "application/json" | {"success": true, "message": "Successfully deleted appointment" | 
| 500       | "application/json" | {"success": false, "error": ""}                                 |

