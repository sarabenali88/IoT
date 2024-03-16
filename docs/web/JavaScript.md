In this file I will be explaining the code I have written for the different requests I have made:

First, I have added an event listener on the page, so all the content will be loaded first before anything else happens. 
By using the getElementById I am retrieving the fields of the inputs, the button and the error field from the HTML file:
```
document.addEventListener("DOMContentLoaded", function () {
    let dateField = document.getElementById("date-input");
    let timeField = document.getElementById("time-input");
    let nameField = document.getElementById("app_name");
    let button = document.getElementById("button");
    let errorMsg = document.querySelector(".error");
```

Next, I add an onclick event on the button and this means that the moment the button is clicked everything after that 
will fire. I added a preventDefault so the page won't keep refreshing after the click. Lastly I am calling the method 
that validates the fields:
```
button.onclick = function (event) {
        event.preventDefault();
        checkFields();
    }
```

Next, I created a method called checkFields that checks the input of the fields. If it's empty then an error message will 
be displayed. If all the fields are entered, you won't see the error message. I am also combining the date and time field
because I need to save this in the database with the datatype DATETIME. Lastly, I am creating an object of the entered 
values and I use this for the post request:
```
function checkFields() {
        let dateInput = dateField.value;
        let timeInput = timeField.value
        let nameInput = nameField.value;

        if (dateInput === '') {
            errorMsg.innerText = "Date cannot be empty!";
        } else if (timeInput === '') {
            errorMsg.innerText = "Time cannot be empty"
        } else if (nameInput === '') {
            errorMsg.innerText = "Name cannot be empty!";
        } else {
            let dateTimeAppointment = dateInput + ' ' + timeInput
            let appointment = {
                "dateTimeAppointment": dateTimeAppointment,
                "name": nameInput
            };
```

Next, I created a fetch function that uses the php file insert_data to make a POST request. I send the appointment as a 
stringified JSON object in the body. I then use the then method that returns a promise and this returns the response in 
JSON format. Lastly, there is an alert that says the appointment has been added:
```
fetch("insert_data.php", {
                "method": "POST",
                "headers": {
                    "Content-Type": "application/json; charset=utf-8"
                },
                "body": JSON.stringify(appointment)
            }).then(function (response) {
                return response.json();
            }).then(function (data) {
                console.log(data);
            });

            errorMsg.innerHTML = "";
            alert("Your appointment has been added!");
        }
    }
```

In the next fetch I created a GET request, I retrieved the data that is saved in the database and I display it 
on the page. I added another then method returns a promise and this returns the response in JSON format again. 
```
fetch("get_data.php", {
    "method": "GET",
    "headers": {
        "Content-Type": "application/json; charset=utf-8"
    }
}).then(function (response) {
    return response.json();
```

I then added another then method with the data that is retrieved. I created a forEach loop to loop through the data, because 
I wanted each appointment to have its own "container". I created a div element and in this div element, I add the data and
some styling. I split the date-time data, so it has a nice format on the website too. I append this div element on the 
div I created in the HTML file: 
```
.then(function (data) {
    for (let appointment of data) {
        let div = document.createElement("div");
        div.classList.add("appointment");
        let appointmentDate = new Date(appointment.date_time_appointment);
        let options = {weekday: 'long', day: 'numeric', month: 'long', year: 'numeric'};
        let formattedDate = appointmentDate.toLocaleDateString('en-GB', options);
        let time = appointment.date_time_appointment.split(' ')[1];
        div.innerHTML = `
        <h6>Appointment: ${appointment.name}</h6>
        <h6>Date: ${formattedDate}</h6>
        <h6>Time: ${time}</h6>  
        <button class="deleteButton mt-2 btn btn-outline-secondary" data-id="${appointment.appointment_id}">Delete</button>`;
        div.style.borderStyle = "groove"
        div.style.width = "50%";
        div.style.padding = "8px";
        div.style.margin = "10px";
        document.getElementById("card").appendChild(div);

```

Next, I added an event listener on the button that I named delete, because I am making a DELETE request. In the fetch 
method I added the php file for the DELETE with the id of the appointment. I did this because I needed to include the parameter
for the appointment id, because I am doing a GET request on the appointment_id in the PHP file. In the then method I do 
a check to see if the response is successful and if it is then I remove the div and if it's not, an error message will 
be console logged:
```
 div.querySelector(".deleteButton").addEventListener("click", function (event) {
            event.preventDefault();

            let appointmentId = this.getAttribute('data-id');
            fetch('delete_data.php?appointment_id=' + appointmentId, {
                method: "DELETE",
                headers: {
                    "Content-Type": "application/json; charset=utf-8"
                }
            }).then(response => {
                if (response.ok) {
                    div.remove();
                } else {
                    console.error("Failed to delete appointment");
                }
            })
        });

        console.log(data);
    }
});
```