package algs11;
import stdlib.*;
import java.util.NoSuchElementException;
import java.util.Scanner;

//Application for adding and popping reservation names 
public class restaurant {

	Node first = null;
	int N = 0;
	static class Node {
       public Node() { }
       public String name;
       public Node next;

    }
	
	//checks if list is empty 
    public boolean isEmpty () {
        //TODO
        return N==0;
    }
    
    //pushes reservation onto system 
    public void push(String name)
    {
    	Node reservation = new Node();
    	reservation.name = name;
    	
    	if(first == null)
    	{
    		first = reservation;
    	}
    	else 
    	{
    		Node x = first;
    		while(x.next != null)
    		{
    			x = x.next;
    		}
    		
    		x.next = reservation;
    	}
    			
    }
    
    public String pop()
    {
    	if(first == null)
    	{
    		return null;
    	}
    	Node x = first;
    	first = first.next;
    	
    	return x.name;
    }
    
    public void printList()
    {
    	if(first == null)
    	{
    		System.out.println("List empty");
    		return;
    	}
    	System.out.print("List: ");
    	for(Node x = first; x != null; x = x.next)
    	{
    		System.out.print(x.name + ", ");
    	}
    	System.out.println();
    }
    
    public static void printMenu()
    {
    	System.out.println("Enter options from Menu: ");
    	System.out.println("A: Enter a reservation");
    	System.out.println("B: Remove reservation from list");
    	System.out.println("C: Print reservation list");
    	System.out.println("D: Quit program");
    	System.out.println("E: For Menu");

    }
    
    public static void main(String[] args)
    {
    	Scanner scan = new Scanner(System.in);
    	printMenu();
    	System.out.print("Enter your option: ");
    	String option = scan.next();
    	restaurant list = new restaurant();
    	while(!option.equals("D"))
    	{
    		if(option.equals("A"))
    		{
    			System.out.print("Enter name:  ");
    			String n = scan.next();
    			list.push(n);
    		}
    		else if(option.equals("B"))
    		{
    			list.pop();
    		}
    		else if(option.equals("C"))
    		{
    			list.printList();
    		}
    		else if(option.equals("D"))
    		{
    			break;
    		}
    		else if(option.equals("E"))
    		{
    			printMenu();
    		}
    		else 
    		{
    			System.out.print("Wrong input: try again! ");
    			option = scan.next();
    		}
    		System.out.print("Enter next option  ");
    		option = scan.next();
    			
    	}
    	scan.close();

    }
    

}