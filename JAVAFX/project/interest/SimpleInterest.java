package project.interest;

public class SimpleInterest{
    private float principal;
    private int rate;
    private int noOfYrs;

    public SimpleInterest(float principal, int rate, int noOfYrs){
        this.principal = principal;
        this.rate = rate;
        this.noOfYrs = noOfYrs;
    }

    public float getInterest()
    {
        float amount;
        amount = ((float)principal * rate * noOfYrs)/100;
        return (amount + principal);
    }
}