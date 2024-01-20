package main

import "fmt"

type Node[T any] struct {
	next  *Node[T]
	value T
}

type List[T any] struct {
	tail *Node[T]
	head *Node[T]
	size int
}

func New[T any]() *List[T] {
	return &List[T]{}
}

func (l *List[T]) AddFirst(value T) {
	newNode := Node[T]{value: value}

	newNode.next = l.head
	l.head = &newNode
	l.size++
}

func (l *List[T]) Add(value T) {
	newNode := Node[T]{value: value}

	if l.size == 0 {
		l.tail = &newNode
		l.head = &newNode
		l.size++
		return
	}

	l.tail.next = &newNode
	l.tail = &newNode
	l.size++
}

func (l *List[T]) Insert(value T, index int) {
	if index > l.size {
    panic("Out of bound")
	}

	newNode := Node[T]{value: value}
	if index == 0 {
		l.AddFirst(value)
		return
	}
	if l.size == index {
		l.Add(value)
		return
	}

	current := l.head
	for i := 0; i < index; i++ {
		current = current.next
	}
	newNode.next = current.next
	current.next = &newNode
	l.size++
}

func (l List[T]) RemoveIndex(index int) {
	if index > l.size || index < 0 {
		fmt.Print("Remove index error")
		return
	}

	if index == 0 {
		l.head = l.head.next
		return
	}

	current := l.head
	for i := 0; i < index-1; i++ {
		current = current.next
	}
	current.next = current.next.next
	l.size--
}

func (l List[T]) toString() string {
	myString := ""
	current := l.head

	if current != nil {
		myString = myString + convertToString(current.value)
		current = current.next
	}

	for current != nil {
		myString = myString + " -> "
		myString = myString + convertToString(current.value)
		current = current.next
	}

	return myString
}

func convertToString(value interface{}) string {
	return fmt.Sprintf("%v", value)
}

func main() {
	myLL := New[int]()
	myLL.Add(2)
	myLL.Add(3)
	myLL.Add(5)
	myLL.AddFirst(1)
	myLL.Insert(4, 7)
	myLL.RemoveIndex(3)
	fmt.Printf(myLL.toString())
}
