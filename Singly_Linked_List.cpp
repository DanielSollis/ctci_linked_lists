#include "Singly_Linked_List.h";
#include <unordered_set>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;


#pragma region LIST FUNCTIONS


#pragma region CONSTRUCTORS/DESTRUCTOR


Singly_Linked_List::Singly_Linked_List() {}


Singly_Linked_List::Singly_Linked_List(Singly_Linked_List & list) {
	Node * runner = list.head;
	while (runner != nullptr) {
		this->push_back(runner->value);
		runner = runner->next;
	}
}


Singly_Linked_List::~Singly_Linked_List() {
	if (!is_circular) {
		delete_linear_list();
	}
	else {
		delete_circular_list();
	}
}


void Singly_Linked_List::delete_linear_list() {
	Node * temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
	}
}


void Singly_Linked_List::delete_circular_list() {
	Node * temp = head;
	while (size > 0) {
		head = head->next;
		delete temp;
		size--;
		temp = head;
	}
}


#pragma endregion
#pragma region OPERATOR OVERLOADS


Singly_Linked_List & Singly_Linked_List::operator=(Singly_Linked_List list) {
	Singly_Linked_List new_list;
	bool end_of_list = false;
	while (!end_of_list) {
		int value = list.pop_front();
		if (value != -1) {
			new_list.push_back(value);
		}
		else {
			end_of_list = true;
		}
	}
	return new_list;
}


std::ostream & operator<<(std::ostream & os, Singly_Linked_List & list) {
	Singly_Linked_List * temp = &list;
	Node * it = temp->head;
	std::string printer = "";
	while (it != nullptr) {
		os << it->value;
		if (it->next != nullptr) {
			os << " ";
		}
		else {
			os << "\n";
		}
		it = it->next;
	}
	return os;
}


#pragma endregion
#pragma region PUSH FRONT


void Singly_Linked_List::push_front(int value) {
	if (!is_circular) {
		Node * temp = new Node;
		temp->next = head;
		temp->value = value;

		if (head == nullptr) {
			tail = temp;
		}
		head = temp;
		size++;
	}
	else {
		cout << "\nList is circular\n";
	}
}


#pragma endregion
#pragma region PUSH BACK


void Singly_Linked_List::push_back(int value) {
	if (!is_circular) {
		Node * temp = new Node;
		temp->next = nullptr;
		temp->value = value;
		if (tail != nullptr) {
			tail->next = temp;
		}
		if (head == nullptr) {
			head = temp;
		}
		tail = temp;
		size++;
	}
	else {
		cout << "\nList is circular\n";
	}
}


#pragma endregion
#pragma region POP FRONT


int Singly_Linked_List::pop_front() {
	if (!is_circular) {
		if (head != nullptr) {
			int value = head->value;
			head = head->next;
			size--;
			return value;
		}
		else {
			size--;
			return -1;
		}
	}
	else {
		cout << "\nList is circular\n";
	}
}


#pragma endregion
#pragma region REMOVE


void Singly_Linked_List::remove(int value) {
	if (!is_circular) {
		Node * prev = head;
		Node * temp = head;
		while (temp != nullptr && temp->value != value) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == nullptr) {
			printf("value not found in list\n");
		}
		else if (temp == head) {
			remove_first_in_list(temp);
		}
		else if (temp->next == nullptr) {
			prev->next = nullptr;
			tail = prev;
			delete temp;
		}
		else {
			prev->next = temp->next;
			delete temp;
		}
		size--;
	}
	else {
		cout << "\nList is circular\n";
	}
}


void Singly_Linked_List::remove_first_in_list(Node * temp) {
	if (temp->next == nullptr) {
		head = nullptr;
	}
	else {
		if (tail == head) {
			tail = head->next;
		}
		head = head->next;
		delete temp;
	}
	size--;

}


#pragma endregion
#pragma region PRINT LIST


void Singly_Linked_List::print_list() {
	if (!is_circular) {
		Node * temp = head;
		while (temp != nullptr) {
			printf("%d ", temp->value);
			temp = temp->next;
		}
		printf("\n\n");
	}
	else {
		Node * temp = head;
		int printed = 0;
		while (printed != size) {
			printf("%d ", temp->value);
			temp = temp->next;
			printed++;
		}
	}
}


void Singly_Linked_List::print_linear_list() {

}


void Singly_Linked_List::print_circular_list() {

}


#pragma endregion
#pragma region GET SIZE


int Singly_Linked_List::get_size() {
	if (head == nullptr) {
		return 0;
	}
	int size = 1;
	Node * temp = head;
	while (temp != nullptr) {
		temp = temp->next;
		size++;
	}
	return size;
}


#pragma endregion
#pragma region MAKE LIST CIRCULAR


int Singly_Linked_List::make_list_circular() {
	int list_point = rand() % size;
	int result_point = list_point;
	Node * temp = head;
	while (list_point != 0) {
		temp = temp->next;
		list_point--;
	}
	tail->next = temp;
	is_circular = true;
	return result_point;
}


#pragma endregion

#pragma endregion
#pragma region QUESTIONS


#pragma region REMOVE DUPS


void Singly_Linked_List::remove_dups() {
	unordered_set<int> dupe_set;
	Node * it = head;
	while (it != nullptr) {
		if (dupe_set.find(it->value) != dupe_set.end()) {
			if (it == tail) {
				delete_last_element(it);
			}
			else {
				delete_middle_node(it);
			}
		}
		else {
			if (it != nullptr) {
				dupe_set.insert(it->value);
			}
			it = it->next;
		}
	}
}


void Singly_Linked_List::delete_last_element(Node *& it) {
	Node * prev = head;
	while (prev->next != tail) {
		prev = prev->next;
	}
	prev->next = nullptr;
	delete tail;
	tail = prev;
	it = nullptr;
}


void Singly_Linked_List::remove_dups_nobuff() {
	Node * temp = head;
	while (temp != nullptr) {
		Node * runner = temp->next;
		while (runner != nullptr) {
			if (runner->value == temp->value) {
				if (runner == tail) {
					delete_last_element(runner);
				}
				else {
					delete_middle_node(runner);
				}
			}
			else {
				runner = runner->next;
			}
		}
		temp = temp->next;
	}
}


#pragma endregion
#pragma region KTH TO LAST


Node * Singly_Linked_List::kth_to_last(int k) {
	int counter = 0;
	Node * temp = head;
	Node * kth_node = kth_to_last_helper(k, temp, counter);
	return kth_node;
}


Node * Singly_Linked_List::kth_to_last_helper(int k, Node *& temp, int & counter) {
	Node * old_temp = temp;
	if (temp != nullptr) {
		temp = kth_to_last_helper(k, temp->next, counter);
		if (counter < k) {
			++counter;
		}
	}
	if (counter < k && temp == nullptr && old_temp != nullptr) {
		return old_temp;
	}
	else if (k == counter && temp != nullptr) {
		return temp;
	}
	else {
		return nullptr;
	}
}


Node Singly_Linked_List::kth_to_last(int k, int size) {
	Node * temp = head;
	int counter = 0;
	while (temp != nullptr && counter != k) {
		temp = temp->next;
		++counter;
	}
	return *temp;
}


#pragma endregion
#pragma region DELETE MIDDLE NODE


void Singly_Linked_List::delete_middle_node(Node * mid) {
	if (mid == tail) {
		printf("Pointer at end of list, cannot delete\n");
	}
	else {
		Node * to_copy = mid->next;
		mid->value = to_copy->value;
		mid->next = to_copy->next;
		if (to_copy == tail) {
			tail = mid;
		}
		delete to_copy;
	}
}


#pragma endregion
#pragma region PARTITION


void Singly_Linked_List::partition(int x) {
	if (head == nullptr) {
		cout << "List was Empty";
	}
	else {
		Node * temp = head;
		Node * list_end = tail;
		bool at_list_end = false;
		while (!at_list_end) {
			if (temp->value >= x) {
				if (temp->next == list_end) {
					at_list_end = true;
				}
				partition_insert(temp);
				partition_delete(temp);
			}
			else {
				temp = temp->next;
			}
			if (temp == list_end) {
				at_list_end = true;
			}
		}
	}
}


void Singly_Linked_List::partition_insert(Node * temp) {
	Node * new_node = new Node;
	new_node->value = temp->value;
	tail->next = new_node;
	new_node->next = nullptr;
	tail = new_node;
}


void Singly_Linked_List::partition_delete(Node * temp) {
	Node * to_delete = temp->next;
	temp->value = temp->next->value;
	temp->next = temp->next->next;
	delete to_delete;
}


int Singly_Linked_List::get_int_rep() {
	Node * temp = head;
	string result_num = "";
	while (temp != nullptr) {
		result_num.append(to_string(temp->value));
		temp = temp->next;
	}
	int result = stoi(result_num);
	return result;
}


#pragma endregion
#pragma region PALINDROME

bool Singly_Linked_List::palindrome(Singly_Linked_List list) {
	vector<int> copy = get_list_vector(list);
	Node * temp = list.head;
	for (int i = copy.size() - 1; i > 0; --i) {
		if (copy[i] != temp->value || temp == nullptr) {
			return false;
		}
		temp = temp->next;
	}
	return true;
}


vector<int> Singly_Linked_List::get_list_vector(Singly_Linked_List list) {
	Node * temp = list.head;
	vector<int> copy;
	while (temp != nullptr) {
		copy.push_back(temp->value);
		temp = temp->next;
	}
	return copy;
}


bool Singly_Linked_List::palindrome_recurse(Singly_Linked_List list) {
	Node * temp_head = head;
	Node * temp_tail = head;
	bool result = palindrome_recurse_helper(temp_head, temp_tail);
	return result;
}


bool Singly_Linked_List::palindrome_recurse_helper(Node *& head, Node * temp) {
	if (temp == nullptr) {
		return true;
	}
	bool result = palindrome_recurse_helper(head, temp->next);
	if (result == false) {
		return false;
	}
	else if (result == true && temp->value == head->value) {
		head = head->next;
		return true;
	}
	else {
		return false;
	}
}


#pragma endregion
#pragma region LOOP DETECTION


Node * Singly_Linked_List::loop_detection() {
	unordered_set<Node *> addresses;
	Node * temp = head;
	while (temp != nullptr) {
		if (addresses.find(temp) != addresses.end()) {
			return temp;
		}
		addresses.insert(temp);
		temp = temp->next;
	}
	cout << "List is not circular\n";
	return tail;
}


#pragma endregion


#pragma endregion