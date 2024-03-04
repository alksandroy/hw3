#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------


Node * makeList(std::vector<int> const & content)
{
	Node * head = nullptr;
	Node * tail = nullptr;

	for(auto v : content)
	{
		if(head == nullptr) {
			head = new Node(v,nullptr);
			tail = head;
		}
		else {
			tail->next = new Node(v,nullptr);
			tail = tail->next;
		}

	}
	return head;
}

struct IsOdd
{
    bool operator()(int num) {
        return (num % 2) != 0;
    }
};

int main(int argc, char* argv[])
{
    // if(argc < 2) {
    //     cout << "Please provide an input file" << endl;
    //     return 1;
    // }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* list = makeList({2});

	list = llfilter(list, IsOdd());
    print(list);
    // Node* head = readList(argv[1]);
    // cout << "Original list: ";
    // print(head);

    // Test out your linked list code

    // auto f = [](int a) -> bool 
    // {
    //     return a;
    // };
    // head = llfilter(head, f);
    // // cout << "TOIDAY\n";
    // // cout << head->val;
    // print(head);
    // Node* small;
    // Node* big;
    // llpivot(head, small, big, 10);
    // print(small);
    // print(big);
    // return 0;

}
