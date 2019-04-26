package project;
import project.interest.CompoundInterest;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import project.Utilities;

public class Controller implements Initializable{
    @FXML
    private ComboBox comboBox;
    private CompoundInterest it;
    @FXML
    private TextField balanceField,rateField,yrsField,result;
    @FXML
    private Label status;
    @FXML
    private MenuItem goBack,exit;
    @FXML
    private MenuBar menuBar;
@Override
public void initialize(URL location, ResourceBundle resources) {
    comboBox.getItems().addAll("Yearly","Half-Yearly","Quarterly","Monthly","Weekly","Daily");
    new Utilities().handleMenuActions(menuBar, goBack,exit);

    }

    public void handleButtonClick()
    {
        try
        {it = new CompoundInterest(Float.parseFloat(balanceField.getText()), Integer.parseInt(yrsField.getText()), Integer.parseInt(rateField.getText()), comboBox.getValue().toString());
        result.setText("" + it.getInterest());
    }
    catch(Exception e)
    {
        status.setText("Enter a Valid Number...");
    }
    }
}