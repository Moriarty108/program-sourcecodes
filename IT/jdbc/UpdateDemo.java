import java.sql.SQLException;
import java.sql.DriverManager;
import java.sql.Connection;

class UpdateDemo {
    public static void main(String[] args) throws SQLException {
        String url = "jdbc:mysql://localhost:3306/mydb";
        String username = "root";
        String password = "abhishek1";

        Connection connection = DriverManager.getConnection(url, username, password);

        String query = "UPDATE student SET marks=94 WHERE name=\'John Doe\'";

        connection.createStatement().executeUpdate(query);
        System.out.println("Update Complete");
    }
}