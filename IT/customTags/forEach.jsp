<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
  <head>
    <title>For Each</title>
  </head>
  <body>
    <c:out value="For Each Example" />
    <% int[] arr = {1,2,3,4}; request.setAttribute("arr",arr);%>
    <c:forEach items="${arr}" var="current" step="2">
      <c:out value="${current}" />
    </c:forEach>
  </body>
</html>
