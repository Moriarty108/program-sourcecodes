<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/sql" prefix="sql" %>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Register</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"
        integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous" />
    <sql:setDataSource var="connnection" url="jdbc:mysql://localhost:3306/mydb" driver="com.mysql.jdbc.Driver"
        user="root" password="abhishek1" />
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
        <form action="register.jsp" method="post" class="mt-5">
            <h1 class="display-4 text-center text-success">Register</h1>
            <div class="form-group">
                <label for="email">Email</label>
                <input type="email" name="email" id="email" class="form-control">
            </div>
            <div class="form-group">
                <label for="password">Password</label>
                <input type="password" name="password" id="password" class="form-control">
            </div>
            <button type="submit" class="mt-5 btn btn-block btn-info">Register</button>
            <a href="index.jsp" class="mt-4 btn btn-block btn-success">Login</a>
        </form>
        <c:if test="${param.email != null}">
            <sql:update dataSource="${connnection}" var="count">
                insert into users (email,password) values(?,?)
                <sql:param value="${param.email}" />
                <sql:param value="${param.password}" />
            </sql:update>
            <c:choose>
                <c:when test="${count == 1}">
                    <div class="mt-5 alert alert-success">User Registered!</div>
                </c:when>
                <c:otherwise>
                    <div class="mt-5 alert alert-danger">An Error Occurred. Couldn't Register User</div>
                </c:otherwise>
            </c:choose>
        </c:if>
    </div>
</body>

</html>