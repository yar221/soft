#include <iostream>
#include <cstring>

using namespace std;

class List{
public:
	List();
	~List();

	void getoutbeg();

	void putinend(string data);
	
	void putinbeg(string data);

	void clear();
	
	void getoutend();
	
	bool isempty();
	
	void print();

private:

	class Node
	{
	public:
		Node * pNext;
		string data;

		Node(string data = string(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node *head;
};

List::List()
{
	Size = 0;
	head = nullptr;
};

List::~List()
{
	clear();
};

void List::getoutbeg()
{
	Node *temp = head;

	head = head->pNext;

	delete temp;

	Size--;

};

void List::putinend(string data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);

	}

	Size++;
};

void List::clear()
{
	while (Size)
	{
		getoutbeg();
	}
};

void List::getoutend()
{
// 	Node *previous = this->head;
// 	for (int i = 0; i < Size - 1; i++)
// 	{
// 		previous = previous->pNext;
// 	}

// 	Node<T> *toDelete = previous->pNext;

// 	previous->pNext = toDelete->pNext;

// 	delete toDelete;
    if (!this->head)
        return;
 
    if (!this->head->pNext)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }
 
    Node *p = this->head;
    while (p->pNext->pNext)
        p = p->pNext;
 
    delete p->pNext;
    p->pNext = nullptr;

	Size--;
};

void List::print(){
    Node *tmp= this->head;
    
    while(tmp){
    
        cout<<tmp->data<<endl;
        
        tmp=tmp->pNext;
    
    }
};

bool List::isempty(){
    if(this->Size == 0){
        return true;
    }else{
        return false;
    }
};

void List::putinbeg(string data)
{
	head = new Node(data, head);
	Size++;
}

int main()
{
    List list;
    bool ex = true;
    while(ex){
        cout << "Что вы хотите сделать" << endl 
        << "1 создать новый элемент списка в его начале" << endl 
        << "2 получить и удалить первый элемент списка" << endl 
        << "3 создать новый элемент списка в его конце" << endl
        << "4  добыть и удалить последний элемент списка" << endl
        << "5 вывести список на экран" << endl 
        << "6 вернуть значение true, если список пуст" << endl
        << "7 выйти" << endl;
        
        char choice;
        cin >> choice;
        string data;
        switch(choice){
            case '1': 
                cout << "Введите строку" << endl;
                cin >> data;
                list.putinbeg(data);
                break;
            case '2': 
                list.getoutbeg();
                break;
            case '3': 
                cout << "Введите строку" << endl;
                cin >> data;
                list.putinend(data);
                break;
            case '4': 
                list.getoutend();
                break;
            case '5': 
                list.print();
                break;
            
            case '6': 
                list.isempty() ? cout << "true" << endl : cout << "false" << endl;
                break;
            
            case '7': 
                ex = false;
                break;
            default: 
                cout << "Шо то не то" << endl;
                break;
            
        }
    }

    return 0;
}
