package section3;
/*������ �� ������ �����߿��Ḯ��Ʈ�� ���� sudo
 * aNode �տ� ���ο� ��� ����
 * newNode.next = aNode
 * newNode.prev = aNode.prev
 * aNode.perv.next = newNode
 * aNode.prev = newNode
 * 
 * aNode �ڿ� ����
 * NewNode.prev = aNode
 * NewNoed.next = aNode.next
 * aNode.next.prev =NewNode
 * aNode.next = NewNode
 * 
 * theNode �� ����
 * theNode.prev.next = theNode.next
 * theNode.next.prev = theNode.prev
 * */
import java.util.Iterator;
import java.util.NoSuchElementException;

public class MySingleLinkedList<T>{
	//member
	private Node<T> head; //ù��° ��常����
	private int size=0;
	//������
	public MySingleLinkedList(){
		head = null;
		size =0;
	}
	
	//inner class
	private static class Node<T>{
			public T data;
			public Node<T> next;
			
			public Node (T item){
				data = item;
				next = null;
			}
		}
	//INSERT	INSERT
	private void addFirst(T item){
		Node<T> newNode = new Node<T>(item); //T : type parameter
		/*1. head -> Node1
		 *    newNode
		 * 2. head -> Node1 ���� �ſ� �߿�
		 * 	   newNode-> Node1
		 * 3. head -> newNode 
		 */
		newNode.next = head;
		head = newNode;
		size++; // ���Ḯ��Ʈ �����߿������� �ش����̰� Ư���� ��쿡���� �۵��ϴ°�?
		//head =null; size=0; �� ��쿡�� �۵��ϴ°�?
		//����� �۵���.
		// head= null -> newNode.next =null; , size++
		
	}
	private void addAfter(Node<T> before, T item){
		Node<T> temp = new Node<T>(item);
		//before ��� ��带 ��� Ư���Ұ�����?
		temp.next = before.next;
		before.next = temp;
		size++; 
		//addAfter �� ����. addBefore�� �������� �ʾƿ� ->���� ���Ḯ��Ʈ�� �׷���.
	}
	public void add(int index, T item){ 	//Insert
		if(index < 0 || index >=size) //index ��ȿ�� �˻�.
//			return ; //exception handling try catch �� �ؾ���.
			throw new IndexOutOfBoundsException();
		if(index ==0) //����ó��
			addFirst(item);
		else{
			Node<T> node = getNode(index-1);
			addAfter(node, item);
		}
	}
	
	//DELETE DELETE
	private T removeFirst(){
		if(head == null)
			return null;
		T tmp = head.data;
		head = head.next;
		size--;
		return tmp;
	}
	private T removeAfter(Node<T> before){
		if(before.next == null)
			return null;
		T tmp = before.next.data;
		before.next = before.next.next; 
		size--;
		return tmp;
		//�ܹ��� ���Ḯ��Ʈ���� � ��� n�� �����ϱ����ؼ��� �� ���� ��� b �� �ʿ��ϴ�
	}
	public T remove(int index){ 	//Delete
		//index��° ��带 �����ϴ°��̱� ������ index-1 ��° ��带 �ƴ°� �߿��մϴ�.
		if(index < 0 || index >=size) //index ��ȿ�� �˻�.a
//			return null ;
			throw new IndexOutOfBoundsException();

		if(index == 0)
			return removeFirst();
		else {
			Node<T> prev = getNode(index-1);
			return removeAfter(prev);
		}
	}
	public boolean remove(T item){
		//remove by data
//		Node<T> p = head; //p�� ������ ����� �ٷ� �� 
//		
//		while(p != null){
//			if(p.next.data.equals(item))
//				return removeAfter(p);
//			p=p.next;
//		}
//		return null;
		//���۹���� �ƴ����� �������� ����(?)�� �ִٰ� �մϴ�.
		 //q�� �׻� p�� ��ĭ �ڸ� ���󰡵��� ��. q.next = p
		
		Node <T> p = head;
		Node <T> q = null;
		while(p!=null && !p.data.equals(item)){
			q=p;
			p=p.next;//q�� �׻� p�� �������
		} //�ݺ��� ����� p�� �ش� �����͸� ���� ����̰� q�� p �ٷ� ���� ��带 ����Ŵ
		
		if(p == null) //�ش� ������ ����
			return  false;
		if(q == null) {// ù��°�����Ͱ� ������ �������� ���. q==null
			T tmp = removeFirst();
			return (tmp != null);
		}
		else{
			T tmp = removeAfter(q);
			return (tmp != null);//�뷫����
		}
	} //���� �����ϱ� �ʹ� ��ƽ��ϴ�.
	//1. linkedlist �� 0���϶� , head==null�϶�
	//2. �Ѱ��ۿ� list�� ������
	//3. �ش� �����Ͱ� ������

	//GETNODE
	public T get (int index){
		if(index < 0 || index >=size) //index ��ȿ�� �˻�.
			return null ;
		return getNode(index).data; //wow
	}
	private Node<T> getNode (int index){
		if(index < 0 || index >=size) //index ��ȿ�� �˻�.
			return null ;
		Node<T> p = head;
		for(int i =0; i<index; i++)
			p=p.next;
		return p;
	}
	
	//SEARCH SEARCH
	public int indexOf(T item){	 //Search
		Node<T> p = head; // Search �ϱ� ���� ó������ �����Ͽ�����
		int index=0;
		while(p != null){ //travel till (find data/end of the list)
			if(p.data.equals(item)) // cmp by .equals
				return index;
			p = p.next; //list traversal. very frequent, very important
			index++;
		}
		return -1;//No Data found
	}
	public int size(){
		int val = size;
		return val;
	}
//	public class Iterator<T> {
//		private Node<T> head;
////		private Node<T> ptr//ĸ��ȭ�� ��带 ����ڿ��� �� ������ ������
//		public Iterator<T>iterator();
////		public E next(); //�ڻ���ڰ� �����͸�E�� �ް�,  �ڽ��� ��ĭ ��next ���� �̵� �ϴ�. 
////		public boolean hasNode(); //������尡 �����ϴ��� �˻�
//	}
	public Iterator<T> iterator(){
		//has next
		//next
		//remove
		//���ο� iterator �� ��ȯ��. ����ڴ� iteratorŸ���� ����.
		//java interface + polymorphism������
		return new MyIterator();
	}
	private class MyIterator implements Iterator<T>{
		private Node<T> nextNode;
		public MyIterator(){
			nextNode = head;
		}
		public boolean hasNext(){
			return nextNode != null;
		}
		public T next(){
			if(nextNode == null){
//				return null; ����ó���� ����� �غ���
				throw new NoSuchElementException();
			}
			T val = nextNode.data;
			nextNode = nextNode.next;
			return val;
		}
		public void remove(){
//			remove�� ������ ��ٷӰ� ū ����. before ���� �ʿ��ҵ� ����.
		}
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MySingleLinkedList<String> list = new MySingleLinkedList<String>();
		list.add(0, "Saturday");
		list.add(1, "Friday");
		list.add(0, "Monday"); //Mon - Sat - Fri
		list.add(2, "Tuesday"); //Mon - Sat - Tue -Fri
		
		
		String str = list.get(2); // Tue
		list.remove(2); // Mon -Sat - Fri
		int pos = list.indexOf("Friday"); // pos = 2 
	}

}
