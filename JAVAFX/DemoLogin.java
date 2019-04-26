import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class DemoLogin extends Application{
    Label prompt;
    public static void main(String [] args){
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Login");
        GridPane grid = new GridPane();// for the layout of button and labels and fields
        grid.setPadding(new Insets(10, 10, 10, 10));
        grid.setVgap(8);
        grid.setHgap(10);

        //username Label
        Label username = new Label("Username:");
        username.getStyleClass().add("bold-label");
        GridPane.setConstraints(username, 0, 0);

        // Field to Enter username
        TextField userField = new TextField("Ab");
        GridPane.setConstraints(userField, 1, 0);

        //password Label
        Label password = new Label("Password:");
        GridPane.setConstraints(password, 0, 1);

        //password field
        PasswordField passField = new PasswordField();
        passField.setPromptText("password ");
        GridPane.setConstraints(passField, 1, 1);

        //Login Button
        Button login = new Button("Login");
        login.setOnAction(e -> {
            if(!isCorrect(passField.getText()))
            {
                prompt = new Label("Password is Incorrect!");
                GridPane.setConstraints(prompt, 1, 2);
                GridPane.setConstraints(login, 1, 3);
                grid.getChildren().add(prompt);
            }
            else
            {
                grid.getChildren().remove(prompt);
                GridPane.setConstraints(login, 1, 2);
            }
        });
        GridPane.setConstraints(login, 1, 2);

        Button signUpButton = new Button("Sign Up");
        signUpButton.getStyleClass().add("button-blue");
        GridPane.setConstraints(signUpButton, 1, 3);

        grid.getChildren().addAll(username,userField,passField,password,login,signUpButton);
        Scene scene = new Scene(grid, 300, 170);
        scene.getStylesheets().add("Viper.css");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private boolean isCorrect(String password)
    {
        if(password.equals("pass"))
        return true;
        else 
        {
            return false;
        }    
    }
}