import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class MenuDemo extends Application{
    private BorderPane layout;
    private Menu fileMenu;
    private MenuBar menuBar;
    private Stage window;

    public static void main(String [] args){
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        window = primaryStage;
        window.setTitle("Menu Demo");

        fileMenu = new Menu("_File");// underscore for a shortcut(by holding down ALT)
        MenuItem newFile = new MenuItem("New...");
        newFile.setOnAction(e -> System.out.println("Create a new file"));

       fileMenu.getItems().add(newFile);
       fileMenu.getItems().add(new MenuItem("Open..."));
       fileMenu.getItems().add(new MenuItem("Save..."));
       fileMenu.getItems().add(new MenuItem("Settings..."));
       fileMenu.getItems().add(new MenuItem("Exit..."));

       menuBar = new MenuBar();
       menuBar.getMenus().addAll(fileMenu);

       layout = new BorderPane();
       layout.setTop(menuBar);

       Scene scene = new Scene(layout, 400, 300);
       window.setScene(scene);
       window.show();
    }
}