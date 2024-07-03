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

    public static Node insert(Node root, int val) {
        if (root == null) {
            root = new Node(val);
            return root;
        }
        if (val < root.data) {
            root.left = insert(root.left, val);
        } else {
            root.right = insert(root.right, val);
        }
        return root;
    }

    public static void inOrder(Node root) {
        if (root == null) return;
        inOrder(root.left);
        System.out.print(root.data + " ");
        inOrder(root.right);
    }
    public static boolean search(Node root, int key){
        if(root == null)return false;
        if(root.data> key){
            return search(root.left,key);
        }else if(root.data==key){
            return true;
        }
        else{
            return search(root.right,key);
        }
    }
    public static void main(String[] args) {
        int values[] = {5, 1, 3, 4, 2, 7};
        Node root = null;
        for (int i = 0; i < values.length; i++) {
            root = insert(root, values[i]);
        }
            System.out.println("---------------");
        inOrder(root);
            System.out.println("");
            System.out.println("---------------");
        if(search(root,27)){
            System.out.println("Element Found");
        }else{
        System.out.println("Element Not Found");
        }
    }
}
 