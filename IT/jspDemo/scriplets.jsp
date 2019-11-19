<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
    <%
        for(int i = 1; i <= 5; i++){
            out.println("<br>I really hate jsp: " + i);
        }
    %>
</body>
</html>