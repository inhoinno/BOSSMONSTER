package lesson4;
//1. Node(Generic type)
//2. MyLinkedList (Whole single list)
public class Node<T> {
	public T data; //data�� ����
	public Node<T> next; //����� ���� ��� next�� ����
	
	public Node( T item){
		data = item;
		next = null;
	}
}
