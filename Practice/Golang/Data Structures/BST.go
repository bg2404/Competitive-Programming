package main

import "fmt"

type node struct {
	key   int
	left  *node
	right *node
}

type tree struct {
	root *node
}

func (t *tree) insertKey(i int) {
	newNode := &node{key: i}
	if t.root == nil {
		t.root = newNode
	} else {
		cur := t.root
		for {
			if i < cur.key {
				if cur.left == nil {
					cur.left = newNode
					break
				} else {
					cur = cur.left
				}
			} else if i > cur.key {
				if cur.right == nil {
					cur.right = newNode
					break
				} else {
					cur = cur.right
				}
			} else {
				break
			}
		}
	}
}

func (t tree) searchKey(i int) {
	cur := t.root
	for {
		if cur == nil {
			fmt.Println("Not Found")
			break
		} else if i < cur.key {
			cur = cur.left
		} else if i > cur.key {
			cur = cur.right
		} else {
			fmt.Println("Found")
			break
		}
	}
}

func main() {
	t := tree{}
	fmt.Println(t)
	t.insertKey(5)
	t.insertKey(3)
	t.insertKey(7)
	t.insertKey(9)
	t.insertKey(0)
	t.searchKey(0)
	t.searchKey(1)
	t.searchKey(2)
	t.searchKey(3)
	t.searchKey(4)
	t.searchKey(5)
	t.searchKey(6)
	t.searchKey(7)
	t.searchKey(8)
	t.searchKey(9)
	t.searchKey(10)
}
