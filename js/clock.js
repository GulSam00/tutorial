
const clockContainer = document.querySelector(".clock");
const button = document.querySelector(".btn");
const dateData = document.querySelector(".input");
const showStartDate = document.querySelector(".start-date");
const showEndDate = document.querySelector(".end-date");

const clockTitle = document.createElement("h2");
const clockDate = document.createElement("h1");
var saveDate = document.createElement("h3");

function getTime(){
    const date = new Date();
    const year = date.getFullYear();
    const month = date.getMonth();
    const day = date.getDate();
    const minutes = date.getMinutes();
    const hours = date.getHours();
    const seconds = date.getSeconds();
    clockDate.innerText = `오늘의 날짜
    ${year}-${month}-${day}`;
    clockTitle.innerText = `현재 시각
    ${hours < 10 ? `0${hours}` : `${hours}`}:${minutes < 10 ? `0${minutes}` : `${minutes}`}:${seconds < 10 ? `0${seconds}` : `${seconds}`}`;
    clockContainer.appendChild(clockDate);
    clockContainer.appendChild(clockTitle);
}

function isEmpty(str){
         
    if(typeof str == "undefined" || str == null || str == "")
        return true;
    else
        return false;
}

function setDate(event){
    event.preventDefault();
    var settingDate = dateData.value;
    if (isEmpty(settingDate))
        {
            alert("날짜를 입력해주세요.");
            return ;
        }
    
    var setYear = settingDate.substring(0,4);
    var setMonth = settingDate.substring(5,7);
    var setDay = settingDate.substring(8,10);
    var total = `${setYear}년 ${setMonth}월 ${setDay}일`;
    var startDate = new Date(`${setYear}-${setMonth}-${setDay}`);
    showStartDate.innerText = "입대일 " + total;
    calcDate(startDate.getTime());
    
}

function calcDate(startDate) {
	var future = startDate + 545 * (1000*60*60*24);  // 처음 만난 날에 밀리초로 바꾼 100일을 더합니다.
	var endDate = new Date(future);  // future 값을 사용해 Date 객체의 인스턴스를 만듭니다.
	var year = endDate.getFullYear();  // ‘연도’를 가져와 year 변수에 저장합니다.
	var month = endDate.getMonth() + 1;  // ‘월’을 가져와 month 변수에 저장합니다.
	var date = endDate.getDate();  // ‘일’을 가져와 date 변수에 저장합니다.
	showEndDate.innerText = "전역일 " + `${year}년 ${month}월 ${date}일`;
}

function init(){
    getTime();
    setInterval(getTime, 1000);
}

button.addEventListener("click", setDate);
init();

