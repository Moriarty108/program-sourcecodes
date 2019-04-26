package project;
import java.net.URL;
import java.util.ResourceBundle;
import project.Utilities;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextField;
import project.percentage.SimplePercentage;

public class Controller4 implements Initializable{
    @FXML
    private ComboBox mode;
    @FXML
    private TextField rField;
    @FXML
    private TextField fromField;
    @FXML
    private TextField result;
    @FXML
    private MenuBar menuBar;
    @FXML
    private MenuItem goBack;
    @FXML
    private MenuItem exit;
    @FXML
    private Label status;
    public void handleButtonClick(){
        try {
            SimplePercentage sp = new SimplePercentage(Float.parseFloat(rField.getText()), Float.parseFloat(fromField.getText()));
            if(mode.getValue().toString().equalsIgnoreCase("%increase"))
            result.setText(""+ sp.getPercentageIncrease());
            else if(mode.getValue().toString().equalsIgnoreCase("%decrease"))
            result.setText(""+ sp.getPercentageDecrease());
        }
        catch (Exception e) {
            status.setText("Invalid Number or Mode not Selected...");
        }
    }
    @Override
    public void initialize(URL location, ResourceBundle resources) {
        mode.getItems().addAll("%increase","%decrease");
        new Utilities().handleMenuActions(menuBar, goBack, exit);
    }
}