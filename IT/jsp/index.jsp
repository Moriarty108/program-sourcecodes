<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/sql" prefix="sql" %>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <meta http-equiv="X-UA-Compatible" content="ie=edge" />
  <title>Login</title>
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"
    integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous" />
  <sql:setDataSource var="connection" driver="com.mysql.jdbc.Driver" url="jdbc:mysql://localhost:3306/mydb" user="root"
    password="abhishek1" />

  <style>
    body {
      font-family: -apple-system, BlinkMacSystemFont,
        'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell,
        'Open Sans', 'Helvetica Neue', sans-serif;
    }
  </style>

</head>

<body>
  <div class="container w-50">
    <form action="index.jsp" method="post" class="mt-5">
      <h1 class="display-4 text-center text-danger">Login</h1>
      <div class="form-group">
        <label for="email">Email</label>
        <input type="email" name="email" id="email" class="form-control" />
      </div>
      <div class="form-group">
        <label for="password">Password</label>
        <input type="password" name="password" id="password" class="form-control" />
      </div>
      <button type="submit" class="mt-5 btn btn-primary btn-block">
        Login
      </button>
      <a href="register.jsp" class="mt-4 btn btn-warning btn-block">Register</a>
    </form>
    <c:if test="${param.email != null}">
      <sql:query dataSource="${connection}" var="records">
        select * from users where email=?
        <sql:param value="${param.email}" />
      </sql:query>
      <c:choose>
        <c:when test="${records != null}">
          <c:choose>
            <c:when test="${records.rowsByIndex[0][2] == param.password}">
              <script>
                alert("Welcome! Login Successful");
              </script>
            </c:when>
            <c:otherwise>
              <div class="mt-5 alert alert-danger">Wrong Password!</div>
            </c:otherwise>
          </c:choose>
        </c:when>
        <c:otherwise>
          <div class="mt-5 alert alert-danger">User does not exists!</div>
        </c:otherwise>
      </c:choose>
    </c:if>
  </div>
</body>

</html>