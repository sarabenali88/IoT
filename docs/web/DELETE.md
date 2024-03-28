
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
```
https://benalis2.loca.lt/delete_data.php
```