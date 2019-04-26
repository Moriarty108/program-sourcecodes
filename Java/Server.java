import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Server extends JFrame{

    private JTextField userText;
    private JTextArea chatWindow;
    private ObjectOutputStream output;// to receive output
    private ObjectInputStream input;// to receive input
    private ServerSocket server;
    private Socket connection;

    //constructor
    public Server()
    {
        super("Bucky's Instant Messenger");
        userText = new JTextField();
        userText.setEditable(false);// if u are not connected to anyone then it makes sense
        userText.addActionListener(new ActionListener(){
        
            @Override
            public void actionPerformed(ActionEvent e) {
                sendMessage(e.getActionCommand());
                userText.setText("");
            }
        });
        add(userText,BorderLayout.NORTH);
        chatWindow = new JTextArea();
        add(new JScrollPane(chatWindow));
        setSize(300,150);
        setVisible(true);
    }

    //set up and run the server
    public void startRunning(){
        try {
            server = new  ServerSocket(6789, 100);//  ServerSocket(portNumber,maxConnections)
            while(true){
                try {
                    waitForConnection();// setting up connection
                    setupStreams();// streams so that messages can be sent and received
                    whileChatting();// to send messages back and forth
                } catch (EOFException e) {
                    showMessage("\n Server ended the Connection");// to terminate the connection
                }
                finally{
                    closeCrap();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //wait for connection, then display connection info
    private void waitForConnection() throws IOException{
        showMessage("Waiting for someone to connect... \n");
        connection = server.accept();// accepts a connection to the Socket only if it server recieves a connection;linking the ServerSocket and Socket
        showMessage(" Now connected to" +connection.getInetAddress().getHostName());
    }

    //get stream to send and recieve data
    private void setupStreams() throws IOException{
        output = new ObjectOutputStream(connection.getOutputStream());// to connect to other computer through the "connection " Socket
        output.flush();// to clean out the crap left in the Stream
        input = new ObjectInputStream(connection.getInputStream());// to recieve stuff from
        showMessage("\n Streams are now setup! \n");
    }

    // during the chat conversation
    private void whileChatting() throws IOException{
        String message = " You are now connected! ";
        sendMessage(message);
        ableToType(true);
        do {
            try {
                message = (String) input.readObject();
                showMessage("\n"+ message);
            } catch (ClassNotFoundException e) {
                showMessage("\n idk wtf that user send ! ");
            }
        } while (!message.equals("CLIENT - END"));
    }

    //Closing Down the Streams and Sockets after chatting bit is done
    private void closeCrap(){
        showMessage("\n Closing connection... \n");
        ableToType(false);
        try {
            output.close();
            input.close();
            connection.close();
        } catch (IOException e) {
           e.printStackTrace();
        }
    }

    //send a mesage to client
    private void sendMessage(String message)
    {
        try {
            output.writeObject("SERVER - " + message);
            output.flush();
            showMessage("\n SERVER - " + message);
        } catch (IOException e) {
            chatWindow.append("\n ERROR: DUDE I CANT SEND THAT MESSAGE");
        }
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

    // let the user type stuff into their box
    private void ableToType(final boolean tof){
        SwingUtilities.invokeLater(new Runnable(){
        
            @Override
            public void run() {
                userText.setEditable(tof);
            }
        });
    }

}