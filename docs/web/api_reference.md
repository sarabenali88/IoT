# API reference

### POST
_**Parameters**_

None

_**Body**_

|     | Data                | 
|-----|---------------------|
| Yes | dateTimeAppointment |
| Yes | name                |    

_**Response**_

| HTTP code | Content-type       | Response                                                                 |
|-----------|--------------------|--------------------------------------------------------------------------|
| 201       | "application/json" | {"success": true, "message": "Appointment is added succesfully!"         | 
| 500       | "application/json" | {"success": false, "message": "No connection with database, "error": ""} |

_**URL link**_
curl -X POST -H "Content-Type: application/json" --data @post.json http://localhost:8080/appointments

### GET
_**Parameters**_

None

_**Body**_

|     | Data | 
|-----|------|
| No  | None |
| No  | None |

_**Response**_

| HTTP code | Content-type                   | Response           |
|-----------|--------------------------------|--------------------|
| 200       | application/json;charset=UTF-8 | "application/json" |

_**URL link**_
curl -X POST -H "Content-Type: application/json;charset=UTF-8" --data @post.json http://localhost:8080/appointments

### DELETE

_**Parameters**_

| Name           | Type     | Data type | Description             |
|----------------|----------|-----------|-------------------------|
| appointment_id | required | int       | id of the appointment   |

_**Body**_

|     | Data | 
|-----|------|
| No  | None |
| No  | None |

_**Response**_

| HTTP code | Content-type       | Response                                                                  |
|-----------|--------------------|---------------------------------------------------------------------------|
| 200       | "application/json" | {"success": true, "message": "Successfully deleted appointment"           | 
| 500       | "application/json" | {"success": false, "message": "No connection with database,  "error": ""} |

_**URL link**_
curl -X POST -H "Content-Type: application/json" --data @post.json http://localhost:8080/appointment_id