import javafx.application.Application;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class DemoPropertyBinding extends Application{
    private Stage window;
    private Button button;
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        window = primaryStage;
        window.setTitle("Demo Property");

        IntegerProperty x = new SimpleIntegerProperty(3);
        IntegerProperty y = new SimpleIntegerProperty();
        y.bind(x.multiply(10));
        System.out.println("x :" + x.getValue());
        System.out.println("y :" + y.getValue());

        x.setValue(9);
        System.out.println("x :" + x.getValue());
        System.out.println("y :" + y.getValue());

        button = new Button("Button");

        StackPane layout = new StackPane();
        layout.getChildren().addAll(button);

        Scene scene = new Scene(layout, 400, 300);
        window.setScene(scene);
        window.show();

    }
}