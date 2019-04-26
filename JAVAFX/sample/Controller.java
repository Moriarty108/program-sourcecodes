package sample;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import java.net.URL;
import java.util.ResourceBundle;

public class Controller {

    public Button button;
    public void handleButtonClick(){
        System.out.println("Run some code the user doesnt see");
        button.setText("Stop touching me!");
    }


}