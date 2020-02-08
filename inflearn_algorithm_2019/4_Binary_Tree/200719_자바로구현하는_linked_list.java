//list를구성하는 node 클래스
class ListNode{
    private String data; //노드에 저장할 data변수
    public ListNode link; //다른노드를 참조할 링크 노드 (부모 등)

    public ListNode(){
        this.data. = null;
        this.link = null;
    }
    public ListNode(String data, ListNode link){
        this.data = data;
        this.link = link;

    }// 생성자 메서드2

    public String getData(){
        return this.data;

    }
}
public class LinkedList{
    private ListNode head;

    public LinkedList (){
        head =null;
    }
    //Insert
    //중간에 노드를 삽입하는 경우. 
    public InsertNode(ListNode prenode, String data){
        ListNode newNode = new ListNode(data); //매개변수를 받아 newnode 생성함
        //prenode.link는 prenode가 참조하는 노드를 가르키므로 prenode.link를 자식노드라고 생각
        newNode.link = prenode.link // p노드 -> s노드(=p.link) 였던것이 아래 문장과 같이하여
        prenode.link = newNode; // p노드 -> new노드 -> s노드가 됨
    }
    
    //리스트 마지막에 노드를 삽입하는 경우.
    public InsertNode(String data){
        ListNode newNode = new ListNode(data);
        if(head == null){
            this.head = newNode; //*??? head는 어디서 설정되는데? ??
        }else { // head is not null
            //temp노드를 루트(head)까지 설정하고 반복문을 통해서 가장 뒤에 있는 노드를 temp 노드가 참조하게 하
            //그 뒤 temp노드(리스트의 가장 마지막 노드) 에 삽입하려는 노드 를 이어줌
            ListNode tempNode =head;

            while(tempNode.link != null){
                tempNode = tempNode.link;
            }//반복문을 통해서 temp노드가 마지막 노드를 참조하도록하고
            tempNode.link = newNode;
        }
    }

    //delete
    //data로 노드를 삭제한다고 했을 때 중복된 데이터를 가진 여러개의 노드 삭제를 어떻게 수행할 것인가요?
    //노드의 삭제는 실제로 연결을 끊고 다음 부모/자식 노드에 다시 연결을 시켜준다.

    //Search
    //1.data로 검색
    public ListNode searchNode(String data){
        ListNode tempNode = this.head;
        while (tempNode != null){
            if (data.equals(tempNode.getData())){
                return tempNode;
            }else {
                tempNode = tempNode.link;
            }
        }
        return tempNode;
    }
    public void printList() {
        ListNode tempNode = this.head;    // tempNode에 head가 가리키는 첫번째 노드를 할당
        
        // tempNode가 null이 아닐 때까지 반복하여 출력
        while(tempNode != null) {
            System.out.print(tempNode.getData() + " ");
            tempNode = tempNode.link;    // temp 노드에 다음 노드(tempNode.link) 할당.
        }
        System.out.println();
    }


}