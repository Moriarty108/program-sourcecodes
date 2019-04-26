package project.interest;
import javafx.scene.control.ComboBox;

public class CompoundInterest{
    private int noOfYrs;
    private float principal;
    private int rate;
    private int n;

    public CompoundInterest(){
        noOfYrs = 0;
        principal = 0;
        rate = 0;
    }
    public CompoundInterest(float principal,int noOfYrs,int rate,String s){
        this.noOfYrs = noOfYrs;
        this.principal = principal;
        this.rate = rate;
        setN(s);
    }

    private void setN(String s){
        if(s.equalsIgnoreCase("Yearly"))
        n = 1;
        if(s.equalsIgnoreCase("Monthly"))
        n = 12;
        if(s.equalsIgnoreCase("Quarterly"))
        n = 4;
        if(s.equalsIgnoreCase("Weekly"))
        n = 52;
        if(s.equalsIgnoreCase("Daily"))
        n = 365;
        if(s.equalsIgnoreCase("Half-Yearly"))
        n = 2;

    }

    public float getInterest()
    {
        double r;
        float amount;
        r = ((double)rate)/(100);
        amount = (float)(principal * (Math.pow( (1+(r/n)), (n * noOfYrs))));
        return amount;
    }
}