#pragma once
#ifndef QUEUELI_H_
#define QUEUELI_H_

template<class Object>
class Queue
{
public:
	Queue();
	~Queue();

	bool isEmpty() const; // 判断队列是不是空的；
	const Object & getFront() const; // 返回队首的数据；
	void enqueue(const Object & x);	// 向队列中写入数据；
	Object dequeue();	// 删除队列中的数据，就是删除队尾的数据；
	void makeEmpty();	// 清空整个队列；
private:
	struct ListNode	// 可以写在内部作为嵌套，也可以写在外面写为友元类；此处也可以写作class
	{
		Object element; // 存放队列中元素数据；
		ListNode *next; // 存放队列中的元素对应的指针；

		ListNode(const Object & theElement, ListNode *n = 0):element(theElement),next(n){}

	};
	ListNode *front;
	ListNode *back;
};

template<class Object>
Queue<Object>::Queue()
{
	front = back = 0; // 此时front和back都是0，创建了一个空的链表；
}

template<class Object>
Queue<Object>::~Queue()
{
	makeEmpty();
}

template<class Object>
void Queue<Object>::makeEmpty()
{
	while (!isEmpty()) //如果链表不为空，就一直进行删除，直到清空；
	{
		dequeue();
	}
}

template<class Object>
bool Queue<Object>::isEmpty() const
{
	return front == 0;
}

template<class Object>
const Object & Queue<Object>::getFront() const
{
	if (isEmpty())
		throw "Queue is empty.";
	return front->element; // 返回首元素；
}

template<class Object>
void Queue<Object>::enqueue(const Object &x)
{
	if (isEmpty())
		back = front = new ListNode(x); // 先new；
	else
		back = back->next = new ListNode(x); // back指向新加入的节点；
}

template<class Object>
Object Queue<Object>::dequeue()
{
	Object frontItem = getFront();

	ListNode *old = front;
	front = front->next;
	delete old; // 删除old;

	return frontItem;
}


#endif // !QUEUELI_H_