# Requirements

To build your embedded device you need to have a clear idea of the requirements. On this page you can describe the requirements of your embedded device. This includes the requirements from DLO, but also your own requirements.

Add some images! 😉

## System requirements table
| **Requirement ID#** | **Requirement**                                                                                                                                                                        | **MoSCoW** | **Compliant** |
|---------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------|---------------|
| EMBRQ#01            | The embedded device acts as a client and sends measured sensor data to the application backend over http or https.                                                                     | MUST       | NO            |
| EMBRQ#02            | The embedded device also acts as a server and receives status messages from the application backend over http or https.                                                                | MUST       | NO            |
| EMBRQ#03            | The embedded device contains at least two types of input sensors (e.g. LDR, buttons, joystick, capacitive touch, etc.).                                                                | MUST       | IN PROGRESS   |
| EMBRQ#04            | The embedded device contains at least two types of visual and/or sensory outputs (e.g. LED, LED Matrix, 7-segment display, motor, servo, actuator, LCD-screen, buzzer, etc.).          | MUST       | IN PROGRESS   |
| EMBRQ#05            | The embedded device uses the WifiManager for configuration of SSID and password (PWD) for connecting to the network.                                                                   | MUST       | DONE          |
| EMBRQ#06            | The embedded device displays the name and date of an appointment. The LCD-screen displays the date&time in the first row and the name in the second row.                               | MUST       | IN PROGRESS   |
| EMBRQ#07            | The embedded device makes use of an active buzzer combined with a push button. When it's time for an appointment the active buzzer will go off 30 minutes before the appointment time. | MUST       | IN PROGRESS   |
| EMBRQ#08            | The embedded device uses an LDR to change the state of the LED light. When it's dark the LED light will turn on and when it's not dark, the LED light will turn off.                   | MUST       | DONE          |

 