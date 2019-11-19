import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.SQLException;

class DeleteDemo {
    public static void main(String[] args) throws SQLException {

        String url = "jdbc:mysql://localhost:3306/mydb";
        String username = "root";
        String password = "abhishek1";

        Connection connection = DriverManager.getConnection(url, username, password);

        String query = "DELETE FROM student WHERE name=\'Arthur\'";

        int rowsAffected = connection.createStatement().executeUpdate(query);
        System.out.println("Delete Complete.");
        System.out.println("Rows Affected : " + rowsAffected);
    }
}