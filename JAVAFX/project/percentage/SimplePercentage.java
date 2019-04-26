package project.percentage;
public class SimplePercentage{
    private float rate,num;
    public SimplePercentage(float rate,float num){
        this.rate = rate;
        this.num = num;
    }
    public float getResult()
    {
        float per = (float)rate/100;
        return (float)per * num;
    }

    public float getPercentageIncrease(){
        return getResult() + num;
    }

    public float getPercentageDecrease(){
        return num - getResult();
    }
}