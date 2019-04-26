function people(name , age){
    this.name = name;
    this.age = age;
    this.yearsUntilRetire = yearsLeft;//weird , right? to associate this property with the function
}

function yearsLeft(){
    return 65 - this.age;
}

var bucky = new people("Bucky ",24);
document.write(bucky.yearsUntilRetire());//this is some weird language