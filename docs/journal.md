# Learning journal

## 2024-02-08
- Today I will continue working on my project. I will sketch out my design and ask for feedback, so I can improve my design. 
For now, I cannot continue working on my web-application because I have no idea where to start and what kind of setup I need.
Today I will try to find that out.

- I made two designs for my website and I didn't know which one to choose, so I asked for feedback and opinions. I ended up 
choosing the second design, because that one felt a little simpler for a 10-week project and I think the second design is 
easier to work with. I also think that I know how to start working on my website, because I saw some examples from other 
classmates.

## 2024-02-14
- Today I have worked on trying to make to turn on the LCD-screen and I also wanted to print something simple as "Hello
World" on it. The only thing I knew was that I needed to solder my backpack to my LCD-screen. So, that's the first thing
I did. I then looked up some tutorials and I had found a lot but a lot of them didn't really explain what I was supposed 
to do. I ended up being very confused because the things people were using in the video, were not in my kit. I ended up
asking for help, and then I looked up some pictures with my teacher and I ended up being able to turn the LCD-screen on
using my WeMos. Then, it was time to print "Hello World" on the LCD-screen. I picked my board and port in Arduino and 
something went wrong again. I kept getting this error: "A fatal esptool.py error occurred: Write timeout". I didn't know 
how to fix this at first, I switched from LCD-screen with Seyma (my classmate), and it ended up working on her laptop. For some 
reason, three ports were available, COM5, COM6, and COM7. I was using COM7 at first, normally I use COM5, so I changed the
port to COM5, and it ended up working. This is how it ended up looking:
![step1-LCD](assets/Step1_lcd.jpg)
![step2-LCD](assets/Step2_lcd.jpg)
![step3-LCD](assets/Step3_lcd.jpg)

What I did was using female to female cables. I then connected each cable to its pin. SO for example, SCL would be connected
to D1. I did this for all four pins. Lastly, I ran the code in Arduino and was able to display the "Hello world". 
This is a website link that helped me:
[link for connecting WeMos to LCD](https://www.esp8266learning.com/wemos-mini-i2c-lcd-example.php)

## 2024-02-15
Today I learned how to use JavaScript again. The last time I used JavaScript was last year and even then everything was 
still a bit vague because JavaScript was very new to me and I didn't understand a lot. After struggling for a bit, I did 
manage to complete my work for the day. I managed to make the view of the website. On the website you can now see a form 
where you can enter the date, time and name of an appointment. I also added validation for the fields. This means if you
don't enter anything, a warning message will be displayed. That is all what I worked on for the web-application

## 2024-02-26
Today I have learned how to use the laser cutter. I had made the decision to work with wood and to do that I needed to 
use the laser cutter. Before this I made a simple sketch design in 2d and 3d with the programs inkscape and openscad. 
I then went to the makers lab to follow the workshop and to try something on my own. At first, I thought that laser cutting
would be very difficult, but it's actually very easy and pretty fun too. After the workshop was finished I decided that I 
want to start on my own design. Even though I only did the front of the pyramid, I wanted to at least have a first 
try/concept. This was a smart thing to do because now I know the measurements for my design. At first, I was unsure because 
I didn't want my design to look to big or too small. By using the laser cutter, I was able to figure how big/small I need 
some things to be. Below I have pictures of the pyramid design in the program and from the wood:
![pyramid_software_program](assets/pyramid_program.jpg)
![pyramid_wood](assets/pyramid_wood_1.jpg)

## 2024-02-28
Today I learned how to connect a push button to my active buzzer and Arduino. I started with searching up some tutorials 
and websites to see how can I set up everything using the wires, breadboard, Arduino, active buzzer and push button. In 
the beginning it was pretty difficult to actually find something that gives a clear explanation of what to do. But I did 
end up figuring it out. I was able to make put everything together and a sound came from the buzzer, this was the first step. 
After that I wanted to use the push button, because the whole idea is that the buzzer goes off, you click on the button and
the buzzer stops. Everything I tried wasn't working and I didn't know what to do, according to the video everything looked 
alright. I asked for help and the problem was that I was missing a wire that was connecting the push button to the power.
I then was able to make a buzzer sound by using the push button and this was step 2. The last step was to make sure that 
the buzzer turns off when I click on the button. I already had some example code from the video, but now I needed to adapt it
to what I want it to do. Since I'm not familiar with C## I didn't really know how to write the code. I knew what I had to use 
, but I didn't know how to apply it. I tried different things, but it didn't quiet work. So, I asked for help from the student
assistant. I ended up figuring it out and for now the buzzer does what I need it to do. Below is the link for the video I used
and some pictures from how everything looked like:
[Link for setup active buzzer-Arduino](https://www.youtube.com/watch?v=gj-H_agfd6U&t=86s)
![sound_1](assets/sound_1.jpg)
![sound_2](assets/sound_2.jpg)
![sound_3](assets/sound_3.jpg)

## 2024-02-29
Today I learned to start working with php. I didn't know how PHP works (I still don't know a lot), but I did work on making 
a connection with my database. I have a database connection and also made a database design. At first, I only had two tables,
the user table and the appointment table, in my design because I didn't know what I should be saving into database apart
from that. I asked for help from the teacher, and he told me that I should also save the data from the sensors I have. 
The sensors I am using are the push button and the LDR and I have also decided which data I want to save in the tables.
Today I failed to accomplish one thing. I wanted to make sure that I could at least save the data from the appointment into
the appointment table in the database. But I didn't manage to do that, because I still find PHP a little hard to work with. 
I will try to take a look at this again tomorrow or in the weekend.

## 2024-03-04
Today I learned to create different measurements for my design during the laser cutting. Last week I went to the 
makers-lab, and I was able to use the laser cutter. The only thing I didn't know how to do is create different 
measurements for different shapes I want to cut out. It was actually very easy and the only thing I had to do was select 
the shape. I cut out another pyramid side design like last week but with new measurements, but the new measurements for 
the LCD-screen weren't accurate, so next week I will be going to the makers-lab again to cut out a new design with the 
right measurements. 

## 2024-03-06
Today I learned how to regulate a LED light by using an LDR. My idea for the LDR sensor changed, because I couldn't find 
any (clear) tutorials or explanations on how to regulate the brightness of the LCD screen, so I decided to use a LED. 
Now it works like this: When it's light the LED will be turned off, but the moment the LED senses darkness, the LED will
be turned on. Last week I worked on the push button combined with the active buzzer, and today I tried to make the 
buzzer/button work together with the LED/LDR. There were some complications first, because I couldn't get the buzzer to 
work again. The problem ended up being a mistake in my code and one of my wires. The only thing I need to figure out now,
is how to make sure I can use the ground and 5v pins for both input/output sensors. Below are some pictures of how I 
did it:
![ldr_1](assets/ldr_1.jpg)
![ldr_2](assets/ldr_2.jpg)
![ldr_3](assets/ldr_3.jpg)
A link reference to the tutorial I followed:
[Link for setup LDR/LED-Arduino](https://projecthub.arduino.cc/DCamino/ambient-light-sensor-using-photo-resistor-and-led-lights-79c2ed)

## 2024-03-07
Today I learned how to create endpoints with php. At first, I had lots of problems with connecting everything to my database. 
But I managed to solve them by asking for help and I realised that I entered the wrong things in some places. To create the 
endpoints I used the knowledge base and video's. I also searched a lot of things on stackoverflow. I can now create an 
appointment that saves to the database, and you can see a list of the appointments that have been created. Sometimes it 
was difficult to add things to the js file, because it kept working and then it didn't, but I managed to fix everything 
by searching on Google. 

## 2024-03-11
Today I learned how to laser cut a design that uses fingers, but it didn't go all too well. I have decided to work with 
wood and since we're not allowed to use any glue or tape or tools like that, I decided I wanted to add fingers to my design.
I found a website that generated the design for me and I thought that I could use this, but the website generated a 
pyramid with all the sides looking the same. So, the fingers did not even fit in the other holes. 
I tried so many times to change the measurements, but everytime it didn't show the right design. I gave up and tried to
make another design in the makers case. I do have a new design now, and I am going to try to cut it out next week. I must 
say that it does look a little different. Next week, I really want to use the laser cut for the last time. 

## 2024-03-13
Today I have learned how to configure Wi-Fi on my Wemos. It was a little confusing to know if it actually worked, but I think
I did it. I ran some code that gave me my Mac adress, and then I configured it with iotroam. I ran some code I found in the
knowledge base, and then I added my Wi-Fi network and password. Everything showed what was supposed to be shown. I thought 
that this would take the whole day so this was my only goal, but I was done early. So, I worked on making my sensors and 
outputs work together on my Arduino, and it worked! I also rewired everything, so now it looks clearer. I think I can start
on the wiring diagram now.
![configured_wires](assets/configured_wires_1.jpg)
![configured_wires](assets/configured_wires_2.jpg)
![configured_wires](assets/configured_wires_3.jpg)
![configured_wires](assets/configured_wires_4.jpg)
![configured_wires](assets/configured_wires_5.jpg)

## 2024-03-14
Today I learned how to display my appointments on my LCD-screen. I made a connection with the Wi-Fi and my Wemos. I did 
this by kind of merging my wifi-setup code and hello world together. I did a GET request on my tunnel page and by using 
my get php code, and then I decoded the JSON object by using the JSON buffer. I then printed the decoded name on the 
LCD-screen. I am glad that I am making progress with this and next time I want to make sure the buzzer works according 
to the time. 
![display_appointment](assets/display_appointment.jpg);

## 2024-03-27
Today I learned how to make the active buzzer work according to the requirements. I had to try lots of things because I 
converted everything to my Wemos, so the button and active buzzer were acting weird. I had to ask for some help to rewire
some things. I have written some code to make the buzzer go off one hour before the appointment time. I think everything 
looks good. All of my inputs and outputs work and the only thing that's left is to put it into a box (at least for embedded).
