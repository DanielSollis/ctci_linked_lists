#pragma once

#include <string>
#include <vector>


struct Node {
	int value;
	Node * next;
};


class Singly_Linked_List {
private:
	Node * tail = nullptr;
	bool is_circular = false;
	int size = 0;

	//helpers
	void delete_linear_list();
	void delete_circular_list();
	void print_linear_list();
	void print_circular_list();
	void remove_first_in_list(Node * temp);
	void delete_last_element(Node *& it);
	void delete_middle_node(Node * mid);
	Node * Singly_Linked_List::kth_to_last_helper(int k, Node *& temp, int & counter);
	void Singly_Linked_List::partition_insert(Node * temp);
	void Singly_Linked_List::partition_delete(Node * temp);
	int Singly_Linked_List::get_int_rep();
	std::vector<int> get_list_vector(Singly_Linked_List list);
	bool Singly_Linked_List::palindrome_recurse_helper(Node *& head, Node * temp);

public:
	//List Functions
	Node * head = nullptr;
	Singly_Linked_List();
	Singly_Linked_List(Singly_Linked_List & list);
	~Singly_Linked_List();
	Singly_Linked_List & operator= (Singly_Linked_List list);
	friend std::ostream & operator<<(std::ostream & os, Singly_Linked_List & list);
	void push_front(int value);
	void push_back(int value);
	int pop_front();
	void remove(int value);
	void print_list();
	int get_size();
	int make_list_circular();

	//Questions
	void remove_dups();
	void remove_dups_nobuff();
	friend Singly_Linked_List sum_lists(Singly_Linked_List one, Singly_Linked_List two); //in main
	Node * kth_to_last(int k);								//to debug
	Node kth_to_last(int k, int size);
	void partition(int x);
	bool palindrome(Singly_Linked_List list);				
	bool palindrome_recurse(Singly_Linked_List list);
	Node * loop_detection(); //to test
};