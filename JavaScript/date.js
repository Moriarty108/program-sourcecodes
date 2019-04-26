function printTime() {
    var now = new Date();
    var hours = now.getHours();
    var minutes = now.getMinutes();
    var seconds = now.getSeconds();
    document.write(hours + " : " + minutes + " : " + seconds + "<br>");
}
setInterval("printTime()" , 1000);//do "printTime()" every 1000 milliseconds