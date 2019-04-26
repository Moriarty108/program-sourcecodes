var tuna = "hey i am a tuna fish";
tuna.length;
function person(name, age) {
    this.name = name;
    this.age = age;
}//constructor function
 
var bucky = new person("Bucky", 24);//An instance/object created by constructor treated as a blueprint
var taylor = new person("Taylor Swift", 20);
document.write(bucky.name);