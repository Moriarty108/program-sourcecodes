import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class App2 extends Application  {
    Stage window;
    Button button;

    @Override
    public void start(Stage primaryStage) throws Exception{
        window = primaryStage;
        window.setTitle("ThenewBoston");

        button = new Button("Click Me");
        button.setOnAction(e -> {
            boolean result = ConfirmBox.display("Title of the Box", "Are u sure?");
            System.out.println(result);
        });
        StackPane layout = new StackPane();
        layout.getChildren().add(button);
        Scene scene = new Scene(layout,300,250);
        window.setScene(scene);
        window.show();
    }

    public static void main(String [] args)
    {
        launch(args);
    }

   
}