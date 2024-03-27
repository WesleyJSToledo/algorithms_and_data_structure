package data_structure.list;

public class List<T>{
	Node<T> first;
	Node<T> last;
	
	public List() {
		first = last = null;
	}
	
	public void add(T value) {
		Node<T> list = new Node<T>();
		
		list.value = value;
		list.next = null;
		if(isEmpty()) {
			first = list;
		} else {
			last.next = list;
		}
		last = list;
	}
	
	public void add(int index, T value) {
		if(index < 0) {
			return;
		}
		
		Node<T> list = new Node<T>();
		list.value = value;
		
		if(index == 0) {
			list.next = first;
			first = list;
		} else {
			Node<T> current = first;
			 for(int i = 1; i < index && current.next != null; i++) {
				 current = current.next;
			 }
			 list.next = current.next;
			 current.next = list;
			 if(list.next == null) {
				 last = list;
			 }
		}
	}
	
	public int size() {
		Node<T> current = first;
		int i = 0;
		while(current != null) {
			current = current.next;
			i++;
		}
		return i;
	}
	
	public void remove (int index) {
		Node<T> current, previous;
		
		current = previous = first;
		for(int i = 0; i < index; i++) {
			current = current.next;
		}
		
		previous = current;
		current = current.next;
		
		if(current == null) {
			return;
		}
		if(current == first) {
			first = first.next;
			previous = null;
		}
		else if(current == last){
			last = previous;
			last.next = null;			
		} else {
			previous.next = current.next;
			current = null;
		}
	}
	public T get(int index) {
		Node<T> current =  first;
		
		for(int i = 0; i < index && current.next != null; i++) {
			current = current.next;
		}
		return current.value;
		
	}
	
	public boolean isEmpty() {
		return first == null;
	}
}

class Node<T>{
	public T value;
	public Node<T> next;
}
