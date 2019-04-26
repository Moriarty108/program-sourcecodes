import javax.swing.JFrame;
class ClientTest
{
     public static void main(String[] args) {
        Client charlie = new Client("192.168.1.5");// argument takes local ip address
        charlie.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        charlie.startRunning();
   }
}