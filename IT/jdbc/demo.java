import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;

class demo {
    public static void main(String[] args) {
        try {
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root",
                    "abhishek1");

            ResultSet result = connection.createStatement().executeQuery("select * from student");

            while (result.next()) {
                System.out.println(result.getString("name") + ", " + result.getString("marks"));
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}