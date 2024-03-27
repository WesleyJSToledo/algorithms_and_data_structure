package algorithms.sorted_array;

import java.util.ArrayList;
import java.util.List;

public class Sort{
	
	public static List<Integer> selectionSort(List<Integer> array) {
		List<Integer> sortArray = new ArrayList<Integer>();
		
		for(int i = 0; i < array.size(); i++) {
			int smaller = searchMin(array);
			sortArray.add(array.remove(smaller));
		}
		return sortArray;
	}
	
	private static int  searchMin(List<Integer> array) {
		int smaller = array.get(0);
		int smallerIndex = 0;
		for(int i = 1; i < array.size(); i++) {
			if(array.get(i) < smaller) {
				smaller = array.get(i);
				smallerIndex = i;
			}
		}
		
		return smallerIndex;
	}
}
