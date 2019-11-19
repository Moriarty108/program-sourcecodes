import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Connection;

class InsertDemo {
    public static void main(String[] args) throws SQLException {
        String url = "jdbc:mysql://localhost:3306/mydb";
        String username = "root";
        String password = "abhishek1";

        Connection connection = DriverManager.getConnection(url, username, password);

        String query = "INSERT INTO student" + " VALUES (\'Arthur\',4,88)";
        connection.createStatement().executeUpdate(query);
        System.out.println("Insert Complete");
    }
}