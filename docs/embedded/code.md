## Library configuration

- // @author Sara Benali
- // This section of the program is for the libraries
- // License type: MIT License

The Libraries cover different functionalities such as Wi-Fi connection, HTTP communication, JSON data handling, LCD-display
control, network time synchronization, UDP communication, DNS resolution, web server capabilities, and lastly Wi-Fi network
configuration.

**Link to GitLab**

```https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/individual-project/tiitiizuuxuu49/-/blame/main/embedded/main-code/final_version_sensors.ino?ref_type=heads#L1```

## Variables 

- // @author Sara Benali
- // This section explains what the variables are used for
- // License type: MIT License

**Overview**

1. The urls for the urls are set, I use these to make a GET and POST request
2. I set the port number for the Wi-Fi configuration
3. I set the columns and rows for the LCD, because the LCD only has 16 columns and 2 rows.
4. I set the buzzer pin on 16 and the button pin on 14
5. I set the origin of the cursors on the LCD to 0
6. I have different variables for the delays
7. I set the numbers to initialize the LCD
8. I set maximum time for how long the buzzer will go off
9. I set the pin-number for the LED
10. I set the numbers for the light

**Link to GitLab**

```https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/individual-project/tiitiizuuxuu49/-/blob/main/embedded/main-code/final_version_sensors.ino?ref_type=heads#L12```

## Setup

- // @author Sara Benali
- // This section of the program setups everything, so you can use it in the program.
- // License type: MIT License

In the setup I set Wi-Fi manager, the pins of the buzzer, button, LED, LCD and the timeClient. 

**Link to GitLab**
```https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/individual-project/tiitiizuuxuu49/-/blob/main/embedded/main-code/final_version_sensors.ino?ref_type=heads#L62```

## Code for the LCD-display, Active buzzer and Push button

- // @author Sara Benali
- // This section of the program retrieves saved appointments and presents them on the LCD-display. It monitors local time
 to trigger the buzzer alarm and provides functionality to stop the buzzer with a button press. 
- // License type: MIT License

**Function description**

The `makeSound()` function displays appointments on the LCD-display. It displays the date/time of the appointment on the 
first row of the LCD, and the name on the second row. It compares the current time to the appointment time and lets the 
buzzer go off one hour before the appointment time. It also stops buzzing the moment you click on the push button. 

**Overview**

1. GET request is made on today's appointments
2. Appointments are deserialized
3. Current time is compared to appointment time
4. Buzzer goes off and turned off by button
5. Appointments are displayed

**Link to GitLab**

```https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/individual-project/tiitiizuuxuu49/-/blob/main/embedded/main-code/final_version_sensors.ino?ref_type=heads#L103```

## Code for the LDR and the LED

- // @author Sara Benali
- // This program segment measures the light level in a room using an LDR sensor and activates the LED based on the 
measured value.
- // License type: MIT License


The `regulateLight()` function checks for the light value in a room. If there's a little light or a lot of light, the LED
stays off, but when it's dark the LED turns on (and a POST request is made).

**Overview**

1. Read the light value
2. Check if it's light or dark
3. If it's dark the LED turns on
4. POST request is made

**Link to GitLab**

```https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/individual-project/tiitiizuuxuu49/-/blob/main/embedded/main-code/final_version_sensors.ino?ref_type=heads#L187```
