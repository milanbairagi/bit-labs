// 12. Student object with method

function showStudentInfo() {
  const student = {
    name: "Milan Bairagi",
    age: 20,
    rollNo: 2014,

    displayInfo: function () {
      return `Name: ${this.name} <br> Age: ${this.age} <br> Roll No: ${this.rollNo}`;
    }
  }
	document.getElementById("info").innerHTML = student.displayInfo();
}
