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
import project.interest.SimpleInterest;
import project.Utilities;

public class Controller2 implements Initializable{
    @FXML
    private TextField pField,rField,yField,resultField;
    private SimpleInterest si;
    @FXML
    private Label status;
    @FXML
    private MenuItem goBack,exit;
    @FXML
    private MenuBar menuBar;
    public void handleClickButton(){
        try{
            si = new SimpleInterest(Float.parseFloat(pField.getText()), Integer.parseInt(rField.getText()), Integer.parseInt(yField.getText()));
        resultField.setText("" + si.getInterest());
    }catch(Exception e){
        status.setText("Enter a Valid Number...");
    }
    }
    @Override
    public void initialize(URL location, ResourceBundle resources) {
        new Utilities().handleMenuActions(menuBar, goBack, exit);
    }
}