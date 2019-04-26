import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class DemoProperty extends Application{
    private Stage window;
    private Button button;
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        window = primaryStage;
        window.setTitle("Demo Property");

        Person bucky = new Person();
        bucky.firstNameProperty().addListener((v, oldValue, newValue) -> {
            System.out.println("Name changed to "+ newValue);
            System.out.println("getFirstName() " + bucky.firstNameProperty());
            System.out.println("getFirstName() " + bucky.getFirstName());
        });

        button = new Button("Button");
        button.setOnAction(e -> bucky.setFirstName("Porky"));

        StackPane layout = new StackPane();
        layout.getChildren().addAll(button);

        Scene scene = new Scene(layout, 400, 300);
        window.setScene(scene);
        window.show();

    }
}