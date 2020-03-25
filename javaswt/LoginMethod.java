 import java.sql.*;


 
public class LoginMethod {
 
    public LoginMethod(){}
    
    public LoginBean checkLogin(String username, String password) throws SQLException,
            ClassNotFoundException {
        String jdbcURL = "tcp://localhost:3306";
        String dbUser = "scary__";
        String dbPassword = "monsterssupercreeps";
 
        Class.forName("com.mysql.jdbc.Driver");
        Connection connection = DriverManager.getConnection(jdbcURL, dbUser, dbPassword);
        String sql = "SELECT * FROM signin WHERE username = ? and password = ?";
        PreparedStatement statement = connection.prepareStatement(sql);
        statement.setString(1, username);
        statement.setString(2, password);
 
        ResultSet result = statement.executeQuery();
 
        LoginBean user = null;
 
        if (result.next()) {
            user = new LoginBean();
            user.setUsername(result.getString("username"));
        }
 
        connection.close();
 
        return user;
    }
}