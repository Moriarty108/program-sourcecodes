import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
class gameProg {
    private static BufferedReader br;
    private static final double DEFAULT_VERSION = 1.00;
    private static final int MENU_EXIT = 4;

    public static void main(String[] args) throws IOException,Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Integer, Game> hashMap = new HashMap<>();
        int mc = 3;
        while ((mc = takeMenuInput()) != MENU_EXIT) {
            if(mc == 1)
            {
                Game game = readGame();
            hashMap.put(game.getGID(), game);
            }
            else if(mc == 2){
                System.out.println("Enter the Game Id:");
                int gId = Integer.parseInt(br.readLine());
                if(!hashMap.containsKey(gId)){
                    System.out.println("Not a valid Game Id");
                }
                else {
                    detailsChangerMenu();
                    System.out.println("Choose :");
                    changeDetails(Integer.parseInt(br.readLine()), gId, hashMap);
                }
            }
            else{
                System.out.println(hashMap);
            }
        }
    }

    private static Game readGame() throws IOException {
        System.out.println("Enter the Name of Game :");
        Game game = new Game(br.readLine(), DEFAULT_VERSION);
        System.out.println("Enter the Game Engine :");
        game.setEngineUsed(br.readLine());
        System.out.println("Enter the Game Publisher :");
        game.setPub(br.readLine());
        System.out.println("Enter the Game Developer :");
        game.setDev(br.readLine());
        return game;
    }

    private static int takeMenuInput() throws IOException {
        int menuControl = MENU_EXIT;
        System.out.println("[1] Enter a Game");
        System.out.println("[2] Change a Game's Details");
        System.out.println("[3] Display all the Games");
        System.out.println("[4] Exit");
        System.out.println("Choose : ");
        menuControl = Integer.parseInt(br.readLine());
        return menuControl;
    }
    private static void detailsChangerMenu(){
        System.out.println("[1] Change Game's Version");
        System.out.println("[2] Change Game Engine");
        System.out.println("[3] Change Game's Publisher");
        System.out.println("[4] Change Game's Developer");
    }
    private static void changeDetails(int menuControl,int gId, HashMap<Integer,Game> map) throws Exception{
        Game g = map.get(gId);
        switch (menuControl) {
            case 1:
                System.out.println("Enter the New Game Version :");
                g.setVersion(Double.parseDouble(br.readLine()));
                break;
            case 2:
            System.out.println("Enter the Game Engine : ");
            g.setEngineUsed(br.readLine());
            break;
            case 3:
            System.out.println("Enter the Publisher : ");
            g.setPub(br.readLine());
            break;
            case 4: 
            System.out.println("Enter the Developer : ");
            g.setDev(br.readLine());
            break;    
            default:
            throw new Exception();
        }
        map.replace(gId, g);
    }
}