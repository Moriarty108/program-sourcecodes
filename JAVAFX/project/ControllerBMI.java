package project;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextField;
import project.Utilities;

public class ControllerBMI implements Initializable{
    @FXML
    private TextField height;
    @FXML
    private TextField weight;
    @FXML
    private TextField result;
    @FXML
    private Label status;
    @FXML 
    private MenuItem goBack;
    @FXML 
    private MenuItem exit;
    @FXML 
    private MenuBar menuBar;
    public void handleButtonClick(){
        try{
            result.setText("" + Utilities.getBMI(Float.parseFloat(height.getText()), Float.parseFloat(weight.getText())));
        }
        catch(Exception e){
            status.setText("Enter valid Values...");
        }
    }
    @Override
    public void initialize(URL location, ResourceBundle resources) {
        new Utilities().handleMenuActions(menuBar, goBack, exit);
    }
}