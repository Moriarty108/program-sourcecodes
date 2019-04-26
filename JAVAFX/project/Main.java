package project;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application{
    public static void main(String[] args) {
        launch(args);
    }
    @Override
    public void start(Stage primaryStage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("SceneMain.fxml"));
        Scene scene = new Scene(root, 600, 400);
        scene.getStylesheets().add("design.css");
        primaryStage.setTitle("Simple Program");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}