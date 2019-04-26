package project;
import javafx.scene.control.MenuBar;
import java.io.IOException;
import javafx.scene.control.MenuItem;
import javafx.stage.Stage;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.fxml.FXMLLoader;;

public class Utilities{
    public void handleMenuActions(MenuBar menuBar,MenuItem goBack,MenuItem exit){
        goBack.setOnAction(e ->{
            try{
            Parent root = FXMLLoader.load(getClass().getResource("SceneMain.fxml"));
            Stage stage = (Stage)((Node)menuBar).getScene().getWindow();
            stage.setScene(new Scene(root, 600, 400));
        }
        catch(IOException error){
            error.printStackTrace();
        }
        });
        exit.setOnAction(e-> {
            Stage stage = (Stage)((Node)menuBar).getScene().getWindow();
            stage.close();
        });
    }

    public static float getBMI(float height,float weight){
        return (float)weight/(height * height);
    }
    
}