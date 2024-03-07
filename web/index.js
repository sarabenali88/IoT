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
            // displayAppointment(appointment);
            console.log(JSON.stringify(appointment));
        }

        //  function displayAppointment(){
        //     let card = document.querySelector("card");
        //     card.querySelector('h6').innerText = "Date:" + dateField.value;
        // }
    }
});
