public class MyLinkedList<T> {
  public Node<T> head;
  public Node<T> tail;
  public int size;

  public void addFirst(T value) {
    head = new Node<T>(value, head);
    size++;

    if (size == 1) {
      tail = head;
    }
  }

  public void add(T value) {
    if (tail == null) {
      head = tail = new Node<T>(value);
    } else {
      Node<T> newNode = new Node<T>(value);
      tail.next = newNode;
      tail = newNode;
    }
    size++;
  }

  public void add(T value, int index) {
    if (index < 0 || index > size) {
      throw new IndexOutOfBoundsException(index);
    }

    if (size == index) {
      add(value);
    } else if (index == 0) {
      addFirst(value);
    } else {
      Node<T> current = head;
      while (index != 1) {
        current = current.next;
        index--;
      }
      Node<T> temp = new Node<>(value, current.next);
      current.next = temp;
      size++;
    }
  }

  public void removeIndex(int index) {
    if (size == index) {
      throw new IndexOutOfBoundsException(index);
    } else if (index == 0) {
      head = head.next;
    } else {
      Node<T> current = head;

      while (index != 1) {
        current = current.next;
        index--;
      }

      current.next = current.next.next;
    }
    size--;
  }

  public boolean contains(T value) {
    Node<T> current = head;

    while (current != null) {
      if (current.value == value)
        return true;
      current = current.next;
    }

    return false;
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    Node<T> current = head;

    if (current != null) {
      sb.append(current.value.toString());
      current = current.next;
    }

    while (current != null) {
      sb.append(" -> ");
      sb.append(current.value.toString());
      current = current.next;
    }

    return sb.toString();
  }

  public static void main(String[] args) {
    MyLinkedList<Integer> test = new MyLinkedList<Integer>();
    test.add(2);
    test.add(3);
    test.add(5);
    test.addFirst(1);
    test.add(4, 3);

    System.out.println(test.contains(4));
    System.out.println(test.toString());
    System.out.println("size" + " " + test.size);
    test.removeIndex(2);
    System.out.println(test.toString());
    System.out.println("size" + " " + test.size);
  }
}

class Node<T> {
  public T value;
  public Node<T> next;

  public Node(T value, Node<T> next) {
    this.value = value;
    this.next = next;
  }

  public Node(T value) {
    this.value = value;
    this.next = null;
  }
}
