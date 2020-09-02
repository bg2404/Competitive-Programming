package main

import (
	"errors"
	"fmt"
)

type stack struct {
	items []int
}

func (s *stack) push(i int) {
	s.items = append(s.items, i)
}

func (s stack) top() (int, error) {
	if len(s.items) == 0 {
		return 0, errors.New("Empty Stack")
	}
	return s.items[len(s.items)-1], nil
}

func (s *stack) pop() error {
	if len(s.items) == 0 {
		return errors.New("Empty Stack")
	}
	s.items = s.items[:len(s.items)-1]
	return nil
}

func main() {
	myStack := stack{}
	fmt.Println(myStack)
	myStack.push(100)
	myStack.push(200)
	myStack.push(300)
	fmt.Println(myStack)
	fmt.Println(myStack.top())
	myStack.pop()
	fmt.Println(myStack)
	fmt.Println(myStack.top())

}
