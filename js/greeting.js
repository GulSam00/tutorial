const form = document.querySelector(".js-form"),
input = form.querySelector("input"),
greeting = document.querySelector(".js-greetings"),
body = document.querySelector("body");

const USER_LS = "currentUser",
    SHOWING_CN = "showing";

function saveName(text){
    localStorage.setItem(USER_LS, text);
}

function handleSubmit(event){
    event.preventDefault();
    const currentValue = input.value;
    paintGreeting(currentValue);
    saveName(currentValue);
}

function askForName(){
    form.classList.add(SHOWING_CN);
    form.addEventListener("submit", handleSubmit);
}

function paintGreeting(text){
    form.style = "display:none";
    greeting.classList.add(SHOWING_CN);
    greeting.innerText = `${text} 장병에게 경의를`;
}

function loadName(){
    const currentUser = localStorage.getItem(USER_LS);
    if (currentUser === null)
    {
        askForName();
    }
    else {
        paintGreeting(currentUser);
    }
}

function setImage(){
    const randomNumber = Math.floor(Math.random()*2);
    const image = new Image();
    image.src = `images/${randomNumber+1}.png`
    image.classList.add("bgImage");
    body.appendChild(image);
}

function init(){
    setImage();
    loadName();

}

init();