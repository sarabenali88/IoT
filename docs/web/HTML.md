In this file I will be explaining the HTML code I have written for the form that the user will enter to make
an appointment. This file exists out of a form where everything is handled dynamically by JavaScript. Styling is done
with Bootstrap and with CSS.

Below I have added the files/libraries for Bootstrap, CSS by using the link tag and href reference. I used the script
tag for the JavaScript file:

```
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
<link rel="stylesheet" href="main.css">
<script type="module" src="index.js"></script>
```

In the head of the file I have added the title of the website by using the title tag:

```
<head>
    <title>My Calender</title>
</head> 
```

In the form I have added the title of the page using an h1 tag and I have added three input fields, a date field, a
time field and a text field. By using the label tag, I have given each field a name so it's clear which field is for
which. In the class tag you can see I have added some styling and I did this with bootstrap. This form exists in the
body
of the page:

```
<body>
<div class="container p-2 mx-4">
<div class="row">
    <div class="col-3">
        <h2>My appointments</h2>
        <div class="form-group">
            <label for="date-input">Date</label>
            <input type="date" class="form-control " id="date-input">
        </div>
        <div class="form-group">
            <label for="time-input">Time</label>
            <input type="time" class="form-control" id="time-input"></div>
        <div class="form-group">
            <label for="app_name">Appointment name</label>
            <input type="text" class="form-control" id="app_name">
        </div>
        <div class="alert-danger error" style="background: none"></div>
        <div class="mt-4">
            <button type="submit" id="button" class="btn btn-outline-secondary">Add appointment</button>
        </div>
    </div>
    <div class="col-7 offset-2 mt-5" id="card"></div>
</div>
</div>
</body>
```

This div tag is used for the appointments that are made. Everytime an appointment is made, the appointment will be added
to this div tag so it kind of looks like a list:

```
   <div class="col-7 offset-2 mt-5" id="card"></div>
```