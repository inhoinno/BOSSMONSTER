package section4;

import java.util.Iterator;
import java.util.ListIterator;

/*OutLine ����
 *public class KWLinkedList <E>{
 * 		private Node<E> head =null;
 *		private Node <E> tail =null;
 * 		private int size=0;
 * }
 * priavte static class Node<E>{
 * //innerclass
 *  }
 *  private class KWListIterator implements ListIterator<E>{
 *  //next hasnext add remove set ....
 *  }
 *  
 * */
public class KWLinkedList<E> {
	
	private Node<E> head = null;
	private Node<E> tail = null;
	private int size =0;
	//inner class
	private static class Node<T>{ //inner class static = Ŭ������ ���
		//�ٸ� ������� ��ü���� ȣ�� �� �� ����
		T data;
		Node<T> next;
		Node<T> prev;
		
		public Node(T item){
			data = item;
			next =null;
			prev = null;
		}
	}
//	public E get(int index){}
//	public void add(int index, E obj){}
//	public int indexOf(E obj){}
//	public E remove (int index){}
//	public boolean remove(E obj){}
//	public int size(){}
	public int indexOf(E item){
		return 0;
	}
	public void add(int index, E item){
		
	}
	public E get (int index){
		return null;
	}
	public boolean remove(E obj){
		return true;
	}
	public void remove(int index){
		
	}
	public int size(){
		return 0;
	}
	
	//����ڿ��� �� �޼��� Iterator ��ȯ
	public Iterator<E> iterator(){
		return new KWListIterator(0); //������ �۾��� ���� iterator next hasnext remove
	}
	public ListIterator<E> listiterator(){
		return new KWListIterator(0); //3 +
	}
	public ListIterator<E>listiterator(int index){
		return new KWListIterator(index);
	}
//inner class non-static =>head � ������ �� ����.
	private class KWListIterator implements ListIterator<E>{
		//data member and constructor
		private Node<E> nextItem; // refer the next Node
		private Node<E> lastItemReturned; //������� or�������(���⿡ ����)�� ����Ŵrefer the node that was returned by next or prev
		private int index; //next node's index

		public KWListIterator(int index){ //index���� ��尡 nextItem
			//?
		}
		@Override
		public void add(E arg0) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public boolean hasNext() {
			// TODO Auto-generated method stub
			return false;
		}

		@Override
		public boolean hasPrevious() {
			// TODO Auto-generated method stub
			return false;
		}

		@Override
		public E next() {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public int nextIndex() {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public E previous() {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public int previousIndex() {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public void remove() {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void set(E e) {
			// TODO Auto-generated method stub
			
		}
		
	}


	
}
