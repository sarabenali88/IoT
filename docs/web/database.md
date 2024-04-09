# Database

### Introduction 
I designed two tables for my database. The first table is the Appointment table. In this table I will be saving the date and
time and the name of the appointment. I also have an AI id, so it keeps going up for every new appointment. The second table
is the Sensor table and this table also has an AI id so the id keeps going up. In this table I am saving the value of 
the light that LDR detects when it's dark, and I am also saving the exact date and time of when the LDR detects
darkness.

### ERD

![uml-diagram](../assets/appointments_erd.png)

### MySQL database
![database-diagram](../assets/appointments_database.png)

### Table descriptions

#### Appointment Table:

**Purpose:** Stores appointment details including date, time, and appointment name.

**Attributes:**

- `appointment_id` (AI): Unique identifier for each appointment.

- `date_time_appointment`: Date and time of the appointment.

- `name`: Name of the appointment.

**Key Constraints:** `appointment_id` is the primary key.

#### Sensor Table:

**Purpose:** Records light detection data captured by sensor.

**Attributes:**

- `sensor_id` (AI): Unique identifier for each sensor entry.

- `light`: Value of light detected by the sensor.

- `datetime`: Date and time of light detection.

**Key Constraints:** `sensor_id` is the primary key.