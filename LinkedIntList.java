// Int Node
class ListNode {
    int value;
    ListNode next;
}

// A LinkedIntList stores a list of integers
public class LinkedIntList {
    private ListNode front;       // The front node of the linked list

    public LinkedIntList(int ...a) {
        // Constructor of LinkedIntList class with avriable number of integer arguements
        front = null;
        for (int i:a) {
            // Inserting int arguments in the linked list one by one 
            ListNode newnode = new ListNode();    // Creating new list node
            newnode.value = i;
            newnode.next = null;
            if(front == null) {
                // if list contains no node
                front = newnode;
            }
            else {
                ListNode cur = front;
                while(cur.next != null) {
                    // finding the position for the insertion of the new node
                    cur = cur.next;
                }
                cur.next = newnode;
            }
        }

    }

    @Override
    public String toString() {
        // Overrides toString method for LinkedIntList object
        String output = "";
        ListNode cur = front;
        while (cur != null) {
            output = output.concat(" " + String.valueOf(cur.value));
            cur = cur.next;
        }
      return output;
    }

    public void doubleUp() {
        // This function doubles up the size of the linked list by inserting a copy of each node
        if(front == null) {
            // if list is empty
            System.out.println("The list is empty!");
            return;
        }
        ListNode cur = front;
        while(cur != null) {
            // Creating a duplicate node
            ListNode newnode = new ListNode();
            newnode.value = cur.value;
            newnode.next = cur.next;
            // inserting node after current node
            cur.next = newnode;
            cur = newnode.next;
        }

        
    }

    public void MyFun() {
        ListNode h = front;
        while(h != null) {
            System.out.print(h.value + "->");
            h = h.next.next;
        }
    }

    public static void main(String[] args) {
        LinkedIntList list = new LinkedIntList(2, 1, 3, 9, 5, 3, 7, 4);
        //list.doubleUp();
        System.out.println();
        list.MyFun();
        LinkedIntList list2 = new LinkedIntList(1, 2, 3, 4, 5, 6, 7);
        System.out.println();
        list2.MyFun();
    }
}