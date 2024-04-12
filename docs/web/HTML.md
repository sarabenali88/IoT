In this file I will be explaining the HTML code I have written for the form that the user will enter to make
an appointment. This file exists out of a form where everything is handled dynamically by JavaScript. Styling is done
with Bootstrap and with CSS.

[Link to code](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/individual-project/tiitiizuuxuu49/-/blob/main/web/index.html?ref_type=heads)

Below I have added the files/libraries for Bootstrap, CSS by using the link tag and href reference. I used the script
tag for the JavaScript file:

```html
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
<link rel="stylesheet" href="main.css">
<script type="module" src="index.js"></script>
```

In the head of the file I have added the title of the website by using the title tag:

```html
<head>
    <title>My Calender</title>
</head> 
```

In the body of the HTML file I have added a header with a fun title and a kind of explanation of the website:

```html
<div class="header">
    <h2 class="title text-center text-white">Reminder Road: Your Pathway to Organized Appointments and Timely
        Reminders!</h2>
    <p class="pt-2 text-center text-white">Do you struggle with keeping up with your appointments, missing deadlines, or
        forgetting important events?
        Say goodbye to the chaos and hello to organization with Reminder Road! With timely reminders and intuitive
        features, you'll never miss a beat again. Take control of your calendar and start enjoying peace of mind
        today!</p>
</div>

```
I have added three input fields, a date field, a time field and a text field. By using the label tag, 
I have given each field a name, so it's clear which field is for which. In the class tag you can see I have added some 
styling and I did this with bootstrap. I have also added a success alert message that will be displayed when adding 
and/or deleting an appointment. 

```html
<div class="container p-2">
    <div class="row">
        <div class="col-5 card mt-5">
            <h3 class="mt-3 mb-4 pt-4">Add new appointment</h3>
            <div class="form-group">
                <label for="date-input">Date</label>
                <input type="date" class="form-control" id="date-input">
            </div>
            <div class="form-group">
                <label for="time-input">Time</label>
                <input type="time" class="form-control" id="time-input">
            </div>
            <div class="form-group">
                <label for="app_name">Appointment name</label>
                <input type="text" class="form-control" id="app_name">
            </div>
            <div class="alert alert-danger error" role="alert" style="display:none;"></div>
            <div class="mt-4">
                <button type="submit" id="button" class="btn">Add appointment</button>
            </div>
            <div class="mt-5">
                <div class="alert alert-success" role="alert"></div>
            </div>
        </div>
```

This div tag is used for the appointments that are made. Everytime an appointment is made, the appointment will be added
to this div tag so it kind of looks like a list:

```html
<div class="card col-6 mt-5 mx-5 card-container pt-4">
            <h2 class="p-2">My appointments</h2>
            <div id="new-appointment">
            </div>
        </div>
```

Lastly, I have added a footer just as an extra thing:
```html
<div class="card-footer">
    <p class="text-center font-weight-bold">@University of Applied Sciences</p>
</div>
```