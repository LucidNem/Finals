// #include <iostream>

// using namespace std;

// int main(int argc, char **argv)
// {



//     return 0;
// }





#include <iostream>
#include <string>

template<class T> class Queue {
private:
	T *queue;
	unsigned int size;
	
public:
	Queue();
	~Queue();
	
	void Enqueue(const T &);
	void Dequeue();
	
	unsigned int Size();
	
	bool operator==(const Queue &);
	
	void Print();
};
template<class T> Queue<T>::Queue() : size(0) {}
template<class T> Queue<T>::~Queue() { if (size > 0) delete[] queue; }

template<class T> void Queue<T>::Enqueue(const T &item) {
	unsigned int newSize = size + 1;
	
	T *old = new T[newSize];
	for (unsigned int i = 0; i < size; i++) {
		old[i] = queue[i];
	}
	old[size] = item;
	if (size > 0) delete[] queue;
	
	queue = new T[newSize];
	for (unsigned int i = 0; i < newSize; i++) {
		queue[i] = old[i];
	}
	size = newSize;
	delete[] old;
}
template<class T> void Queue<T>::Dequeue() {
	if (!size) return;
	
	unsigned int newSize = size - 1;
	
	T *old = new T[newSize];
	for (unsigned int i = 1; i < size; i++) {
		old[i - 1] = queue[i];
	}
	delete[] queue;
	
	queue = new T[newSize];
	for (unsigned int i = 0; i < newSize; i++) {
		queue[i] = old[i];
	}
	size = newSize;
	delete[] old;
}

template<class T> unsigned int Queue<T>::Size() { return size; }

template<class T> bool Queue<T>::operator==(const Queue &q) {
	if (size != q.size ) return false;
	for (unsigned int i = 0; i < size; i++) {
		if (queue[i] != q.queue[i]) return false;
	}
	return true;
}

template<class T> void Queue<T>::Print() {
	for (unsigned int i = 0; i < size; i++)
		std::cout << queue[i] << std::endl;
}

class QueueItem {
private:
	int num;
	std::string str;

public:
	QueueItem();
	QueueItem(int, std::string);
	~QueueItem();
	
	bool operator!=(const QueueItem &);
	
	friend std::ostream &operator<<(std::ostream &, const QueueItem &);
};
QueueItem::QueueItem() {}
QueueItem::QueueItem(int n, std::string s) 
: num(n), str(s) {}
QueueItem::~QueueItem() {}

bool QueueItem::operator!=(const QueueItem &qi) {
	return num != qi.num || str != qi.str;
}

std::ostream &operator<<(std::ostream &os, const QueueItem &qi) {
	os << "Num: " << qi.num << ", Str: " << qi.str;
    return os;
}


int main(int argc, char** argv) {
	Queue<QueueItem> q;
	q.Dequeue();
	for (int i = 0; i < 10; i++) {
		q.Enqueue(QueueItem(i, "item"));
	}
	for (int i = 0; i < 3; i++) {
		q.Dequeue();
	}
	
	Queue<QueueItem> q2;
	for (int i = 3; i < 10; i++) {
		q2.Enqueue(QueueItem(i, "item"));
	}
	
	std::cout << "Q Size: " << q.Size() << std::endl;
	q.Print();
	
	std::cout << "Q == Q2: " << (q == q2) << std::endl;
	
	return 0;
}
