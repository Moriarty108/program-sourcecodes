package project;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import project.interest.SimpleInterest;

public class ControllerMain implements Initializable{
    @FXML
    private ListView list;
    @FXML
    private TextArea details;
    @FXML
    private Parent root;
    @Override
    public void initialize(URL location, ResourceBundle resources) {
        list.getItems().addAll("Compound Interest", "Simple Interest","Simple Percentage","Percent Increase/Decrease","Body Mass Index(BMI) Calculator");
        list.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
    }

    public void handleButtonClick(ActionEvent event){
        try{
            if(list.getSelectionModel().getSelectedItem().toString().equalsIgnoreCase("Compound Interest"))
        root = FXMLLoader.load(getClass().getResource("Scene1.fxml"));
        else if(list.getSelectionModel().getSelectedItem().toString().equalsIgnoreCase("Simple Interest"))
        root = FXMLLoader.load(getClass().getResource("Scene2.fxml"));
        else if(list.getSelectionModel().getSelectedItem().toString().equalsIgnoreCase("Simple Percentage"))
        root = FXMLLoader.load(getClass().getResource("Scene3.fxml"));
        else if(list.getSelectionModel().getSelectedItem().toString().equalsIgnoreCase("Percent Increase/Decrease"))
        root = FXMLLoader.load(getClass().getResource("Scene4.fxml"));
        else if(list.getSelectionModel().getSelectedItem().toString().equalsIgnoreCase("Body Mass Index(BMI) Calculator"))
        root = FXMLLoader.load(getClass().getResource("Scene5.fxml"));
    }
    catch(IOException e){
        e.printStackTrace();
    }
    catch(NullPointerException e){
        e.printStackTrace();
    }
        Stage stage = (Stage)((Node)event.getSource()).getScene().getWindow();
        stage.setScene(new Scene(root, 610, 400));
    }
}