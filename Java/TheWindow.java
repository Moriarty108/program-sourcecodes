import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;

public class TheWindow extends JFrame{

    private JSlider slider;
    private DemoSlider myPanel;

    public TheWindow(){
        super("Title");
        myPanel = new DemoSlider();
        myPanel.setBackground(Color.ORANGE);
        slider = new JSlider(SwingConstants.HORIZONTAL, 0 , 200 ,10);
        slider.setMajorTickSpacing(10);//width for little lines on slider
        slider.setPaintTicks(true);// actually paints them
        slider.addChangeListener(
            new ChangeListener(){
            
                @Override
                public void stateChanged(ChangeEvent e) {
                    myPanel.setD(slider.getValue());
                }
            }
        );

        add(slider,BorderLayout.SOUTH);
        add(myPanel);
    }
}