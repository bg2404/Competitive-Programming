// Prepend data to linked list and delete a value from linked list
package main

import (
	"fmt"
)

type node struct {
	data int
	next *node
}

type linkedList struct {
	head *node
}

func (l *linkedList) prepend(i int) {
	newNode := &node{data: i}
	if l == nil || l.head == nil {
		l.head = newNode
	} else {
		newNode.next = l.head
		l.head = newNode
	}
}

func (l *linkedList) deleteByValue(i int) {
	if l != nil && l.head != nil {
		if l.head.data == i {
			l.head = l.head.next
		} else {
			prev := l.head
			for prev.next != nil {
				if prev.next.data == i {
					break
				}
				prev = prev.next
			}
			if prev.next != nil {
				prev.next = prev.next.next
			}
		}
	}
}

func (l linkedList) printList() {
	for l.head != nil {
		fmt.Printf("%v ", l.head.data)
		l.head = l.head.next
	}
	fmt.Printf("\n")
}

func main() {
	myList := linkedList{}
	myList.prepend(0)
	myList.prepend(1)
	myList.prepend(2)
	myList.prepend(3)
	myList.prepend(4)
	myList.printList()
	myList.deleteByValue(2)
	myList.printList()
	myList.deleteByValue(0)
	myList.printList()
	myList.deleteByValue(4)
	myList.printList()
	myList.deleteByValue(1)
	myList.printList()
	myList.deleteByValue(3)
	myList.printList()
}
