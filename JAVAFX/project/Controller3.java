package project;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import project.percentage.SimplePercentage;
import project.Utilities;

public class Controller3 implements Initializable{
    @FXML 
    private TextField num1;
    @FXML
    private TextField num2;
    @FXML
    private TextField result;
    @FXML
    private MenuItem goBack;
    @FXML
    private MenuItem exit;
    @FXML
    private Label status;
    @FXML
    private MenuBar menuBar;
    @Override
    public void initialize(URL location, ResourceBundle resources) {
        new Utilities().handleMenuActions(menuBar, goBack, exit);
    }
    @FXML
    public void handleButtonClick(){
        try{
            if(Float.parseFloat(num1.getText())>100)
            throw new Exception();
            SimplePercentage s = new SimplePercentage(Float.parseFloat(num1.getText()), Float.parseFloat(num2.getText()));
            result.setText("" + s.getResult());
        }
        catch(Exception e)
        {
            status.setText("Enter a valid Number....");
        }
    }
}