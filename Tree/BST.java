// class BST{
//     static class Node{
//         int data;
//         Node left;
//         Node right;
//         Node(int data){
//             this.data =data;
//             this.left = null;
//             this.right = null;
//         }
//     }
//     public static Node insert(Node root,int val){
//         if(root == null){
//             root = new Node(val);
//             return root;
//         }
//         if(root.data> val){
//             root.left = insert(root.left,val);
//         }
//         else{
//             root.left = insert(root.right,val);
//         }
//         return root;
//     }
//     public static void inOrder(Node root){
//         if(root==null)return;
//         inOrder(root.left);
//         System.out.println(root.data +" ");
//         inOrder(root.right);
//     }
//     public static void main(String args []){
//        int values[]= {5,1,3,4,2,7};
//        Node root = null;
//        for(int i =0;i<values.length;i++){
//         root = insert(root,values[i]);
//        }
//        inOrder(root);
       
//     }
// }

/**
 * BST
 */
 class BST {
        static class Node {
            int data;
            Node left;
            Node right;
            Node(int data) {
                this.data = data;
                this.left = null;
                this.right = null;
            }
        }
        
        // insert a node into the tree
        public static Node insert(Node root, int val) {
            if (root == null) {
                root = new Node(val);
                return root;
            }
            if (root.data > val) {
                root.left = insert(root.left, val);
            } else {
                root.right = insert(root.right, val);
            }
            return root;
        }
        
        // print the tree
        public static void inOrder(Node root) {
            if (root == null)
                return;
            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }
   public static void main(String[] args) {
    int values[] = { 5, 1, 3, 4, 2, 7 };
    Node root = null;
    for (int i = 0; i < values.length; i++) {
      root = insert(root, values[i]);
    }
    inOrder(root);
  }}