

/*
트리는 *연결리스트 개념입니다.

노드
ㅁㅁㅁㅁ
left/data/p/right
로 4개의 배열? 로이루어지고
left rigth 각각엔 pointer변수로 주소값을 받습니다

 */
//이진트리의 순회
/*
이진트리의 순회 
1 . inorder 중순회
2 , preorder 선순회
3 . postorder 후순회
4 . levelorder 레벨순회


inorder // 트리 중 가장 작은 노드부터 순회하는 방식(T_left -> root -> T_right)
1 . Tree-Left를 inorder  (가장 왼쪽아래 노드순회)
2 . (subtree의, 혹은 tree의) root순회
3 . Tree_Right를 inorder ()

//sudo
Inorder_Tree_Walk(x) //x는 노드
1. if x != Null
2.  then Inorder_Tree_Walk(left[x])
3.      print key[x]
4.      Inorder_Tree_Walk(right[x])


preorder
1. root순회
2. Tree_left 로 내려가서 preorder
3. Tree_right 로 내가서 preorder

//sudo
Preorder_Tree_Walk(x)
1. if x!= Null;
2.  then print key[x]
3.      Preorder_Tree_Walk(left[x])
4.      Preorder_Tree_Walk(right[x])



postorder
1. Tree_Left를 post order
2. Tree_Right를 post order
3. Root 순회

//sudo
1. if x!= Null;
2.  then Postorder_Tree_Walk(left[x])
3.      Postorder_Tree_Walk(right[x])
4.      print key[x]
*/ 


class MyTree{




}