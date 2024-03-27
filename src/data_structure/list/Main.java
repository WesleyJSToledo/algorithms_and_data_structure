package data_structure.list;

public class Main {
	
	/*
	 * Implementação Básica de uma Lista onde posso adicionar, remover, pegar um valor de uma posição, ver se está vazia
	 * 
	 * Basic Implementation of a List where I can add, remove, get a value from a position, see if it is empty
	 */
	
	public static void main(String[] args) {
		List<Integer> list = new List<Integer>();
		
		for(int i = 0; i < 10; i++) {
			list.add(i);
		}
		
		System.out.println(list.get(5));
		
		
		for(int i = 0; i < list.size(); i++) {
			System.out.printf("%d", list.get(i));
		}
		System.out.println();
		System.out.println(list.size());
		
		list.remove(3);
		
		for(int i = 0; i < list.size(); i++) {
			System.out.printf("%d", list.get(i));
		}
	}
}
