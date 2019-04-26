import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * FileOptions
 */
public class FileOptions {
    private static BufferedReader br;
    public static void main(String[] args) throws IOException,Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        boolean loopFlag = true;
        while(loopFlag)
        {
            System.out.print("\n>");
         String command = br.readLine();
         if(command.compareToIgnoreCase("exit") == 0)
         loopFlag = false;
         else
          {
            String[] commandPart = command.split(" ");
            execute(commandPart[0], commandPart[1]);
          }
        }
    }

    public static void execute(String command,String filePath)throws IOException,Exception{
        File file = new File(filePath);
        if(command.compareToIgnoreCase("delete") == 0){
            if(file.delete())
            System.out.println("File Deleted!");
            else
            System.out.println("Error Deleting File");
        }
        else if(command.compareToIgnoreCase("new") == 0){
        if(file.createNewFile())
            System.out.println("File Created!");
            else
            System.out.println("Error Creating File");
        }
        else if(command.compareToIgnoreCase("exists") == 0){
            if(file.exists())
            System.out.println("File Exits!");
            else
            System.out.println("File Does not Exists"); 
        }
        else if(command.compareToIgnoreCase("exec") == 0){
            Runtime.getRuntime().exec(file.getAbsolutePath(),
             null,
             new File("C:/Users/Moriarty/Desktop/Coding lang/Java/Seperate/"));
        }
        else throw new Exception();
    }

}