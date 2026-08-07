public class Main {
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();

        // initially empty
        System.out.println("Is Empty: " + bst.isEmpty());
        System.out.println("Size: " + bst.size());

        // insert elements
        bst.add(8);
        bst.add(3);
        bst.add(10);
        bst.add(1);
        bst.add(6);
        bst.add(14);
        bst.add(4);
        bst.add(7);
        bst.add(13);

        System.out.println("\nAfter insertion:");
        System.out.println("Size: " + bst.size());
        System.out.println("Height: " + bst.height());
        System.out.print("Inorder: ");
        bst.printInOrder();

        // search
        System.out.println("\nContains 6: " + bst.contains(6));
        System.out.println("Contains 20: " + bst.contains(20));

        // duplicate insertion
        System.out.println("\nInsert duplicate 6: " + bst.add(6));

        // remove
        System.out.println("\nRemove 1: " + bst.remove(1));
        System.out.println("Contains 1: " + bst.remove(1));

        System.out.println("\nRemove 10: " + bst.remove(10));
        System.out.println("Contains 10: " + bst.remove(10));

        System.out.println("\nRemove 8 (root): " + bst.remove(8));
        System.out.println("Contains 8: " + bst.remove(8));

        System.out.println("\nFinal Size: " + bst.size());
        System.out.println("Final Height: " + bst.height());
        System.out.print("Inorder: ");
        bst.printInOrder();
    }
}
