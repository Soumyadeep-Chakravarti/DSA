#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

typedef Node *NodePtr;

void addHead(NodePtr &Head, int newdata)
{

	NodePtr newPtr = new Node;

	if (newPtr != NULL)
	{
		newPtr->data = newdata;
		newPtr->next = Head;
		Head = newPtr;
	}
	else
	{
		cout << "Memory allocation error" << endl;
		exit(1);
	}
}

// fucntion version
NodePtr addHeadFunc(NodePtr head, int newdata)
{

	NodePtr newPtr = new Node;
	newPtr->data = newdata;
	newPtr->next = head;
	return newPtr;
}

void delHead(NodePtr &Head)
{

	if (Head != NULL)
	{
		NodePtr cur = Head;
		Head = Head->next;
		delete cur;
	}
}

// function version
NodePtr delHeadFunc(NodePtr Head)
{

	if (Head != NULL)
	{
		NodePtr cur = Head;
		Head = Head->next;
		delete cur;
	}

	return Head;
}

void DisplayList(NodePtr Head)
{
	NodePtr cur;
	cur = Head;
	while (cur != NULL)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}

// return the pointer of the node has data=item
// return NULL if item does not exist
NodePtr searchNode(NodePtr Head, int item)
{
	NodePtr Cur = Head;
	while ((Cur != NULL) && (Cur->data != item))
		Cur = Cur->next;

	return Cur;
}

void addEnd(NodePtr &Head, int newdata)
{

	NodePtr last = Head;
	NodePtr newPtr = new Node;
	if (newPtr == NULL)
	{
		cout << "allocation error" << endl;
		exit(1);
	}
	newPtr->data = newdata;
	newPtr->next = NULL;
	if (last != NULL)
	{ // general non-empty list case
		while (last->next != NULL)
			last = last->next;
		last->next = newPtr;
	}
	else // deal with the case of empty list
		Head = newPtr;
}

// functin version
NodePtr addEndFunc(NodePtr Head, int newdata)
{

	NodePtr last = Head;
	NodePtr newPtr = new Node;
	if (newPtr == NULL)
	{
		cout << "allocation error" << endl;
		exit(1);
	}
	newPtr->data = newdata;
	newPtr->next = NULL;
	if (last != NULL)
	{ // general non-empty list case
		while (last->next != NULL)
			last = last->next;
		last->next = newPtr;
	}
	else // deal with the case of empty list
		Head = newPtr;

	return Head;
}

// insert item into linked list according to ascending order
void insertNode(NodePtr &Head, int item)
{
	NodePtr New, Cur, Pre;
	New = new Node;
	if (New == NULL)
	{
		cout << "Insufficient Memory" << endl;
		exit(1);
	}
	New->data = item;
	Pre = NULL;
	Cur = Head;
	while (Cur != NULL && item > Cur->data)
	{
		Pre = Cur;
		Cur = Cur->next;
	}
	if (Pre == NULL)
	{ // insert to head of linked list
		New->next = Head;
		Head = New;
	}
	else
	{
		Pre->next = New;
		New->next = Cur;
	}
}

void deleteNode(NodePtr &Head, int item)
{
	NodePtr prev, cur = Head;
	while (cur != NULL && item > cur->data)
	{
		prev = cur;
		cur = cur->next;
	}

	if (cur == NULL || cur->data != item)
	{
		cout << "Delete error: " << item
			 << " not in list!" << endl;
		return;
	}
	if (cur == Head)
		Head = Head->next;
	else
		prev->next = cur->next;
	delete cur;
}

int length(NodePtr Head)
{
	int size = 0;
	NodePtr cur = Head;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

int lengthRec(NodePtr Head)
{
	if (Head == NULL)
		return 0;
	return length(Head->next) + 1;
}

// returns merged list (changes first list)
NodePtr mergeLists(NodePtr Head1, NodePtr Head2)
{
	NodePtr Union, Cur;

	if (Head1 == NULL)
		return Head2;
	else if (Head2 == NULL)
		return Head1;
	Union = Head1;
	Cur = Head2;
	while (Cur != NULL)
	{
		if (searchNode(Union, Cur->data) == NULL)
			insertNode(Union, Cur->data);
		Cur = Cur->next;
	}
	return Union;
}

bool isPalindromeOld(NodePtr Head)
{
	// copy the list in reverse order
	NodePtr newList = NULL;
	NodePtr cur = Head;
	while (cur != NULL)
	{
		addHead(newList, cur->data);
		cur = cur->next;
	}

	// compare the list and reversed list
	cur = Head;
	while (cur != NULL)
	{
		if (cur->data != newList->data)
			return false; // not palindrome!
		cur = cur->next;
		newList = newList->next;
	}
	return true; // all same; must be palindrome!
}

bool isPalindrome(NodePtr head)
{
	NodePtr newList = NULL;
	NodePtr p = head;
	while (p != NULL)
	{
		addHead(newList, p->data);
		p = p->next;
	}

	NodePtr p1 = head;
	NodePtr p2 = newList;
	bool palindrome = true;
	while ((p1 != NULL) && (palindrome))
	{
		if ((p1->data) == (p2->data))
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		else
			palindrome = false;
	}

	p = newList;
	while (p != NULL)
	{
		delHead(p);
	}

	return palindrome;
}

// for the recursive version of palindrom

NodePtr reverse(NodePtr head)
{
	NodePtr res;
	if (head == NULL)
		res = NULL;
	else
		res = addEndFunc(reverse(head->next), head->data);
	return res;
}

bool palindrome(NodePtr p1, NodePtr p2)
{

	bool palin;
	if (p1 == NULL)
		palin = true;
	else if ((p1->data) != (p2->data))
		palin = false;
	else
		palin = palindrome(p1->next, p2->next);

	return palin;
}

void deleteList(NodePtr head)
{
	NodePtr p = head;
	if (p != NULL)
	{
		p = delHeadFunc(p);
		deleteList(p);
	}
}

bool isPalindromeRec(NodePtr head)
{
	bool palin;

	NodePtr newList = reverse(head);
	palin = palindrome(head, newList);
	deleteList(newList);

	return palin;
}

int main()
{
	NodePtr Head1 = NULL, Head2 = NULL, Head;

	addHead(Head1, 50);
	addHead(Head1, 40);
	addHead(Head1, 30);
	addHead(Head1, 20);
	cout << "List 1: " << endl;
	DisplayList(Head1);
	cout << "Length of Head1 list: " << length(Head1) << endl;
	cout << "Recursive length of Head1 list: " << lengthRec(Head1) << endl;
	if (isPalindrome(Head1))
		cout << "Head1 list is palindrome" << endl;
	else
		cout << "Head1 list is not palindrome" << endl;

	addHead(Head2, 25);
	addHead(Head2, 35);
	addHead(Head2, 45);
	addHead(Head2, 35);
	addHead(Head2, 25);
	cout << "List 2: " << endl;
	DisplayList(Head2);
	cout << "Length of Head2 list: " << length(Head2) << endl;
	cout << "Recursive length of Head2 list: " << lengthRec(Head2) << endl;
	if (isPalindrome(Head2))
		cout << "Head2 list is palindrome" << endl;
	else
		cout << "Head2 list is not palindrome" << endl;

	Head = mergeLists(Head1, Head2);
	cout << "Merged List: " << endl;
	DisplayList(Head);

	cout << "Length of Merged list: " << length(Head) << endl;
	cout << "Recursive length of Merged list: " << lengthRec(Head) << endl;
	if (isPalindromeRec(Head))
		cout << "Merged list is palindrome" << endl;
	else
		cout << "Merged list is not palindrome" << endl;
	cout << "check the list again:" << endl;
	DisplayList(Head);
}
