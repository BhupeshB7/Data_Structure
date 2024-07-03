class BinaryTree {
    constructor() {
        this.idx = 0;
    }

    static Node = class {
        constructor(data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    buildTree(nodes) {
        if (this.idx >= nodes.length || nodes[this.idx] === -1) return null;
        let root = new BinaryTree.Node(nodes[this.idx]);
        this.idx++;
        root.left = this.buildTree(nodes);
        this.idx++;
        root.right = this.buildTree(nodes);
        return root;
    }

    static preorder(root) {
        if (root === null) return;
        process.stdout.write(root.data + " ");
        BinaryTree.preorder(root.left);
        BinaryTree.preorder(root.right);
    }

    static inorder(root) {
        if (root === null) return;
        BinaryTree.inorder(root.left);
        process.stdout.write(root.data + " ");
        BinaryTree.inorder(root.right);
    }

    static postorder(root) {
        if (root === null) return;
        BinaryTree.postorder(root.left);
        BinaryTree.postorder(root.right);
        process.stdout.write(root.data + " ");
    }

    static levelOrder(root) {
        if (root === null) return;

        let queue = [];
        queue.push(root);
        queue.push(null); // Add null as a marker for the end of the first level

        while (queue.length > 0) {
            let temp = queue.shift();

            if (temp !== null) {
                process.stdout.write(temp.data + " ");
                if (temp.left !== null) queue.push(temp.left);
                if (temp.right !== null) queue.push(temp.right);
            } else {
                // End of current level
                console.log();
                if (queue.length > 0) {
                    queue.push(null); // Add marker for next level
                }
            }
        }
    }
}

// Example usage:
const nodes = [1, 2, 4, 8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1, 3, 6, -1, -1, 7, -1, -1];
const tree = new BinaryTree();
const root = tree.buildTree(nodes);

console.log("Root data " + root.data);

console.log("Preorder traversal: ");
BinaryTree.preorder(root);
console.log();

console.log("Inorder traversal: ");
BinaryTree.inorder(root);
console.log();

console.log("Postorder traversal: ");
BinaryTree.postorder(root);
console.log();

console.log("Level Order traversal: ");
BinaryTree.levelOrder(root);
console.log();
