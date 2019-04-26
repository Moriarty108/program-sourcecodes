import java.io.*;
import java.util.*;
public class Set
{
    private List<Integer> array;

    public Set()
    {
        array = new ArrayList<Integer>();
    }

    public Set(int [] list)
    {
        array = new ArrayList<Integer>();
        for(Integer x : list)
        array.add(x);
    }

    public Set(int startingInt)
    {
        array = new ArrayList<Integer>();
        array.add(startingInt);
    }

    public Set union(Set B)
    {
        Iterator it = this.array.iterator();
        Set C = new Set();
        while(it.hasNext())
        {
            C.array.add((Integer)it.next());
        }
        it = B.array.iterator();
        while(it.hasNext())
        {
            if(!(C.array.contains(it.next())))
            C.array.add((Integer)it.next());
        }
        Collections.sort(C.array);
        return C;
    } 

    public Set interSection(Set B)
    {
        Set C = new Set();
        Iterator it = this.array.iterator();
        while(it.hasNext())
        {
            if(B.array.contains(it.next()))
            C.array.add((Integer)it.next());
        }
        Collections.sort(C.array);
        return C;
    }

    public void addToList()
    {
       Scanner sc = new Scanner(System.in);
        int i;
        i = sc.nextInt();
        array.add((Integer)i);
    }

    public void addArrayToList()throws Exception
    {
        Scanner sc = new Scanner(System.in);
        int n,a;
        System.out.print("Enter How many Integers you want to Enter:");
        n = sc.nextInt();
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter Element "+(i+1)+" :");
            a = sc.nextInt();
            array.add((Integer)a);
        }
    }
}