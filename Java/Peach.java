import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class Peach extends JFrame
{
   private JButton b;
   private Color color = Color.WHITE;
   private JPanel panel;

   public Peach()
   {
       super("Title");
       panel = new JPanel();
       panel.setBackground(color);
       b = new JButton("Color");
       b.addActionListener(new ActionListener(){
       
           @Override
           public void actionPerformed(ActionEvent e) {
               color = JColorChooser.showDialog(panel,"Pick your Color",color);
               if(color == null)
               color = Color.WHITE;
               panel.setBackground(color);
           }
       });
       add(panel,BorderLayout.CENTER);
       add(b,BorderLayout.SOUTH);
   }
    
}