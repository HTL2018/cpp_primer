#pragma once
#ifndef _SEQUENTIALQUEUE_H
#define _SEQUENTIALQUEUE_H

#include <iostream>
#include <algorithm>

template<class T>
class Queue
{
public:
	Queue(int queueCapacity = 10);
	bool IsEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& itme);
	void PoP();
private:
	T *queue;
	int front; //存放队首位置；
	int rear;  //存放队尾位置；
	int capacity; // 存放队列的大小容量；
};

template<class T> // 定义构造函数；
Queue<T>::Queue(int queueCapacity) :capacity(queueCapacity)
{
	if (capacity < 1) throw"Queue capacity must be >0.";
	queue = new T[capacity];
	front = rear = 0;
}

template<class T> // 判断队列是否为空；
inline bool Queue<T>::IsEmpty() const
{
	return front == rear; //如果队首等于队尾，则队列为空；
}

template<class T>
void Queue<T>::Push(const T &item)
{
	//if (rear == capacity - 1)//capacity-1为队列最后一个，表明如果队尾到达队列最后，再+1，就回到队列首部；
	//	rear = 0;
	//else
	//	reat++;
	if ((rear + 1) % capacity == front)	//队列满了
	{
		//加倍；
		T* newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start < 2) //没有回绕
			std::copy(queue + start, queue + start + capacity - 1, newQueue);
		else
		{
			std:: copy(queue + start, queue + capacity, newQueue);
			std::copy(queue, queue + rear + 1, newQueue + capacity - start);
		}

		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}

	rear = (rear + 1) % capacity;//漂亮的代码！实现的功能和上面注释掉的代码的功能一样；
	queue[rear] = item;
}

template<class T>
inline T& Queue<T>::Front() const
{
	if (IsEmpty()) throw "Queue is empty. No front element.";
	return queue[(front + 1) % capacity]; //之所以这么写是因为在设计的时候，将front指的位置设计为空的；
}

template<class T>
inline T& Queue<T>::Rear() const
{
	if (IsEmpty()) throw "Queue is empty. No rear element.";
	return queue[rear % capacity];
}

template<class T>
void Queue<T>::PoP()
{
	if (IsEmpty()) throw "Queue is empty. Cannot delete.";
	front = (front + 1) % capacity;	// 作用类似于上面；
	queue[front].~T(); // 因为存入的可能是对象，所以调用析构函数来删除；这样保证第一个有元素的前一个位置是空的；
}
#endif // !_SEQUENTIALQUEUE_H