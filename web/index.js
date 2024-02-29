let dateField = document.getElementById("date-input");
let timeField = document.getElementById("time-input");
let nameField = document.getElementById("app_name");
let button = document.getElementById("button");
let errorMsg = document.querySelector(".error");


button.onclick = function (event) {
    event.preventDefault();
    checkFields();
}

function checkFields(){
    let dateInput = dateField.value;
    let timeInput = timeField.value;
    let nameInput = nameField.value;

    if (dateInput === '') {
        errorMsg.innerText = "Date cannot be empty!";
    } else if (timeInput === '') {
        errorMsg.innerText = "Time cannot be empty!";
    } else if (nameInput === '') {
        errorMsg.innerText = "Name cannot be empty!";
    } else {
        errorMsg.innerHTML = "";
        new XMLHttpRequest();
    }
}




