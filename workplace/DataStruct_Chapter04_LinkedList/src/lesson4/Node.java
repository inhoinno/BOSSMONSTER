package lesson4;
//1. Node(Generic type)
//2. MyLinkedList (Whole single list)
public class Node<T> {
	public T data; //data를 말함
	public Node<T> next; //연결된 다음 노드 next를 말함
	
	public Node( T item){
		data = item;
		next = null;
	}
}
