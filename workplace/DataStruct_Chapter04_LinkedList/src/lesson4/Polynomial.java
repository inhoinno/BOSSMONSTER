package lesson4;
/*���׽��� ǥ��
 * ���Ḯ��Ʈ�� �̿��Ͽ� �ϳ��� ���׽��� ǥ���ϴ� Ŭ���� polynomial �� �ۼ�
 * ���׽��� �׵��� ���� ����Ʈ�� ǥ���Ѵ�.
 * �׵��� ������ ���ؼ� TODO : ������������ �����Ͽ� �����ϸ�, ���� ������ ���� 2���̻� �������ʰ� �Ѵ�
 * 
 * ���� ����� 0�� ���� ������ �ʰ� �Ѵ�
 * �ϳ��� ���� ����� ������ ���� ���ǵȴ�. �ϳ��� ���� ǥ���ϱ� ���� 
 * Ŭ���� Term �� �����Ѵ�.
 * Ŭ���� Polynomial�� ���׽��� ����ϴ� �޼���� ����ϴ� �޼��带 �����Ѵ�.
 * */

public class Polynomial {
	public char name; //f g h(x)
	public MySingleLinkedList<Term> terms ;	

	
	public Polynomial(char name){
		this.name = name;
		terms = new MySingleLinkedList<>();
	}
	
	public void addTerm(int coef, int expo){
		//������ ���׽� �ڱ� �ڽſ��� �߰� �ϴ� �޼���. +2x2 
		//���� ���� ���� �̹��ִٸ� ����� �����ϸ� �� if ����� 0�� �Ǹ� ������ �ؾ���
		//���ٸ� ���ο� ���� �����ϰ� �������� ����
		//TODO �������� �� �ڸ��� ��� ã�����ΰ�?
		// p�ش� �� q�� �� �� 
		
		if(coef == 0 ) //exception
			return; //����� 0�� ��
		Node<Term> p = terms.head , q =null; // p & q q�� ��� null �� �� �ִٴ°� ����
		
		while(p != null && p.data.expo > expo){ // SOLVE p = �ش��� q= ���� ���
			q = p;
			p = p.next;
		} //traversal
		if( p!=null && p.data.expo == expo){ //ã�Ҵµ�, ������ ���� �ִ°��
			p.data.coef += coef;
			if(p.data.coef == 0){ //����� 0�� �Ǵ� ��� delete
				// remove/delete node p
				if(q == null) //�� p is first
					terms.removeFirst();
				else
					terms.removeAfter(q);
				}
		}
		else {  //���� �� ���� ���°�� ���ο� �� add
			Term t =new Term(coef, expo);
			if (q == null)
				terms.addFirst(t);
			else
				terms.addAfter(q, t);
			
		}
		
	}
	public int calc (int x){
		int result =0;
		Node<Term> p = terms.head; // p 
		while(p != null ){ 
			result += p.data.calc(x);
			p = p.next;
		} //traversal
		return result;
	}
	public String toString(){
//		String result ="";
//		Node<Term> p = terms.head; // p 
//		while(p != null ){ 
//			result += ("+" + p.data.toString();
//			p = p.next;
//		} //traversal
//		return result;
		
		StringBuilder sb = new StringBuilder();
		sb.append(name + "(x) = ");
		Node<Term> p = terms.head;
		while(p!=null){
			sb.append("+" + p.data.toString());
			p = p.next;
		}
		return sb.toString();
	}
	
}
