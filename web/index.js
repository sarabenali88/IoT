document.addEventListener("DOMContentLoaded", function() {
    let dateField = document.getElementById("date-time-input");
    let nameField = document.getElementById("app_name");
    let button = document.getElementById("button");
    let errorMsg = document.querySelector(".error");

    button.onclick = function (event) {
        event.preventDefault();
        checkFields();
    }

    function checkFields(){
        let dateTimeInput = dateField.value;
        let nameInput = nameField.value;

        if (dateTimeInput === '') {
            errorMsg.innerText = "Date and Time cannot be empty!";
        } else if (nameInput === '') {
            errorMsg.innerText = "Name cannot be empty!";
        } else {
            let appointment = {
                "date_time_appointment": dateTimeInput,
                "name": nameInput
            };

            fetch("script.php", {
                "method" : "POST",
                "headers" : {
                    "Content-Type" : "application/json; charset=utf-8"
                },
                "body" : JSON.stringify(appointment)
            }).then(function (response){
                return response.json();
            }).then(function(data){
                console.log(data);
            });

            errorMsg.innerHTML = "";
            alert("Your appointment has been added!");
            // displayAppointment(appointment);
        }

        //  function displayAppointment(){
        //     let card = document.querySelector("card");
        //     card.querySelector('h6').innerText = "Date:" + dateField.value;
        // }
    }
});
