class UserStorage {
  loginUser(id, password) {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        if (
          (id === "ellie" && password === "dream") ||
          (id === "coder" && password === "coding")
        ) {
          resolve(id);
        } else {
          reject(new Error("wrong id"));
        }
      }, 100);
    });
  }
  getRoles(user) {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        if (user === "ellie") {
          resolve({ name: "ellie", role: "admin" });
        } else {
          reject(new Error("wrong user"));
        }
      }, 100);
    });
  }

  onSuccess(userWithRole) {
    alert(userWithRole);
    alert(`hello! ${userWithRole.name}, you have ${userWithRole.role}}`);
  }
}

const userStorage = new UserStorage();
const id = prompt("enter id");
const password = prompt("enter password");

userStorage
  .loginUser(id, password)
  .then(userStorage.getRoles)
  .then(userStorage.onSuccess)
  .catch(console.log);
