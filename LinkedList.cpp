/*------------------------------------------------------------
    author  : tareq mahmood
    id      : 1305011
    descrip : this a offline submission of CSE 202 course
-------------------------------------------------------------*/


#include <iostream>
#include <cstdio>
#include <windows.h>
#include <sstream>

#define prl(x) cout << x << endl;

using namespace std;

class Element {
private:
    Element * next;
	Element * prev;
	int value;
public:
	void setNext(Element *n) {
		next = n;
	}
	Element * getNext() {
		return next;
	}
	void setPrev(Element *p) {
		prev  = p;
	}
	Element * getPrev() {
		return prev;
	}
	void setValue(int v) {
		value = v;
	}
	int getValue() {
		return value;
	}
};

class LinkedListBase {
protected:
	Element * head;
	Element * tail;
	int size;
public:
	LinkedListBase() {
        head=new Element;
        tail=new Element;
		head->setNext(tail);
		tail->setPrev(head);
		size = 0;
    }
	int getSize() {
		return size;
	}
	~LinkedListBase() {
		delete head;
		delete tail;
	}
};

class LinkedList: public LinkedListBase {

public:
    void add(Element e);
    void add(int index, Element e);
    void addFirst(Element e);
    void addLast(Element e);
    void clear();
    bool contains(Element e);
    Element get(int index);
    Element getFirst();
    Element getLast();
    int indexOf(Element e);
    int lastIndexOf(Element e);
    Element remove(int index);
    bool remove(Element e);
    Element removeFirst();
    bool removeFirstOccurrence(Element e);
    Element removeLast();
    bool removeLastOccurrence(Element e);
    int Size();
    bool isEmpty();
    string toString();

    // for debugging purpose //
    void forPrint();
    void backPrint();
    void okPrint();
};

void LinkedList::add(Element e)
{
    Element *node = new Element;
    node->setValue(e.getValue());
    if(size == 0)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->setNext(node);
        node->setPrev(tail);
        tail = node;
    }
    size++;
}

void LinkedList::add(int index, Element e)
{
    Element *node = new Element;
    node->setValue(e.getValue());
    if(index > size) return;
    if(index == size)
    {
        add(e);
        return;
    }
    Element *temp = head;
    for(int i = 0; i < size; i++)
    {
        if(i == index) break;
        else temp = temp->getNext();
    }
    if(temp == head)
    {
        node->setNext(head);
        head->setPrev(node);
        head = node;
        size++;
    }
    else {
        node->setNext(temp);
        node->setPrev(temp->getPrev());
        temp->getPrev()->setNext(node);
        temp->setPrev(node);
        size++;
    }
}

void LinkedList::addFirst(Element e)
{
    Element *node = new Element;
    node->setValue(e.getValue());
    if(size == 0)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->setNext(head);
        head->setPrev(node);
        head = node;
    }
    size++;
}

void LinkedList::addLast(Element e)
{
    Element *node = new Element;
    node->setValue(e.getValue());
    if(size == 0)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->setNext(node);
        node->setPrev(tail);
        tail = node;
    }
    size++;
}

void LinkedList::clear()
{
    head = 0;
    tail = 0;
    size = 0;
}

bool LinkedList::contains(Element e)
{
    Element *temp = head;
    for(int i = 0; i < size; i++)
    {
        if(temp->getValue() == e.getValue()) return true;
        temp = temp->getNext();
    }
    return false;
}

Element LinkedList::get(int index)
{
    Element *temp = head;
    for(int i = 0; i < size; i++)
    {
        if(i == index) return *temp;
        temp = temp->getNext();
    }
    cout << "Not Found" << endl;
}

Element LinkedList::getFirst()
{
    if(size == 0)
    {
        cout << "List is empty" << endl;
    }
    return *head;
}

Element LinkedList::getLast()
{
    if(size == 0)
    {
        cout << "List is empty" << endl;
    }
    return *tail;
}

int LinkedList::indexOf(Element e)
{
    Element *temp = head;
    for(int i = 0; i < size; i++)
    {
        if(temp->getValue() == e.getValue()) return i;
        temp = temp->getNext();
    }
    return -1;
}

int LinkedList::lastIndexOf(Element e)
{
    Element *temp = tail;
    for(int i = size - 1; i >= 0; i--)
    {
        if(temp->getValue() == e.getValue()) return i;
        temp = temp->getPrev();
    }
    return -1;
}

Element LinkedList::remove(int index)
{
    if(index >= size)
    {
        cout << "WARNING: index out of range!" << endl;
        exit(0);
    }
    if(size == 0)
    {
        cout << "WARNING: list is already empty!" << endl;
        exit(0);
    }
    Element *temp = head;
    for(int i = 0; i < size; i++)
    {
        if(i == index) break;
        else temp = temp->getNext();
    }
    if(temp == head)
    {
        head = temp->getNext();
    }
    else if(temp == tail)
    {
        tail = temp->getPrev();
    }
    else
    {
        temp->getPrev()->setNext(temp->getNext());
        temp->getNext()->setPrev(temp->getPrev());
    }
    size--;
    return *temp;
}

bool LinkedList::remove(Element e)
{
    Element *temp = head;
    int i;
    for(i = 0; i < size; i++)
    {
        if(temp->getValue() == e.getValue()) break;
        else temp = temp->getNext();
    }
    if(i == size) return false;
    if(temp == head)
    {
        head = temp->getNext();
    }
    else if(temp == tail)
    {
        tail = temp->getPrev();
    }
    else
    {
        temp->getPrev()->setNext(temp->getNext());
        temp->getNext()->setPrev(temp->getPrev());
    }
    size--;
    free(temp);
    return true;
}

Element LinkedList::removeFirst()
{
    if(size == 0)
    {
        cout << "WARNING: list is already empty!" << endl;
        exit(0);
    }
    Element *temp = head;
    if(size == 1) tail = head = NULL;
    else head = temp->getNext();
    size--;
    return *temp;
}

bool LinkedList::removeFirstOccurrence(Element e)
{
    return remove(e);
}

Element LinkedList::removeLast()
{
    if(size == 0)
    {
        cout << "WARNING: list is already empty!" << endl;
        exit(0);
    }
    Element *temp = tail;
    if(size == 1) head = tail = NULL;
    else tail = temp->getPrev();
    size--;
    return *temp;
}

bool LinkedList::removeLastOccurrence(Element e)
{
    Element *temp = head;
    Element *temp2 = NULL;
    int i;
    for(i = 0; i < size; i++)
    {
        if(temp->getValue() == e.getValue()) temp2 = temp;
        temp = temp->getNext();
    }
    if(temp2 == NULL) return false;
    if(temp2 == head)
    {
        head = temp2->getNext();
    }
    else if(temp2 == tail)
    {
        tail = temp2->getPrev();
    }
    else
    {
        temp2->getPrev()->setNext(temp2->getNext());
        temp2->getNext()->setPrev(temp2->getPrev());
    }
    size--;
    free(temp2);
    return true;
}

int LinkedList::Size()
{
    return size;
}

bool LinkedList::isEmpty()
{
    return (size == 0);
}

string LinkedList::toString()
{
    stringstream s;
    Element *temp = head;
    for(int i = 0; i < size; i++)
    {
        s << temp->getValue();
        if(i != size - 1) s << ",";
        temp = temp->getNext();
    }
    return s.str();
}

int menu()
{
    printf("-------------------------------------------------------------------------\n");
    printf("1. Add new element \t 2. Add new element at \t 3. Add first\n");
    printf("4. Add last \t\t 5. Clear \t\t 6. If contains \n");
    printf("7. Get element at \t 8. Get first \t\t 9. Get last \n");
    printf("10. Index of element \t 11. Last index of \t 12. Remove and get \n");
    printf("13. Remove \t\t 14. Remove first \t 15. Remove first occur \n");
    printf("16. Remove last \t 17. Remove last occur \t 18. Get size \n");
    printf("19. Check empty \t 20. Show in string \t 21. exit \n");
    printf("-------------------------------------------------------------------------\n");
    int n;
    scanf("%d", &n);
    return n;
}

void LinkedList::forPrint()
{
    Element *temp = head;
    printf("    ");
    cout << "list size: " << size << endl;
    printf("    ");
    for(int i = 0; i < size; i++)
    {
        cout << temp->getValue();
        if(i < size - 1) cout << "->";
        temp = temp->getNext();
    }
    cout << endl;
}

void LinkedList::backPrint()
{
    Element *temp = tail;
    for(int i = 0; i < size; i++)
    {
        cout << temp->getValue();
        if(i < size - 1) cout << "<-";
        temp = temp->getPrev();
    }
    cout << endl;
}

void LinkedList::okPrint()
{
    prl("-------------------------------");
    forPrint();
    printf("    ");
    Element *a = head;
    int arr[100];
    Element *b = tail;
    for(int i = 0; i < size; i++)
    {
        arr[i] = a->getValue();
        a = a->getNext();
    }
    for(int i = size - 1; i >= 0; i--)
    {
        if(arr[i] != b->getValue())
        {
            prl(i << "Not Okay!");
            return;
        }
        b = b->getPrev();
    }
    prl("Okay!");
    prl("-------------------------------");
}

// just a sample main function //

int main()
{
    LinkedList ll;
    while(1)
    {
        int n = menu();
        if(n == 1)
        {
            int value;
            cout << "Value: ";
            cin >> value;
            Element e;
            e.setValue(value);
            ll.add(e);
        }
        else if(n == 2)
        {
            int value, index;
            cout << "Value: ";
            cin >> value;
            cout << "Index: ";
            cin >> index;
            Element e;
            e.setValue(value);
            ll.add(index, e);
        }
        else if(n == 3)
        {
            int value;
            cout << "Value: ";
            cin >> value;
            Element e;
            e.setValue(value);
            ll.addFirst(e);
        }
        else if(n == 4)
        {
            int value;
            cout << "Value: ";
            cin >> value;
            Element e;
            e.setValue(value);
            ll.addLast(e);
        }
        else if(n == 5)
        {
            ll.clear();
        }
        else if(n == 6)
        {
            int value;
            cout << "Value: ";
            cin >> value;
            Element e;
            e.setValue(value);
            if(ll.contains(e)) cout << "This element is in the list" << endl;
            else cout << "This element is NOT in the list" << endl;
        }
        else if(n == 7)
        {
            int index;
            cout << "Index: ";
            cin >> index;
            cout << ll.get(index).getValue() << endl;
        }
        else if(n == 8)
        {
            cout << ll.getFirst().getValue() << endl;
        }
        else if(n == 9)
        {
            cout << ll.getLast().getValue() << endl;
        }
        else if(n == 10)
        {
            int value;
            cout << "Value: ";
            cin >> value;
            Element e;
            e.setValue(value);
            cout << ll.indexOf(e) << endl;
        }
        else if(n == 11)
        {
            int value;
            cout << "Value: ";
            cin >> value;
            Element e;
            e.setValue(value);
            cout << ll.lastIndexOf(e) << endl;
        }
        else if(n == 12)
        {
            int index;
            cout << "Index: ";
            cin >> index;
            if(index >= ll.Size())
            {
                cout << "Invalid index" << endl;
                continue;
            }
            cout << "Removed element: " << ll.remove(index).getValue() << endl;
        }
        else if(n == 13)
        {
            int value;
            cout << "Value: ";
            cin >> value;
            Element e;
            e.setValue(value);
            if(ll.remove(e)) cout << "successful remove" << endl;
            else cout << "unsuccessful remove" << endl;
        }
        else if(n == 14)
        {
            if(ll.Size() == 0)
            {
                cout << "The list is already empty" << endl;
                continue;
            }
            cout << ll.removeFirst().getValue() << endl;
        }
        else if(n == 15)
        {
            int value;
            cout << "Value: ";
            cin >> value;
            Element e;
            e.setValue(value);
            if(ll.removeFirstOccurrence(e)) cout << "successful remove" << endl;
            else cout << "unsuccessful remove" << endl;
        }
        else if(n == 16)
        {
            if(ll.Size() == 0)
            {
                cout << "The list is already empty" << endl;
                continue;
            }
            cout << ll.removeLast().getValue() << endl;
        }
        else if(n == 17)
        {
            int value;
            cout << "Value: ";
            cin >> value;
            Element e;
            e.setValue(value);
            if(ll.removeLastOccurrence(e)) cout << "successful remove" << endl;
            else cout << "unsuccessful remove" << endl;
        }
        else if(n == 18)
        {
            cout << "List size : " << ll.Size() << endl;
        }
        else if(n == 19)
        {
            if(ll.isEmpty()) cout << "List is empty" << endl;
            else cout << "List is not empty" << endl;
        }
        else if(n == 20)
        {
            cout << ll.toString() << endl;
        }
        else
        {
            break;
        }
        ll.okPrint();
    }
	return 0;
}
