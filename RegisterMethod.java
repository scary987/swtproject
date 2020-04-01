//import java.util.Date;
import java.sql.*;



public class RegisterMethod {

  public RegisterMethod(){}

    public RegisterBean checkRegister(String username, String password, String vorname, String nachname, String host, String emailname, Date birthdate) throws SQLException ,
            ClassNotFoundException {
        String jdbcURL = "tcp://localhost:3306";
        String dbUser = "scary__";
        String dbPassword = "monsterssupercreeps";

        Class.forName("com.mysql.jdbc.Driver");
        Connection connection = DriverManager.getConnection(jdbcURL, dbUser, dbPassword);
        String sql = "SELECT * FROM signin WHERE username = ?";
        PreparedStatement statement = connection.prepareStatement(sql);
        statement.setString(1, username);
        //statement.setString(2, password);

        ResultSet result = statement.executeQuery();

        RegisterBean user = null;
        //
        if (!result.next()) {
          user = new RegisterBean();
        //  System.out.println("Ihr Username ist einzigartig!!!");

        }
        //insert into signin table
        String insertsql = "Insert into signin(username,password) values (?,?)";
        statement = connection.prepareStatement(insertsql);
        statement.setString(1, username);
        statement.setString(2, password);
         statement.execute();
         //get id
        sql = "SELECT distinct id FROM signin WHERE username = ? and password = ?";
        statement = connection.prepareStatement(sql);
        statement.setString(1,username);
        statement.setString(2,password);
        result= statement.executeQuery();
        result.next();
        int id = result.getInt("id");

        insertsql = "Insert into users(id,vorname,nachname,birthdate,emailname,emailhost) values (?,?,?,?,?,?) ";
        statement = connection.prepareStatement(insertsql);
        statement.setInt(1,id);
        statement.setString(2,vorname);
        statement.setString(3, nachname);

        //convert java date to mysql date format string
      //  java.text.SimpleDateFormat sdf = new java.text.SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
      //  String currentTime = sdf.format(birthdate);

        statement.setDate(4, birthdate );
        statement.setString(5, emailname);
        statement.setString(6, host);
        user.setUsername(username);
        user.setVorname(vorname);
        user.setNachname(nachname);
        user.setDate(birthdate);

        //user.setSessionid(somegeneratednumber);

        statement.execute();
        connection.close();
        return user;
      }
}
