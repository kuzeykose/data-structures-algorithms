class MyArrayList<E> {
  private arr: E[];
  private size: number;

  constructor(initCapacity: number = 3) {
    this.arr = new Array(initCapacity);
    this.size = 0;
  }

  add(elm: E): boolean {
    if (this.arr.length === this.size) {
      this.expand();
    }
    this.arr[this.size++] = elm;
    return true;
  }

  contains(elm: E): boolean {
    for (let i = 0; i < this.size; i++) {
      if (elm === this.arr[i]) {
        return true;
      }
    }
    return false;
  }

  private expand(): void {
    this.arr = [...this.arr, ...new Array(this.arr.length)];
  }

  toString(): string {
    if (this.size === 0) {
      return '[]';
    }

    let result = '[' + this.arr[0];
    for (let i = 1; i < this.size; i++) {
      result += ',' + this.arr[i];
    }
    result += ']';
    return result;
  }
}

function main() {
  const list = new MyArrayList<number>();
  list.add(1);
  list.add(2);
  list.add(3);
  console.log(list.toString());
  console.log(list.contains(2));
}

main()
