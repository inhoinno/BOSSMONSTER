package lesson4;
//인터페이스와 구현의 분리
//ㅁ 연결리스트는 리스트라는 추상적인 데이터타입을 구현하는 한가지 방법일 뿐 입니다.
//ㅁ 인터페이스와 구현을 분리하면 코드의 모듈성이 증가하며 코드의 유지/보수 코드의 재사용이 용이해진다.
       
/*
 * 
 * Implementatiojn & Interface
 * 
 * <Implementation>   |  	interface
 * 										T get(int index)
 * 										void add(int index) ...
 * 
 * Node<T> head;			T remove
 * class Node<T>{	 		boolean remove
 * Tdata;							int indexOf
 * Node<T> next; 			int size
 *  ....
 * 사용자는 Interface 만 알면 되고 Implementation 에 대해서는 알 필요도 없고 알 수 도 없당
 * 
 * */
 public class Interface_Impementation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
