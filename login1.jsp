<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.util.*"%>
<%@ include file="file1.jsp" %>
<html>
	<body>
		<% String var1= request.getParameter("username");session.setAttribute("username",var1); %><br>
	<% String var2 =request.getParameter("password"); session.setAttribute("password",var2); %>
	<% out.println(var1+"\n"+var2);//system("set -a PATH xd"); 
	   %>




	</body>

	
</html>
