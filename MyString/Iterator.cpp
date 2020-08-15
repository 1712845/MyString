#include"Iterator.h"
Iterator::Iterator(char*&ptr,int& size, int index) : Ptr(ptr),Size(size),Index(index){}
char& Iterator::operator *()
{
	if (Index >= Size || Index < 0) throw out_of_range("Truy cap khong hop le!\n");
	return *(Ptr + Index);
}
int& Iterator::getSize()
{
	return Size;
}
int Iterator::getIndex()
{
	return Index;
}
const char& Iterator::operator *() const
{
	return *(Ptr + Index);
}
Iterator& Iterator::operator++()
{
	Index++;
	return *this;
}
Iterator Iterator::operator++(int)
{
	Iterator temp = *this;
	Index++;
	return temp;
}
Iterator& Iterator::operator--()
{
	Index--;
	return *this;
}
Iterator Iterator::operator--(int)
{
	Iterator temp = *this;
	Index--;
	return temp;
}
Iterator Iterator::operator+(int i)
{
	Index = Index + i;
	return *this;
}
Iterator Iterator ::operator-(int i)
{
	Index = Index - i;
	return *this;
}
Iterator& Iterator::operator+=(int i)
{
	Index += i;
	return *this;
}
Iterator& Iterator::operator-=(int i)
{
	Index -= i;
	return *this;
}
bool Iterator::operator!=(const Iterator& s)
{
	return Index != s.Index;
}
bool Iterator::operator==(const Iterator& s)
{
	return Index == s.Index;
}
ReverseIterator::ReverseIterator(char*&ptr, int& size, int index) : Ptr(ptr), Size(size), Index(index) {}
char& ReverseIterator::operator *()
{
	if (Index >= Size || Index < 0) throw out_of_range("Truy cap khong hop le!\n");
	return *(Ptr + Index);
}
const char& ReverseIterator::operator *() const
{
	return *(Ptr + Index);
}
ReverseIterator& ReverseIterator::operator++()
{
	Index--;
	return *this;
}
ReverseIterator ReverseIterator::operator++(int)
{
	ReverseIterator temp = *this;
	Index--;
	return temp;
}
ReverseIterator& ReverseIterator::operator--()
{
	Index++;
	return *this;
}
ReverseIterator ReverseIterator::operator--(int)
{
	ReverseIterator temp = *this;
	Index++;
	return temp;
}
ReverseIterator ReverseIterator::operator+(int i)
{
	Index = Index - i;
	return *this;
}
ReverseIterator ReverseIterator ::operator-(int i)
{
	Index = Index + i;
	return *this;
}
ReverseIterator& ReverseIterator::operator+=(int i)
{
	Index -= i;
	return *this;
}
ReverseIterator& ReverseIterator::operator-=(int i)
{
	Index += i;
	return *this;
}
bool ReverseIterator::operator!=(const ReverseIterator& s)
{
	return Index != -1;
}
bool ReverseIterator::operator==(const ReverseIterator& s)
{
	return Index == -1;
}
int& ReverseIterator::getSize()
{
	return Size;
}
int ReverseIterator::getIndex()
{
	return Index;
}
