In this file I will be explaining the styling I did with CSS. 

I added some styling for the "containers" that each appointment go into. I have added a border-style, width, and some 
padding and margin, and a border-radius, so it looks nice on the page.

```css
.appointment {
    border-style: groove;
    width: 60%;
    padding: 8px;
    margin: 10px;
    border-radius: 5px;
}
```

I added some styling for the alert box message that is shown after an appointment is created. I added some width, so it 
doesn't overlap with the containers for the appointments, and I added none to the display, so a green a bar isn't shown
on the page before you created an appointment. 

```css
.alert-success {
    width: 90%;
    display: none;
}
```

I didn't want the page to keep getting longer when a user is adding an appointment, so I added a scroll-bar to the 
card-container by using the webkit: 

```css
.card-container {
    max-height: 500px;
    overflow-y: auto;
}
.card-container::-webkit-scrollbar {
    width: 8px; /* Set the width of the scrollbar */
}

.card-container::-webkit-scrollbar-thumb {
    background-color: #483C32; /* Set the color of the scrollbar thumb */
    border-radius: 10px; /* Set the border radius of the scrollbar thumb */
}

```

I wanted the header of the page to have a taupe colour, so I added that and some padding and changed the font-size 
of text:

```css
.header {
    background-color: #483C32; /* Brown color */
    padding: 20px; /* Add some padding to give space around the text */
}
p {
    font-size: 14px;
}
```

I wanted the buttons to have the same colour as the header, so I added some background colour and changed the colour 
of the text inside the button based on if someone hovered on it or not:

```css
.btn {
    background-color: #483C32;
    color: #FFFFFF;
}

.btn:hover {
    border-color: #483C32;
    color: #000000;
    background-color: #FFFFFF;
}
```