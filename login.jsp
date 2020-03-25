<%@ page contentType="text/html; charset=utf-8" language="java"  pageEncoding="utf-8" %>
<html>
<head><title>Gedankengutlogin</title></head>
	<body> 
		<form name="login" method="get" action="login" style="text-align: center"> 
			<label for="username">Enter Your Username: </label> <br>
			<input type="text" id="username" name="username" size="50"><br>
			<label for="password">Enter Your Password: </label><br>
			<input type="password" id="password" name="password"  size="50"><br>
			<br>${message}
			<br><br>
			<input type="submit" name="submit" value="Login" >
		</form>

			
		<%

		//session.setAttribute("username",username); 
		//session.setAttribute("password",password);
		%>
	</body>
	<script type="text/javascript">
	    $(document).ready(function() {
        $("#loginForm").validate({
            rules: {
                username: {
                    required: true,
                    username: true
                },
         
                password: "required",
            },
             
            messages: {
                username: {
                    required: "Please enter email",
                    username: "Please enter a valid email address"
                },
                 
                password: "Please enter password"
            }
        });
 
    });
</script>
</html>

