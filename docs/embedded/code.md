# Embedded code

### Active buzzer code 
I used the pins from the Arduino to keep track of when the behaviour of the buzzer and button should change. I declared 
first that the buzzer sound will be the output and the button will be the input. I also tracked the state of the button. 
I set the buzzer to HIGH, so it would always make a buzzing sound. I then use a while-loop, so I can check when the buzzer
is supposed to stop buzzing. In the while-loop I used an if-statement to check if the button State is LOW, if it is then 
the buzzer should also be LOW. I also added a delay in the while-loop and outside the while-loop, so when you actually 
click on the button, the buzzer stops making a sound. For now, I have that the code runs again after 200 ms, but after
I have more of my functionalities this will change.
[Link to my embedded code](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/individual-project/tiitiizuuxuu49/-/blob/main/embedded/test_code/active-sound-file.ino?ref_type=heads)






This is not a place to put your code, but to describe the code that you have written. You can describe the code in a general way, but also go into detail on specific parts of the code. You can also refer to the code in your repository. So just add a link to the code in your repository.