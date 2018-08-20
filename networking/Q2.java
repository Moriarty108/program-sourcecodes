import java.util.Scanner;

class Q2{
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("\nEnter how many Bits you want to enter:");
        int n = sc.nextInt();
        int arr[] = new int[n];
        input(arr);
        System.out.println("\nCode before assigning Check Bits:");
        for (int var : arr) {
            System.out.print(var + " ");
        }
        assignCheckBits(arr);
        System.out.println("\nAfter Assigning Check Bits:");
        for (int var : arr) {
            System.out.print(var + " ");
        }
        System.out.println();
    }
    public static void input(int arr[]){
        int n = 1;
        int pos;
        System.out.println("\nEnter Information Bits...");
        for (int i = 2; i < arr.length; i++) {
            boolean skipFlag = false;
            pos = i + 1;
            for (int j = 0; j < (Math.sqrt(arr.length) + 1); j++) {
                if(pos == (Math.pow(2,j))){
                    skipFlag = true;
                    break;
                }
            }
            boolean validFlag = false;
            if(!skipFlag){
                if(n == (arr.length - Math.sqrt(arr.length)))
                break;
               System.out.print("Enter bit " + (n++) + ":");
               arr[i] = sc.nextInt();
               do {
                   if(arr[i]!=0 && arr[i]!=1){
                       validFlag = false;
                       System.out.println("\nError : Bit can either be '0' or '1'");
                       System.out.print("Enter Again :");
                       arr[i] = sc.nextInt();
                   }
                   else validFlag = true;
               } while (!validFlag);
            }
        
        }
    }
    public static void assignCheckBits(int arr[]){
        int val[] = new int[(int)Math.sqrt(arr.length)+1];
        for (int i = 0; i < arr.length; i++) {
            int pos = i + 1;
            int temp = pos;
            if(arr[i]==1){
                for (int j = 0; j < Math.sqrt(arr.length); j++) {
                    if((temp>=Math.pow(2,j))&&(temp<Math.pow(2,j+1))){
                        val[j]++;
                        temp-=Math.pow(2,j);
                        j = 0;
                    }
                    else if(temp==Math.pow(2,j+1)){
                        val[j+1]++;
                        temp-=Math.pow(2,j+1);
                        j = 0;
                    }
                    else if(temp == 1){
                        temp = 0;
                        val[0]++;
                        break;
                    }
                    else if(temp==0)
                    break;
                }
            }
        }
        for (int i = 0; i < val.length; i++) {
            if(!isEven(val[i]))
            arr[(int)Math.pow(2,i)-1] = 1;
        }
    }
    public static boolean isEven(int num){
        if(num%2 == 0)
        return true;
        else return false;
    }
}