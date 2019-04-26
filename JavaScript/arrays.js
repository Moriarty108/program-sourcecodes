var people = ["Bucky" , "Tommy" , "Sarah" , "Hannah"];
document.write(people[3]);

var things = new Array(3);
things[0] = "jersey shore";
things[1] = "brian regan";
things[2] = "thenewboston";
document.write("<br>" + things);

var stuff = new Array();
var x = 9;
var tuna = 65 - 54;
stuff[0] = "baconator";
stuff[1] = "old pumpkins";
document.write("<br > "+ stuff);

var dudes = ["Bucky" , "Dan" , "Randy" ];
var chicks = ["Lisa" , "Erin" , "Hannah"];
var people = dudes.concat(chicks);
document.write("<br> " + people);
document.write("<br> " + people.join("-"));//joins converts array into string and takes a string for a seperator other than comma and for default no arguments
people.pop();
people.push("Harry" , "Ron");
people.sort();
document.write("<br> " + people.join(";"));
