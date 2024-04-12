**SELECT data from the tables:**

```sql
SELECT * FROM iot.Appointment;

SELECT * FROM iot.Sensor;

```

**INSERT data into tables:**

```sql
INSERT INTO `iot`.`Appointment` (`date_time_appointment`, `name`)
VALUES ('2024-04-11 21:46:00', 'Project');

INSERT INTO `iot`.`Sensor` (`light`, `date_time`)
VALUES (130, '2024-04-11 21:46:00');
```

**DELETE data from tables:**

```sql
DELETE FROM iot.Appointment WHERE `appointment_id` = ...;

DELETE FROM iot.Sensor WHERE `id` = ...;
```