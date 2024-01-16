import java.util.Arrays;

public class MyArrayList<E> {
  E[] arr;
  int size;

  public MyArrayList() {
    this(3);
  }

  @SuppressWarnings("unchecked")
  public MyArrayList(int initCapacity) {
    arr = (E[]) new Object[initCapacity];
    size = 0;
  }

  public boolean add(E elm) {
    if (arr.length == size) {
      expand();
    }
    arr[size++] = elm;
    return true;
  }

  public boolean contains(E elm) {
    for (int i = 0; i < size; i++) {
      if (elm.equals(arr[i]))
        return true;
    }
    return false;
  }

  private void expand() {
    arr = Arrays.copyOf(arr, arr.length * 2);
  }
  
  private int indexOf(E elm){
    for(int i = 0; i < size; i++){
      if(elm.equals(arr[i])){
        return i;
      }
    }
    return -1;
  }

  private E remove(E elm){
    
  int len = arr.indexOf(elm);
  if(len == -1){
  return;
  } else{
    int[] myArr = arr;
    int[] newArr = new int[size-1];
    for(int i = 0; i < len; i++){
      newArr[i] = arr[i];
    }
    for(int i = len; i < size-1; i++){
      newArr[i] = arr[i+1];
        }
    arr = newArr;
    size--;
      }  
    return elm;
    }

  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append('[');
    if (size != 0) {
      sb.append(arr[0]);
    }
    for (int i = 1; i < size; i++) {
      sb.append(',');
      sb.append(arr[i]);
    }
    sb.append(']');
    return new String(sb);
  }

  public static void main(String[] args) {
    MyArrayList<String> arr = new MyArrayList<>(3);

    arr.add("test");
    System.out.println(arr.toString());
  }
}
