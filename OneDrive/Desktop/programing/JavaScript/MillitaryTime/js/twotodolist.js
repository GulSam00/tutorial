const toDoForm = document.querySelector(".input-text"),
toDoInput = toDoForm.querySelector("input"),
pendingList = document.querySelector(".pending"),
finishedList = document.querySelector(".finished");

const PENDING_LS = "PENDING";
const FINISHED_LS = "FINISHED";

let pending = [];
let finish = [];

function deleteToDo(deleteNode){
  pendingList.removeChild(deleteNode);
  const cleanToDos = pending.filter(function(toDo) {
      return (toDo.id !== parseInt(deleteNode.id));
  });
  pending = cleanToDos;
  saveToDos(PENDING_LS, pending);
}

function deleteFinish(deleteNode){
    finishedList.removeChild(deleteNode);
    const cleanToDos = finish.filter(function(toDo) {
        return (toDo.id !== parseInt(deleteNode.id));
    });
    finish = cleanToDos;
    saveToDos(FINISHED_LS, finish);
  }

function moveFinish(text){

    const li = document.createElement("li");
  const deleteBtn = document.createElement("button");
  deleteBtn.addEventListener("click", function() {
      movePending(text),
      deleteFinish(deleteBtn.parentNode)});
  const finishBtn = document.createElement("button");
  const span = document.createElement("span");
  const newId = finish.length + 1;
  deleteBtn.innerText = "X";
  finishBtn.innerText = "V";
  span.innerText = text;
  li.appendChild(span);
  li.appendChild(deleteBtn);
  li.appendChild(finishBtn);
  li.id = newId;
  finishedList.appendChild(li);
  const toDoObj = {
      text: text,
      id: newId
  };
  finish.push(toDoObj);
  saveToDos(FINISHED_LS, finish);
}

function saveToDos(Key, list){
  localStorage.setItem(Key, JSON.stringify(list));
}

function movePending(text){
  const li = document.createElement("li");
  const deleteBtn = document.createElement("button");
  deleteBtn.addEventListener("click", function() {deleteToDo(deleteBtn.parentNode)});
  const finishBtn = document.createElement("button");
  finishBtn.addEventListener("click", function() {
    deleteToDo(deleteBtn.parentNode),
    moveFinish(text)
    });


  const span = document.createElement("span");
  const newId = pending.length + 1;
  deleteBtn.innerText = "X";
  finishBtn.innerText = "V";
  span.innerText = text;
  li.appendChild(span);
  li.appendChild(deleteBtn);
  li.appendChild(finishBtn);
  li.id = newId;
  pendingList.appendChild(li);
  const toDoObj = {
    text: text,
    id: newId
};
  pending.push(toDoObj);
  saveToDos(PENDING_LS, pending);
}

function inputSubmit(event){
    event.preventDefault();
  const currentValue = toDoInput.value;
  if (currentValue === "")
  {
      alert("값을 입력해주세요.");
      return ;
  }
  movePending(currentValue);
  toDoInput.value = "";
}

function loadToDos(){

  const loadedPending = localStorage.getItem(PENDING_LS);
  const loadedFinshed = localStorage.getItem(FINISHED_LS);

  if (loadedPending !== null){
      const parsedPending = JSON.parse(loadedPending)
      parsedPending.forEach(function(toDo) {
        movePending(toDo.text);
      });
  }
  if (loadedFinshed !== null){
    const parsedFinished = JSON.parse(loadedFinshed)
    parsedFinished.forEach(function(toDo) {
      moveFinish(toDo.text);
    });
}
}

function init(){
  loadToDos();
  toDoForm.addEventListener("submit", inputSubmit);
}

init();
