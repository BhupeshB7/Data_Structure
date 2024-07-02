package Tree;

import java.util.LinkedList;
import java.util.Queue;

public class BinaryTreeS {
   public static class Node{
        int data;
        Node left;
        Node right;

        Node(int data){
            this.data = data;
            this.left = this.right = null;
        }
    }
    static class BinaryTree {
        static int idx;

        public static Node buildTree(int nodes[]) {
            if (idx >= nodes.length || nodes[idx] == -1) return null;
            Node root = new Node(nodes[idx]);
            idx++;
            root.left = buildTree(nodes);
            idx++;
            root.right = buildTree(nodes);
            return root;
        }
    }
       public static void preorder(Node root){
           if(root==null)return;
           System.out.print(root.data+" ");
           preorder(root.left);
           preorder(root.right);
       }
       public static void inorder(Node root){
           if(root==null)return;
           inorder(root.left);
           System.out.print(root.data+" ");
           inorder(root.right);
       }
       public static void postorder(Node root){
           if(root==null)return;
           postorder(root.left);
           postorder(root.right);
           System.out.print(root.data+" ");
       }
       public static void levelOrder(Node root){
        if (root == null) return;

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        queue.add(null); // Add null as a marker for the end of the first level

        while (!queue.isEmpty()) {
            Node temp = queue.poll();

            if (temp != null) {
                System.out.print(temp.data + " ");
                if (temp.left != null) queue.add(temp.left);
                if (temp.right != null) queue.add(temp.right);
            } else {
                // End of current level
                System.out.print("\n");
                if (!queue.isEmpty()) {
                    queue.add(null); // Add marker for next level
                }
            }
        }
    }
    public static void main(String[] args) {
        int nodes [] ={1,2,4,8,-1,-1,9,-1,-1,5,10,-1,-1,11,-1,-1,3,6,-1,-1,7,-1,-1};
        // int nodes [] ={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        BinaryTree tree= new BinaryTree();
        Node root = tree.buildTree(nodes);
        System.out.println("Root data "+ root.data);
        System.out.print("Preorder traversal: ");
        preorder(root);
        System.out.println();
    
        System.out.print("Inorder traversal: ");
        inorder(root);
        System.out.println();
    
        System.out.print("Postorder traversal: ");
        postorder(root);
        System.out.println();
    
        System.out.print("Level Order traversal: ");
        System.out.println();
        levelOrder(root);
        System.out.println();
    }
}
