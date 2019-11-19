<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <meta http-equiv="X-UA-Compatible" content="ie=edge" />
    <title>Document</title>
  </head>
  <body>
    <% String firstName = request.getParameter("firstname"); String lastName =
    request.getParameter("lastname"); String country =
    request.getParameter("country");%> The Student is Confirmed : <%=
    firstName%> <%= lastName%>
    <br /><br />

    Favoutite Language : ${param.fav_lang}
    <br /><br />
    Student's Country : <%= country %>
  </body>
</html>
