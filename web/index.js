fetch("get_data.php", {
    "method": "GET",
    "headers": {
        "Content-Type": "application/json; charset=utf-8"
    }
}).then(function (response) {
    return response.json();
}).then(function (data) {
    for (let appointment of data){
        let div = document.createElement("div");
        div.classList.add("appointment");
        div.innerHTML = `
            <p>${appointment.date_time_appointment} ${appointment.name}</p>`;
        div.style.borderStyle = "solid"
        div.style.borderColor = "#EDC9AFFF";
        div.style.padding = "8px"; // Add padding
        div.style.margin = "10px";
        document.getElementById("card").appendChild(div);
    }
    console.log(data);
});




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

            fetch("get_data.php", {
                "method": "GET",
                "headers": {
                    "Content-Type": "application/json; charset=utf-8"
                }
            }).then(function (response) {
                return response.json();
            }).then(function (data) {
                console.log(data);
            });
        }
    }
});
