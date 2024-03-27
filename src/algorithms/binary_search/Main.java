package algorithms.binary_search;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

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
		
		List<Integer> sortedArray = Sort.selectionSort(array);
		
		System.out.print("[ ");
		sortedArray.forEach(x -> System.out.print(x + ", "));
		System.out.print(" ]\n");
		
		System.out.println("Digite um valor: ");
		int item = sc.nextInt();
		
		System.out.println("Item: " + item);
		System.out.println("Position: " + BinarySearch.search(sortedArray, item));
	}

}
