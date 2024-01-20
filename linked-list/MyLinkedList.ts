class MyNode<T> {
  public value: T;
  public next: MyNode<T> | null;

  constructor(value: T, next: MyNode<T> | null = null) {
    this.value = value;
    this.next = next;
  }
}

class MyLinkedList<T> {
  public head: MyNode<T> | null = null;
  public tail: MyNode<T> | null = null;
  public size: number = 0;

  public addFirst(value: T): void {
    this.head = new MyNode<T>(value, this.head);
    this.size++;

    if (this.size === 1) {
      this.tail = this.head;
    }
  }

  public add(value: T): void {
    if (this.tail === null) {
      this.head = this.tail = new MyNode<T>(value);
    } else {
      const newMyNode = new MyNode<T>(value);
      this.tail.next = newMyNode;
      this.tail = newMyNode;
    }
    this.size++;
  }

  public addAtIndex(value: T, index: number): void {
    if (index < 0 || index > this.size) {
      throw new Error(`Index out of bounds: ${index}`);
    }

    if (this.size === index) {
      this.add(value);
    } else if (index === 0) {
      this.addFirst(value);
    } else {
      let current: MyNode<T> | null = this.head;
      while (index !== 1 && current !== null) {
        current = current.next;
        index--;
      }
      if (current !== null) {
        const temp = new MyNode<T>(value, current.next);
        current.next = temp;
        this.size++;
      }
    }
  }

  public removeAtIndex(index: number): void {
    if (this.size === index) {
      throw new Error(`Index out of bounds: ${index}`);
    } else if (index === 0 && this.head !== null) {
      this.head = this.head.next;
    } else {
      let current: MyNode<T> | null = this.head;

      while (index !== 1 && current !== null) {
        current = current.next;
        index--;
      }

      if (current !== null && current.next !== null) {
        current.next = current.next.next;
        this.size--;
      }
    }
  }

  public contains(value: T): boolean {
    let current: MyNode<T> | null = this.head;

    while (current !== null) {
      if (current.value === value) {
        return true;
      }
      current = current.next;
    }

    return false;
  }

  public toString(): string {
    let sb: string = "";
    let current: MyNode<T> | null = this.head;

    if (current !== null) {
      sb += this.convertToString(current.value);
      current = current.next;
    }

    while (current !== null) {
      sb += ` -> ${this.convertToString(current.value)}`;
      current = current.next;
    }

    return sb;
  }

  public convertToString<T>(value: T): string {
    if (typeof value === "string") {
      return value;
    } else if (typeof value === "number") {
      return value.toString();
    } else {
      throw new Error("Cannot convert this type to string");
    }
  }
}

(() => {
  const test = new MyLinkedList<number>();
  test.add(2);
  test.add(3);
  test.add(5);
  test.addFirst(1);
  test.addAtIndex(4, 3);

  console.log(test.contains(4));
  console.log(test.toString());
  console.log("size", test.size);
  test.removeAtIndex(2);
  console.log(test.toString());
  console.log("size", test.size);
})();
