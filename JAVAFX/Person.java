import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.beans.value.ObservableValue;

public class Person{
    private StringProperty firstName = new SimpleStringProperty(this,"firstName", "");

    public void setFirstName(String firstName){
        this.firstName.set(firstName);
    }

    public String getFirstName(){
        return firstName.get();
    }

    public StringProperty firstNameProperty(){
        return firstName;
    }
}