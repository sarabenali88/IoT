/**
 * In this file the JavaScript code manages a scheduling application's UI interactions, input validation, server
 * communication for data insertion and deletion, and dynamic display of appointments.
 *
 * @author Sara Benali
 */

/**
 * The fields are being checked on the entered value and data is being inserted
 *
 * @author Sara Benali
 */
document.addEventListener("DOMContentLoaded", function () {
    let dateField = document.getElementById("date-input");
    let timeField = document.getElementById("time-input");
    let nameField = document.getElementById("app_name");
    let button = document.getElementById("button");
    let errorMsg = document.querySelector(".error");
    let successMsg = document.querySelector(".alert-success");

    button.onclick = function (event) {
        event.preventDefault();
        checkFields();
    }

    function checkFields() {
        let dateInput = dateField.value;
        let timeInput = timeField.value
        let nameInput = nameField.value;

        if (dateInput === '') {
            errorMsg.innerHTML = "Datum mag niet leeg zijn!";
            errorMsg.style.display = "block";
        } else if (timeInput === '') {
            errorMsg.innerHTML = "Tijd mag niet leeg zijn!"
            errorMsg.style.display = "block";
        } else if (nameInput === '') {
            errorMsg.innerHTML = "Naam mag niet leeg zijn!";
            errorMsg.style.display = "block";
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
                createAppointments();
            });
            errorMsg.innerHTML = "";
            errorMsg.style.display = "none";
            successMsg.innerHTML = "Uw afspraak is toegevoegd!";
            successMsg.style.display = "block";

        }
    }
});

/**
 * In this method the data is being retrieved and shown on the page
 * @author Sara Benali
 */
function createAppointments() {
    fetch("get_data.php", {
        "method": "GET",
        "headers": {
            "Content-Type": "application/json; charset=utf-8"
        }
    }).then(function (response) {
        return response.json();
    }).then(function (data) {
        document.getElementById("card").innerHTML = ' ';
        for (let appointment of data) {
            let div = document.createElement("div");
            div.classList.add("appointment");
            let appointmentDate = new Date(appointment.date_time_appointment);
            let options = {weekday: 'long', day: 'numeric', month: 'long', year: 'numeric'};
            let formattedDate = appointmentDate.toLocaleDateString('nl-NL', options);
            let time = appointment.date_time_appointment.split(' ')[1];
            div.innerHTML = `
        <h6>Afspraak: ${appointment.name}</h6>
        <h6>Datum: ${formattedDate}</h6>
        <h6>Tijd: ${time}</h6>  
        <button class="deleteButton mt-2 btn btn-outline-secondary" data-id="${appointment.appointment_id}">Verwijderen</button>`;
            data.sort((a, b) => new Date(a.date_time_appointment) - new Date(b.date_time_appointment));
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
                        console.log("Failed to delete appointment");
                    }
                })
            });

        }
    });
}

createAppointments();
