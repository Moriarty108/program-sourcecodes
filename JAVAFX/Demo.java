import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Demo extends Application {
    Button button;
    @Override
    public void start(Stage primaryStage) throws Exception{
        primaryStage.setTitle("Title of the Window");
        button = new Button();
        button.setText("Click Me");
        button.setOnAction(e -> {
            System.out.println("hey now...");
            System.out.println("Hello...");
        });// lambda expression
        StackPane layout = new StackPane();
        layout.getChildren().add(button);
        Scene scene = new Scene(layout , 300, 250);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String [] args)
    {
        launch(args);
    }

}