package main

import (
	"errors"
	"fmt"
)

type queue struct {
	items []int
}

func (q *queue) enqueue(i int) {
	q.items = append(q.items, i)
}

func (q queue) front() (int, error) {
	if len(q.items) == 0 {
		return 0, errors.New("Empty Queue")
	}
	return q.items[0], nil
}

func (q *queue) dequeue() error {
	if len(q.items) == 0 {
		return errors.New("Empty Queue")
	}
	q.items = q.items[1:]
	return nil
}

func main() {
	myQueue := queue{}
	fmt.Println(myQueue)
	myQueue.enqueue(100)
	myQueue.enqueue(200)
	myQueue.enqueue(300)
	fmt.Println(myQueue)
	fmt.Println(myQueue.front())
	myQueue.dequeue()
	fmt.Println(myQueue)
	fmt.Println(myQueue.front())
}