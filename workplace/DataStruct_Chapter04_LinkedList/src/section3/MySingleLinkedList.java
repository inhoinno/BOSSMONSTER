package section3;
/*순서를 잘 생각한 ㅇㅣ중연결리스트의 삽입 sudo
 * aNode 앞에 새로운 노드 삽입
 * newNode.next = aNode
 * newNode.prev = aNode.prev
 * aNode.perv.next = newNode
 * aNode.prev = newNode
 * 
 * aNode 뒤에 삽입
 * NewNode.prev = aNode
 * NewNoed.next = aNode.next
 * aNode.next.prev =NewNode
 * aNode.next = NewNode
 * 
 * theNode 를 삭제
 * theNode.prev.next = theNode.next
 * theNode.next.prev = theNode.prev
 * */
import java.util.Iterator;
import java.util.NoSuchElementException;

public class MySingleLinkedList<T>{
	//member
	private Node<T> head; //첫번째 노드만ㅁㅁ
	private int size=0;
	//생성자
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
		 * 2. head -> Node1 순서 매우 중요
		 * 	   newNode-> Node1
		 * 3. head -> newNode 
		 */
		newNode.next = head;
		head = newNode;
		size++; // 연결리스트 가장중요한점은 극단적이고 특이한 경우에서도 작동하는가?
		//head =null; size=0; 인 경우에도 작동하는가?
		//결론은 작동함.
		// head= null -> newNode.next =null; , size++
		
	}
	private void addAfter(Node<T> before, T item){
		Node<T> temp = new Node<T>(item);
		//before 라는 노드를 어떻게 특정할것인지?
		temp.next = before.next;
		before.next = temp;
		size++; 
		//addAfter 는 간단. addBefore는 간단하지 않아요 ->단일 연결리스트라서 그래요.
	}
	public void add(int index, T item){ 	//Insert
		if(index < 0 || index >=size) //index 유효성 검사.
//			return ; //exception handling try catch 를 해야함.
			throw new IndexOutOfBoundsException();
		if(index ==0) //예외처리
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
		//단방향 연결리스트에서 어떤 노드 n을 삭제하기위해서는 그 앞의 노드 b 가 필요하다
	}
	public T remove(int index){ 	//Delete
		//index번째 노드를 삭제하는것이기 때문에 index-1 번째 노드를 아는게 중요합니다.
		if(index < 0 || index >=size) //index 유효성 검사.a
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
//		Node<T> p = head; //p는 삭제할 노드의 바로 전 
//		
//		while(p != null){
//			if(p.next.data.equals(item))
//				return removeAfter(p);
//			p=p.next;
//		}
//		return null;
		//나쁜방법은 아니지만 지저분한 문제(?)가 있다고 합니다.
		 //q는 항상 p의 한칸 뒤를 따라가도록 함. q.next = p
		
		Node <T> p = head;
		Node <T> q = null;
		while(p!=null && !p.data.equals(item)){
			q=p;
			p=p.next;//q는 항상 p의 직전노드
		} //반복문 종료시 p는 해당 데이터를 가진 노드이고 q는 p 바로 전의 노드를 가르킴
		
		if(p == null) //해당 데이터 없음
			return  false;
		if(q == null) {// 첫번째데이터가 삭제할 데이터인 경우. q==null
			T tmp = removeFirst();
			return (tmp != null);
		}
		else{
			T tmp = removeAfter(q);
			return (tmp != null);//대략수정
		}
	} //예외 생각하기 너무 어렵습니다.
	//1. linkedlist 가 0개일때 , head==null일때
	//2. 한개밖에 list에 없을때
	//3. 해당 데이터가 없을때

	//GETNODE
	public T get (int index){
		if(index < 0 || index >=size) //index 유효성 검사.
			return null ;
		return getNode(index).data; //wow
	}
	private Node<T> getNode (int index){
		if(index < 0 || index >=size) //index 유효성 검사.
			return null ;
		Node<T> p = head;
		for(int i =0; i<index; i++)
			p=p.next;
		return p;
	}
	
	//SEARCH SEARCH
	public int indexOf(T item){	 //Search
		Node<T> p = head; // Search 하기 위해 처음부터 수행하여야함
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
////		private Node<T> ptr//캡슐화된 노드를 사용자에게 줌 선물을 줬지만
//		public Iterator<T>iterator();
////		public E next(); //★사용자가 데이터를E로 받고,  자신은 한칸 앞next 으로 이동 하는. 
////		public boolean hasNode(); //다음노드가 존재하는지 검사
//	}
	public Iterator<T> iterator(){
		//has next
		//next
		//remove
		//새로운 iterator 를 반환함. 사용자는 iterator타입을 받음.
		//java interface + polymorphism다형성
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
//				return null; 예외처리를 제대로 해보자
				throw new NoSuchElementException();
			}
			T val = nextNode.data;
			nextNode = nextNode.next;
			return val;
		}
		public void remove(){
//			remove는 굉장히 까다롭고 큰 일임. before 가ㅏ 필요할듯 싶음.
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
