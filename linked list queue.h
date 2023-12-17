template <class T>
class Node
{
	T data;
	Node* next;
public:
	/*Node()
	{
		data = 0;
		next = nullptr;
	}*/
	Node(T a, Node* v)
	{
		data = a;
		next = v;
	}
	void setData(T a)
	{
		data = a;
	}
	void setNext(Node* a)
	{
		next = a;
	}
	T getData()
	{
		return data;
	}
	Node<T>* getNext()
	{
		return next;
	}


};

template <class T>
class Queue
{
public:
	Node<T>* front;
	Node<T>* rear;
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}
	bool is_empty()
	{
		if (front == nullptr && rear == nullptr)
			return 1;
		return 0;

	}
	Queue(Queue<T>& a)
	{
		front = nullptr;
		rear = nullptr;
		if (a.is_empty() != true)
		{
			Node<T>* cur = a.front;
			while (cur->getNext() != nullptr)
			{
				this->enqueue(cur->getData());
				cur = cur->getNext();
			}
			this->enqueue(cur->getData());
		}
	}
	void enqueue(T a)
	{
		Node<T>* n_node = new Node<T>(a,NULL);
		//= new Node(a, nullptr);
		n_node->setData(a);
		n_node->setNext(nullptr);
		if (is_empty() == 1)
		{
			rear = n_node;
			front = n_node;
		}
		else
		{
			rear->setNext(n_node);
			rear = n_node;
		}
	}
	T dequeue()
	{
		//Node<T>* r_node = nullptr;
		T d;
		if (is_empty() == 1)
		{
			cout << "sorry queue is emptt\n";
			return T();
		}
		else
		{

			if (front->getNext() != nullptr)
			{
				d = front->getData();
				Node<T>* t = front->getNext();;
				delete front;
				front = t;
			}
			else
			{
				d = front->getData();;
				Node<T>* t = nullptr;
				delete front;
				front = nullptr;;
				rear = nullptr;
			}

			return d;

		}
	}
	int size()
	{
		int count = 0;
		Node<T>* c = front;
		if (c == nullptr)
			return 0;
		while (c->getNext() != nullptr)
		{
			count++;
			c = c->getNext();
		}
		if (c != nullptr)
			count++;
		return count;
	}
	T peek()
	{
		if (is_empty() != 1)
			return front->getData();
	}
	void clear()
	{
		while (front != nullptr)
			dequeue();
	}
	void print(Queue q)
	{
		Node<T>* current = q.front;
		while(current!= nullptr)
		{
			cout << current->getData() << " ";
			current = current->getNext();
		}
		cout << endl;
	}
	T Front()
	{
		if (is_empty() != 1)
			return front->getData();;
		return -1;
	}
	//q3
	bool isPalindrome(std::string a)
	{
		
		int i = 0;
		while (a[i] != '\0')
		{
			enqueue(a[i]);
			i++;
		}
		if (is_empty()==1)
			return 0;
		while (i>0)
		{
			char l = dequeue();
			if (l != a[--i])
				return 0;
		}
		return 1;
	}
};
