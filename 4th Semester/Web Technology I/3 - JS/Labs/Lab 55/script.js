// 15. Display current date and time in dd/mm/yyyy hh:mm:ss

const now = new Date();
// const pad = n => n.toString().padStart(2, '0');
// const date = `${pad(now.getDate())}/${pad(now.getMonth()+1)}/${now.getFullYear()}`;
// const time = `${pad(now.getHours())}:${pad(now.getMinutes())}:${pad(now.getSeconds())}`;
const dateTime = `${now.getDate()}/${now.getMonth()}/${now.getFullYear()}
                  ${now.getHours()}:${now.getMinutes()}:${now.getSeconds()}`
document.getElementById('result').textContent = `${dateTime}`;
