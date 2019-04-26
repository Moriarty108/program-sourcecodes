import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class ReadFile extends JFrame{

    private JTextField addressBar;
    private JEditorPane display;// Used to display an HTML Document

    //constructor
    public ReadFile()
    {
        super("Bucky Browser");
        addressBar = new JTextField("Enter a URL");
        addressBar.addActionListener(new ActionListener(){
        
            @Override
            public void actionPerformed(ActionEvent e) {
                loadCrap(e.getActionCommand());// will Load the content
            }
        });

        add(addressBar,BorderLayout.NORTH);// Adding Address Bar to the top
        display = new JEditorPane();
        display.setEditable(false);// now the text cannot be Edited
        display.addHyperlinkListener(
            new HyperlinkListener(){
            
                @Override
                public void hyperlinkUpdate(HyperlinkEvent e) {
                    if(e.getEventType()==HyperlinkEvent.EventType.ACTIVATED)
                    loadCrap(e.getURL().toString());
                }
            }
        );
        add(new JScrollPane(display),BorderLayout.CENTER);//for a scrollable view
        setSize(500,300);
        setVisible(true);
    }

    //load crap to display on the screen
    private void loadCrap(String userText){
        try {
            display.setPage(userText);// to display the doc
            addressBar.setText(userText);// to retain the url after redirecting
        } catch (Exception e) {
           System.out.println("crap!");
        }
    }
}