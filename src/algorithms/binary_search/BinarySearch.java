package algorithms.binary_search;

import java.util.List;

public class BinarySearch{
	public static int search(List<Integer> array, Integer item){
		
		int low = 0;
		int high = array.size() - 1;
		
		while(low <= high) {
			int mid = (low + high) / 2;
			int guess = array.get(mid);
			
			if(guess == item) {
				return mid;
			}
			if(guess > item) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return -1;	
	}
} 
