#ifndef __ITERATOR_H__
#define __ITERATOR_H__
#pragma warning(disable:4996)
#include<iostream>
#include<math.h>
using namespace std;
class Iterator
{
private:
	char*& Ptr;
	int& Size;
	int Index;
public:
	int getIndex();
	int& getSize();
	Iterator(char*& ptr, int& size, int index);
	Iterator(const Iterator &other) = default;
	Iterator& operator = (const Iterator &other) = default;
	char& operator *();
	const char& operator *() const;
	Iterator& operator++();
	Iterator operator++(int);
	Iterator& operator--();
	Iterator operator--(int);
	Iterator operator+(int i);
	Iterator operator-(int i);
	Iterator& operator+=(int i);
	Iterator& operator-=(int i);
	bool operator != (const Iterator& s);
	bool operator == (const Iterator& s);
	~Iterator() = default;
};
class ReverseIterator
{
private:
	char*& Ptr;
	int& Size;
	int Index;
public:
	int& getSize();
	int getIndex();
	ReverseIterator(char*& ptr, int& size, int index);
	ReverseIterator(const ReverseIterator &other) = default;
	ReverseIterator& operator = (const ReverseIterator &other) = default;
	char& operator *();
	const char& operator*() const;
	ReverseIterator& operator++();
	ReverseIterator operator++(int);
	ReverseIterator& operator--();
	ReverseIterator operator--(int);
	ReverseIterator operator+(int i);
	ReverseIterator operator-(int i);
	ReverseIterator& operator+=(int i);
	ReverseIterator& operator-=(int i);
	bool operator != (const ReverseIterator& s);
	bool operator == (const ReverseIterator& s);
	~ReverseIterator() = default;
};
#endif
