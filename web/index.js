document.addEventListener("DOMContentLoaded", function () {
    let dateField = document.getElementById("date-input");
    let timeField = document.getElementById("time-input");
    let nameField = document.getElementById("app_name");
    let button = document.getElementById("button");
    let errorMsg = document.querySelector(".error");

    button.onclick = function (event) {
        event.preventDefault();
        checkFields();
    }

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

            fetch("insert_data.php",
                {
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
});

fetch("get_data.php", {
    "method": "GET",
    "headers": {
        "Content-Type": "application/json; charset=utf-8"
    }
}).then(function (response) {
    return response.json();
}).then(function (data) {
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