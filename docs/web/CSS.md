In this file I will be explaining the styling I did with CSS. 

I added some styling for the "containers" that each appointment go into. I have added a border-style, width, and some 
padding and margin, so it looks nice on the page.

```
.appointment {
    border-style: groove;
    width: 50%;
    padding: 8px;
    margin: 10px;
}
```

I added some styling for the alert box message that is shown after an appointment is created. I added some width, so it 
doesn't overlap with the containers for the appointments, and I added none to the display, so a green a bar isn't shown
on the page before you created an appointment. 

```
.alert-success {
    width: 120%;
    display: none;
}
```