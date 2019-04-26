import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Client extends JFrame{

    private JTextField userText;
    private JTextArea chatWindow;
    private ObjectOutputStream output;
    private ObjectInputStream input;
    private String message = "";
    private String serverIP;
    private Socket connection;

    //constructor
    public Client(String host){
        super("Client mofo!");
        serverIP = host;
        userText = new JTextField();
        userText.setEditable(false);
        userText.addActionListener(new ActionListener(){
        
            @Override
            public void actionPerformed(ActionEvent e) {
                sendData(e.getActionCommand());
                userText.setText("");
            }
        });
        add(userText,BorderLayout.NORTH);
        chatWindow = new JTextArea();
        add(new JScrollPane(chatWindow));
        setSize(300,150);
        setVisible(true);
    }

    // connect to server
    public void startRunning(){
        try {
            connectToServer();
            setupStreams();
            whileChatting();
        } catch (EOFException e) {
            showMessage("\n Client terminated connection... \n");
        }
        catch(IOException e){
            e.printStackTrace();
        }
        finally{
            closeCrap();
        }
    }

    // connect to server
    private void connectToServer() throws IOException{
        showMessage("Attempting connection... \n");
        connection = new Socket(InetAddress.getByName(serverIP), 6789);// (IPAddress,portNumber)
        showMessage("Connected to: " + connection.getInetAddress().getHostName());
    }

    //setup streams to send and recieve messages
    private void setupStreams() throws IOException{
        output = new ObjectOutputStream(connection.getOutputStream());
        output.flush();
        input = new ObjectInputStream(connection.getInputStream());
        showMessage("\n Dude your streams are now good to go !");
    }

    //while chatting with server
    private void whileChatting() throws IOException{
        ableToType(true);
        do {
            try {
                message = (String) input.readObject();
                showMessage("\n" + message);
            } catch (ClassNotFoundException e) {
                showMessage("\n I dont know that object type");
            }
        } while (! message.equals("SERVER - END"));
    }

    //updates chatWindow
    private void showMessage(final String text)// appends the GUI without creating a new one
    {
        SwingUtilities.invokeLater(new Runnable(){
        
            @Override
            public void run() {
                chatWindow.append(text);
            }
        });
    }

    // close the streams and sockets
    private void closeCrap()
    {
        showMessage("\n Closing crap down...");
        ableToType(false);
        try {
            output.close();
            input.close();
            connection.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // send messages to server
    private void sendData(String message)
    {
        try {
            output.writeObject("CLIENT - "+ message);
            output.flush();
            showMessage("\n CLIENT - "+ message);
        } catch (IOException e) {
            chatWindow.append("\n Something messed up sending message");
        }
    }

    private void ableToType(final boolean tof)
    {
        SwingUtilities.invokeLater(new Runnable(){
        
            @Override
            public void run() {
                userText.setEditable(tof);
            }
        });
    }
}