public class BinarySearchTree {
    // track the number of nodes in BST
    private int nodeCount = 0;

    // this BST is a rooted tree so we maintain a handle on the root node
    private Node root = null;

    // internal node containing node references
    // and the actual node data
    private class Node {
        int data;
        Node left, right;
        public Node(Node left, Node right, int elem) {
            this.data = elem;
            this.left = left;
            this.right = right;
        }
    }

    // check if the BST is empty
    public boolean isEmpty() {
        return size() == 0;
    }

    // get the number of nodes in the BST
    public int size() {
        return nodeCount;
    }

    // add an element to this binary tree.
    // returns true if we successfully perform insertion
    public boolean add(int elem) {
        if (contains(elem))
            return false;
        else {
            root = add(root, elem);
            nodeCount++;
            return true;
        }
    }

    // private method to recursively add a value in the binary tree
    private Node add(Node node, int elem) {
        if (node == null)
            node = new Node(null, null, elem);
        else {
            // place lower element values in the left subtree
            if (elem < node.data)
                node.left = add(node.left, elem);
            // place higher element values in the right subtree
            else
                node.right = add(node.right, elem);
        }
        return node;
    }

    // remove a value from this binary tree, it it exists
    public boolean remove(int elem) {
        // make sure the node you want to remove exists
        if (contains(elem)) {
            root = remove(root, elem);
            nodeCount--;
            return true;
        }
        return false;
    }

    private Node remove(Node node, int elem) {
        if (node == null) return null;

        int cmp = elem - node.data;

        // dig into the left subtree if the value
        // is smaller than the currnet value
        if (cmp < 0)
            node.left = remove(node.left, elem);
        // dig into the right subtree if the value
        // is larger than the current value
        else if (cmp > 0)
            node.right = remove(node.right, elem);
        // found the node we wish to remove
        else {
            // this is the case with only a right subtree or
            // no subtree at all. In this case we just swap
            // the node we wish to remove with its right child.
            if (node.left == null) {
                Node rightChild = node.right;

                node.data = 0;
                node = null;

                return rightChild;
            }
            // this is the case with only a left subtree or
            // no subtree at all. In this case we just swap
            // the node we wish to remove with its left child.
            else if (node.right == null) {
                Node leftChild = node.left;

                node.data = 0;
                node = null;

                return leftChild;
            }
            // when remove a node from a binary tree with two links the
            // successor of the node being removed can either be the largest
            // value in the left subtree or the smallest value in the right
            // subtree. In this implementation I have decided to find the
            // largest value in the left subtree which can be found by
            // traversing as far right as possible in the left subtree.
            else {
                // Find the rightmost node in the left subtree
                Node tmp = digRight(node.left);

                // swap the data
                node.data = tmp.data;

                // go into the left subtree and remove the rightmost node we
                // found and swapped data with. this prevents us from having
                // two nodes in our tree with same value.
                node.left = remove(node.left, tmp.data);

                // if instead we wanted to find the smallest node in the right
                // subtree as opposed to largest value in the left subtree
                // here is what we would do:
                // Node tmp = digLeft(node.right);
                // node.data = tmp.data;
                // node.right = remove(node.right, tmp.data);
            }
        }

        return node;
    }

    // helper method to find the leftmost node
    // private Node digLeft(Node node) {
    //     Node curr = node;
    //     while (curr.left != null)
    //         curr = curr.left;
    //     return curr;
    // }

    // helper method to find the rightmost node
    private Node digRight(Node node) {
        Node curr = node;
        while (curr.right != null)
            curr = curr.right;
        return curr;
    }

    // returns true if the element exists in the tree
    public boolean contains(int elem) {
        return contains(root, elem);
    }

    // private recursive method to find an element in the tree
    private boolean contains(Node node, int elem) {
        // base case: reached bottom, value not found
        if (node == null)
            return false;

        int cmp = elem - node.data;

        // dig into the left subtree because the value we're
        // looking for is smaller than the current value
        if (cmp < 0)
            return contains(node.left, elem);
        // dig into the right subtree because the value we're
        // looking for is larger than the current value
        else if (cmp > 0)
            return contains(node.right, elem);
        // we have found the value we are looking for
        else
            return true;
    }

    // computes the height of the tree, O(n)
    public int height() {
        return height(root);
    }

    // recursive helper method to compute the height of the tree
    private int height(Node node) {
        if (node == null) return 0;
        return 1 + Math.max( height(node.left), height(node.right) );
    }

    // inorder print method
    public void printInOrder() {
        printInOrder(root);
        System.out.println();
    }

    private void printInOrder(Node node) {
        if (node == null)
            return;

        printInOrder(node.left);
        System.out.print(node.data + " ");
        printInOrder(node.right);
    }

    // To BE ADDED...

    // this method returns an integer for a given TreeTraversalOrder.
    // the ways in which you can traverse the tree are in four different ways:
    // preorder, inorder, postorder and leverlorder.
    /*
    public java.util.Iterator<Integer> traverse(TreeTraverseOrder order) {
        switch (order) {
            case PRE_ORDER:
                return preorderTraversal();
            case IN_ORDER:
                return inorderTraversal();
            case POST_ORDER:
                return postorderTraversal();
            case LEVEL_ORDER:
                return levelorderTraversal();
            default:
                return null;
        }
    }

    private java.util.Iterator<Integer> preOrderTraversal() {
        // implementation
    }

    private java.util.Iterator<Integer> inOrderTraversal() {
        // implementation
    }

    private java.util.Iterator<Integer> postOrderTraversal() {
        // implementation
    }

    private java.util.Iterator<Integer> levelOrderTraversal() {
        // implementation
    }
    */
}