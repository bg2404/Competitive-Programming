/*****************************************************************************************************
*    Computational number theory.                                                                    *
*    Write a program that prints out all integers of the form a^3 + b^3 where a and b are integers   *
*    between 0 and n in sorted order, without using excessive space. That is, instead of computing   *
*    an array of the n^2 sums and sorting them, build a minimum-oriented priority queue, initially    *
*    containing (0^3, 0, 0), (1^3, 1, 0), (2^3, 2, 0), ..., (n^3, n, 0). Then, while the priority    *
*    queue is nonempty, remove the smallest item (i^3 + j^3, i, j), print it, and then, if j < n,    *
*    insert the item (i^3 + (j+1)^3, i, j+1).                                                        *
*    Use this program to find all distinct integers a, b, c, and d between 0 and 10^6 such that      *
*    a^3 + b^3 = c^3 + d^3, e.g., 1729 = 9^3 + 10^3 = 1^3 + 12^3.                                    *
******************************************************************************************************/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long Function(long long, long long);

long long lhsFunc(long long a, long long b) {
    return a + 2 * b * b;
}

long long rhsFunc(long long c, long long d) {
    return 3 * c * c * c + 4 * d * d * d * d;
}

struct Node {
    long long sum;
    long long i;
    long long j;

    Node(long long i, long long j, Function func) : sum(func(i, j)), i(i), j(j) {}

    string toString() {
        return to_string(sum) + " = " + to_string(i) + "^3 + " + to_string(j) + "^3";
    }

    inline bool operator>(const Node &o) const {
        return sum > o.sum;
    }
};

void remove_and_add(priority_queue<Node, vector<Node>, greater<Node>> &pq, Function func, int n) {
    Node node = pq.top();
    pq.pop();
    if (node.j < n) {
        pq.emplace(Node(node.i, node.j + 1, func));
    }
}

int main() {
    int n = 1000;

    priority_queue<Node, vector<Node>, greater<Node>> lhs, rhs;
    for (int i = 0; i <= n; ++i) {
        lhs.emplace(Node(i, 0, lhsFunc));
        rhs.emplace(Node(i, 0, rhsFunc));
    }

    long long num_solutions = 0;

    while (!lhs.empty()) {
        Node l = lhs.top();
        Node r = rhs.top();
        if (l.sum < r.sum) {
            remove_and_add(lhs, lhsFunc, n);
        } else if (r.sum < l.sum) {
            remove_and_add(rhs, rhsFunc, n);
        } else {
            long long lcnt = 0, rcnt = 0;
            while (!lhs.empty() && lhs.top().sum == l.sum) {
                ++lcnt;
                remove_and_add(lhs, lhsFunc, n);
            }
            while (!rhs.empty() && rhs.top().sum == r.sum) {
                ++rcnt;
                remove_and_add(rhs, rhsFunc, n);
            }
            num_solutions += lcnt * rcnt;
        }
    }
    cout << num_solutions << endl;
    return 0;
}