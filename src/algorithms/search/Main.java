package algorithms.search;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;

import algorithms.sorted_array.Sort;

public class Main {
	
	static Random rand = new Random();
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		List<Integer> array = new ArrayList<Integer>();	
		
		int size = rand.nextInt(500);
		
		for(int i = 0; i < size; i++) {
			array.add(rand.nextInt(500));
		}
		
		array = removeDuplicates(array);
		
		List<Integer> sortedArray = Sort.selectionSort(array);		
		
		System.out.print("[ ");
		sortedArray.forEach(x -> System.out.print(x + ", "));
		System.out.print(" ]\n");
		
		System.out.println("Digite um valor: ");
		int item = sc.nextInt();
		
		System.out.println("Item: " + item);
		System.out.println("Position: " + Search.binarySearch(sortedArray, item));
	}
	
	private static List<Integer> removeDuplicates(List<Integer> list){
		Set<Integer> hashList = new HashSet<Integer>(list);
		return new ArrayList<Integer>(hashList);
	}

}
