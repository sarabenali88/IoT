In this file I will be explaining the code I have written for the different requests I have made:

First, I have added an event listener on the page, so all the content will be loaded first before anything else happens. 
By using the getElementById I am retrieving the fields of the inputs, the button and the error and success field from 
the HTML file:
```
document.addEventListener("DOMContentLoaded", function () {
    let dateField = document.getElementById("date-input");
    let timeField = document.getElementById("time-input");
    let nameField = document.getElementById("app_name");
    let button = document.getElementById("button");
    let errorMsg = document.querySelector(".error");
    let successMsg = document.querySelector(".alert-success");
```

Next, I add an onclick event on the button and this means that the moment the button is clicked everything after that 
will fire. I added a preventDefault so the page won't keep refreshing after the click. Lastly I am calling the method 
that validates the fields:
```
button.onclick = function (event) {
        event.preventDefault();
        handleAppointmentSubmission();
    }
```

Next, I created a method called checkFields that checks the input of the fields. If it's empty then an error message will 
be displayed. If all the fields are entered, you won't see the error message. I am also combining the date and time field
because I need to save this in the database with the datatype DATETIME. Lastly, I am creating an object of the entered 
values and I use this for the post request:
```
function handleAppointmentSubmission() {
        let dateInput = dateField.value;
        let timeInput = timeField.value
        let nameInput = nameField.value;

        if (dateInput === '') {
            errorMsg.innerHTML = "Date cannot be empty!";
            errorMsg.style.display = "block";
        } else if (timeInput === '') {
            errorMsg.innerHTML = "Time cannot be empty"
            errorMsg.style.display = "block";
        } else if (nameInput === '') {
            errorMsg.innerHTML = "Name cannot be empty!";
            errorMsg.style.display = "block";
        } else {
            let dateTimeAppointment = dateInput + ' ' + timeInput
            let appointment = {
                "dateTimeAppointment": dateTimeAppointment,
                "name": nameInput
            };
```

Next, I created a fetch function that uses the php file insert_data to make a POST request. I send the appointment as a 
stringified JSON object in the body. I then use the then method that returns a promise and this returns the response in 
JSON format. In the second then method, I call the createAppointments method because I want the appointment to immediately
be added on the page without having to refresh the page first. Lastly, there is an alert-message that says the 
appointment has been added with a close button and if you click on the button, the message disappears and the input fields
are cleared:

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
                createAppointments();
                successMsg.innerHTML = "Your appointment has been added!" + `<span class="close">&times;</span>`;
                successMsg.style.display = "block";
                let closeButton = document.querySelector('.close');
                closeButton.addEventListener('click', function() {
                successMsg.style.display = 'none';
                dateField.value = '';
                timeField.value = '';
                nameField.value = '';
            });   
            });

            errorMsg.innerHTML = "";
            errorMsg.style.display = "none";
            
         }
    }
```

In the next fetch I created a GET request, I retrieved the data that is saved in the database and I display it 
on the page. I put this fetch method in a function, because I need to reuse the code in other places as well.
I added another then method returns a promise and this returns the response in JSON format again. 
```
function createAppointments() {
fetch("get_data.php", {
    "method": "GET",
    "headers": {
        "Content-Type": "application/json; charset=utf-8"
    }
}).then(function (response) {
    return response.json();
```

In the second then method I am looping through the data that is being retrieved. I created a forEach loop to loop through 
the data, because I wanted each appointment to have its own "container". I created a div element and in this div element,
I add the data. I split the date-time data, so it has a nice format on the website too. I also sorted the appointments based
on the date and time of the appointments. I append this div element on the div I created in the HTML file: 
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
        data.sort((a, b) => new Date(a.date_time_appointment) - new Date(b.date_time_appointment));
        document.getElementById("new-appointment").appendChild(div);

```

Next, I added an event listener on the button that I named delete, because I am making a DELETE request. In the fetch 
method I added the php file for the DELETE with the id of the appointment. I did this because I needed to include the parameter
for the appointment id, because I am doing a GET request on the appointment_id in the PHP file. In the then method I do 
a check to see if the response is successful and if it is then I remove the div and display a message that you can also 
remove by clicking on the button and if it's not, an error message will be console logged:
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
                    successMsg.innerHTML = "Your appointment has been deleted!" + `<span class="close">&times;</span>`;
                    successMsg.style.display = "block";
                    let closeButton = document.querySelector('.close');
                    closeButton.addEventListener('click', function () {
                        successMsg.style.display = 'none';
                    });
                    div.remove();                
                    } else {
                 console.error("Failed to delete appointment");
                }
            })
        });

        console.log(data);
    }
 });
}
```

Lastly, I call the method createAppointments, so the data from the database is also shown on the website.

```
createAppointments();
```