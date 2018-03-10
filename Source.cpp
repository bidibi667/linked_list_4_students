
#include <iostream>

struct Node {
	int data = 0;
	Node *pNext = nullptr;
};

struct List {
	Node *pHead = nullptr;
	int len = 0;
};


void Print(const List &lst) {
	Node *it = lst.pHead;
	while (it) {
		std::cout << it->data << '\t';
		it = it->pNext;
	}
	std::cout << std::endl;
}

void Append(List &lst, int data) {
	Node *new_node = new Node;
	new_node->data = data;
	new_node->pNext = lst.pHead;
	lst.pHead = new_node;
	++lst.len;
}

int Pop(List &lst) {
	if (!lst.len) {
		std::cerr << "Attempt to delete from empty list.\n";
		return -1;
	}
	Node *to_delete = lst.pHead;
	int ret_val = lst.pHead->data;

	lst.pHead = lst.pHead->pNext;

	delete to_delete;
	--lst.len;
	return ret_val;
}

int GetData(const List &lst, int index) {
	if (lst.len < index + 1)
	{
		std::cerr << "Wrong index\n";
		return -1;
	}
	Node *it = lst.pHead;
	int count = 0;
	while (it && count != index) {
		++count;
		it = it->pNext;
	}
	return it->data;

}


void Insert(List &lst, int data, int pos) {
	if (lst.len < pos)
	{
		std::cerr << "Wrong position\n";
		return;
	}
	if (!pos) {
		
		Append(lst, data);
		return;
	}
	Node *new_item = new Node;
	new_item->data = data;
	int index = 1;
	Node *it = lst.pHead;
	while (it && index != pos) {
		++index;
		it = it->pNext;
	}
	new_item->pNext = it->pNext;
	it->pNext = new_item;
}


struct Dummy {
	int a = 9;
};

int main()
{

	List my_list;
	Append(my_list, 0);

	Append(my_list, 1);
	Append(my_list, 2);
	Append(my_list, 3);
	Append(my_list, 4);
	Append(my_list, 5);
	Print(my_list);
	Insert(my_list, 6, 3);
	Print(my_list);

	Insert(my_list, 7, 0);
	Print(my_list);

	Insert(my_list, 8, 7);
	Print(my_list);

	Insert(my_list, 9, 10);
	Print(my_list);

	getchar();
	return 0;
}