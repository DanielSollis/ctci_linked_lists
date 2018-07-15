#include "Singly_Linked_List.h";
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::cin;
using std::string;
using std::to_string;


#pragma region PROTOTYPES


//Sum Lists
Singly_Linked_List sum_lists(Singly_Linked_List one, Singly_Linked_List two);
Singly_Linked_List create_result_list(string sum_string);

//Tests
void test_remove_dups();
void run_removal_version(Singly_Linked_List & list);
int choose_buff();

void test_sum_lists();
Singly_Linked_List get_int_list(int num);
void print_result(int first_num, int second_num);

void test_kth_to_last();
void run_kth_version(Singly_Linked_List list, int kth_version, int k);

void test_partition();

void test_palindrome();
bool run_palindrome_version(char ver, Singly_Linked_List * list);
void print_palindrome_result(bool result);

void test_loop_detection();
void test_is_circular();

//helpers
Singly_Linked_List get_test_list();
int get_n();
char get_char();
bool check_repeat();
char get_func_version();


#pragma endregion


int main() {
	test_loop_detection();
	return 0;
}


#pragma region SUM LISTS


Singly_Linked_List sum_lists(Singly_Linked_List one, Singly_Linked_List two) {
	int num_one = one.get_int_rep();
	int num_two = two.get_int_rep();
	int sum = num_one + num_two;
	string sum_string = to_string(sum);
	Singly_Linked_List result = create_result_list(sum_string);
	return result;
}


Singly_Linked_List create_result_list(string sum_string) {
	Singly_Linked_List result;
	for (int i = 0; i < sum_string.size(); ++i) {
		char element = sum_string[i];
		int num = element - '0';
		result.push_back(num);
	}
	return result;
}


#pragma endregion
#pragma region TESTS


#pragma region TEST REMOVE DUPS


void test_remove_dups() {
	bool quit = false;
	while (!quit) {
		Singly_Linked_List list = get_test_list();
		if (list.head == nullptr) {
			printf("You Did Not Make a List\n");
		}
		else {
			cout << list << "\n";
			run_removal_version(list);
			cout << list << "\n";
		}
		quit = check_repeat();
	}
}


void run_removal_version(Singly_Linked_List & list) {
	int buff = choose_buff();
	if (buff == 0) {
		list.remove_dups();
	}
	else {
		list.remove_dups_nobuff();
	}
}


int choose_buff() {
	int buff;
	printf("Use Buffer? (0 for yes): ");
	cin >> buff;
	return buff;
}


#pragma endregion
#pragma region TEST SUM LISTS


void test_sum_lists() {
	bool quit = false;
	while (!quit) {
		printf("Enter the first number to add (-1 to quit): ");
		int first_num;
		cin >> first_num;
		printf("Enter the second number to add: ");
		int second_num;
		cin >> second_num;
		quit = check_repeat();
	}
}

Singly_Linked_List get_int_list(int num) {
	Singly_Linked_List list;
	string str = to_string(num);
	for (int i = 0; i < str.size(); ++i) {
		list.push_back(str[i] - '0');
	}
	return list;
}

void print_result(int first_num, int second_num) {
	Singly_Linked_List one = get_int_list(first_num);
	Singly_Linked_List two = get_int_list(second_num);
	Singly_Linked_List result = sum_lists(one, two);
	result.print_list();
	printf("\n");
}


#pragma endregion
#pragma region TEST KTH TO LAST


void test_kth_to_last() {
	bool done = false;
	while (!done) {
		Singly_Linked_List test_list = get_test_list();
		test_list.print_list();
		char kth_version = get_func_version();
		int k = get_n();
		run_kth_version(test_list, kth_version, k);
		done = check_repeat();
	}
}


void run_kth_version(Singly_Linked_List list, int kth_version, int k) {
	if (kth_version == 0) {
		int size = list.get_size();
		Node kth = list.kth_to_last(k, size);
		printf("\n%d\n", kth.value);
	}
	else {
		Node * kth = list.kth_to_last(k);
		printf("\n%d\n", kth->value);
	}
}


#pragma endregion
#pragma region TEST PARTITION


void test_partition() {
	bool done = false;
	while (!done) {
		Singly_Linked_List list = get_test_list();
		list.print_list();
		int x = get_n();
		list.partition(x);
		list.print_list();
		done = check_repeat();
	}
}


#pragma endregion
#pragma region TEST PALINDROME


void test_palindrome() {
	bool done = false;
	while (!done) {
		Singly_Linked_List temp_list = get_test_list();
		Singly_Linked_List * list = &temp_list;
		list->print_list();
		char ver = get_func_version();
		bool result = run_palindrome_version(ver, list);
		print_palindrome_result(result);
		done = check_repeat();
	}
}


bool run_palindrome_version(char ver, Singly_Linked_List * list) {
	bool result = false;
	if (ver == '0') {
		result = list->palindrome(*list);
	}
	else {
		result = list->palindrome_recurse(*list);
	}
	return result;
}


void print_palindrome_result(bool result) {
	if (result) {
		printf("YES\n\n");
	}
	else {
		printf("NO\n\n");
	}
}


#pragma endregion
#pragma region TEST LOOP DETECTION


void test_loop_detection() {
	bool done = false;
	while (!done) {
		Singly_Linked_List temp_list = get_test_list();
		Singly_Linked_List * list = &temp_list;
		int ran = list->make_list_circular();
		Node * result_node = list->loop_detection();
		printf("Node number: %d\n", ran);
		printf("Node value: %d\n", result_node->value);
		done = check_repeat();
	}
}


void test_is_circular() {
	Singly_Linked_List temp_list = get_test_list();
	Singly_Linked_List * list = &temp_list;
	bool done = false;
	while (!done) {
		int ran_num = list->make_list_circular();
		printf("\n%d\n", ran_num);
		list->print_list();
		done = check_repeat();
	}
}


#pragma endregion


#pragma endregion
#pragma region HELPERS


Singly_Linked_List get_test_list() {
	Singly_Linked_List list;
	bool list_done = false;
	while (!list_done) {
		printf("Enter Numbers for the List (-1 to Finish): ");
		int to_add;
		cin >> to_add;
		if (to_add == -1) {
			list_done = true;
		}
		else {
			list.push_back(to_add);
		}
	}
	return list;
}


int get_n() {
	printf("Enter number: ");
	int n;
	cin >> n;
	return n;
}


char get_char() {
	printf("Enter number: ");
	char n;
	cin >> n;
	return n;
}


bool check_repeat() {
	bool done = false;
	printf("go again? Y/N");
	char again;
	cin >> again;
	if (toupper(again) != 'Y') {
		done = true;
	}
	return done;
}


char get_func_version() {
	printf("Choose a version (0 for non-recursive) ");
	char func_version;
	cin >> func_version;
	return func_version;
}


#pragma endregion