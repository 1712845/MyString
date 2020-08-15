#include "MyString.h"
MyString::MyString()
{
	str = new char[Size + 1];
	str= NULL ;
	Size = 0;
}
MyString::MyString(const char* src)
{
	Size = strlen(src);
	str = new char[Size + 1];
	strcpy(str, src);
	str[Size] = '\0';
}
MyString::~MyString()
{
	Size = 0;
	str = NULL;
	delete[] str;
}
int MyString::length()
{	
	int index = 0;
	while (str[index] != NULL)
	{
		index++;
	}
	return index;
}
bool MyString::Empty()
{
	return Size == 0;
}
MyString::operator const char *() const
{
	return str;
}
MyString::MyString(const MyString& copy)
{
	Size = copy.Size;
	str = new char[Size + 1];
	strcpy(str, copy.str);
}
MyString::MyString(int convert)             
{
	int temp = convert;
	int index = 0;
	do
	{
		temp /= 10;
		index++;
	} while (temp != 0);
	Size = index;
	str = new char[Size+1];
	do
	{
		str[index - 1] = char((convert % 10) + 48);
		convert /= 10;
		index--;
	} while (index > 0);
	str[Size] = '\0';
} 
MyString& MyString::operator=(const MyString& src)
{
	if (this != &src)
	{
		delete[] str;
		Size = strlen(src.str);
		str = new char[Size+1];
		for (int i = 0; i < src.Size; i++)
		{
			str[i] =src.str[i];
		}
		str[Size] = '\0';
	}
	return *this;
}
char* MyString::GetString()
{
	return str;
}
MyString& MyString::operator+(const MyString& src)
{
	*this+= src;
	return *this;
}
MyString& MyString::operator+(const char c)
{
	*this += c;
	return *this;
}
MyString& MyString::operator+(const char* src)
{
	*this += src;
	return *this;
}
MyString& MyString ::operator += (const MyString& src)
{
	if (Size != 0 && src.Size != 0)
	{
		char *temp = str;
		str = new char[Size + src.Size];
		for (int i = 0; i < Size; i++)
		{
			str[i] = temp[i];
		}
		
		for (int i = 0; i < src.Size; i++)
		{
			str[Size + i] = src.str[i];
		}
		str[Size + src.Size] = '\0';
		Size += src.Size;
		temp = NULL;
		delete[] temp;
		return *this;
	}
	else if (Size != 0 && src.Size == 0)
	{
		return *this;
	}
	else if (Size == 0 && src.Size != 0)
	{
		Size = src.Size;
		str = new char[src.Size + 1];
		for (int i = 0; i < src.Size; i++)
		{
			str[Size + i] = src.str[i];
		}
		str[Size + src.Size] = '\0';
		return *this;
	}
}
MyString& MyString ::operator += (const char* src)
{
	if (Size != 0 && strlen(src) != 0)
	{
		char *temp = str;
		str = new char[Size + strlen(src)];
		for (int i = 0; i < Size; i++)
		{
			str[i] = temp[i];
		}

		for (int i = 0; i < strlen(src); i++)
		{
			str[Size + i] = src[i];
		}
		str[Size + strlen(src)] = '\0';
		Size += strlen(src);
		temp = NULL;
		delete[] temp;
		return *this;
	}
	else if (Size != 0 && strlen(src) == 0)
	{
		return *this;
	}
	else if (Size == 0 && strlen(src) != 0)
	{
		Size = strlen(src);
		str = new char[strlen(src) + 1];
		for (int i = 0; i < strlen(src); i++)
		{
			str[Size + i] = src[i];
		}
		str[Size + strlen(src)] = '\0';
		return *this;
	}
}
MyString& MyString ::operator += (const char c)
{
	Size++;
	str = (char*)realloc(str, Size * sizeof(char));
	str[Size - 1] = c;
	str[Size] = '\0';
	return *this;
}
ostream& operator << (ostream& outdev, const MyString &s)
{
	if (s.Size != 0)
	{
		outdev << s.str;
		return outdev;
	}
	else
	{
		return outdev;
	}
}
bool operator < (const MyString& src1, const MyString &src2)
{

	return strcmp(src1.str, src2.str) < 0;
}
bool operator <= (const MyString& src1, const MyString &src2)
{
	return strcmp(src1.str, src2.str) <= 0;
}
bool operator == (const MyString& src1, const MyString &src2)
{
	return strcmp(src1.str, src2.str) == 0;
}
bool operator != (const MyString& src1, const MyString &src2)
{
	return strcmp(src1.str, src2.str) != 0;
}
bool operator > (const MyString& src1, const MyString &src2)
{
	return strcmp(src1.str, src2.str) > 0;
}
bool operator >= (const MyString& src1, const MyString &src2)
{
	return strcmp(src1.str, src2.str) >= 0;
}
char& MyString::operator[](unsigned int index)
{
	if (index < 0 || index > strlen(str))
	{
		cout << "Khong co gia tri tai vi tri: " << index<<endl;
	}
	return str[index];
}
MyString& MyString::insert(int index, const MyString& src)
{
	if (index <= Size - 1)
	{
		char* temp = new char[Size + src.Size];
		for (int i = 0; i < index; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i <src.Size; i++)
		{
			temp[i + index] = src.str[i];
		}
		for (int i = index + src.Size ; i < Size + src.Size; i++)
		{
			temp[i] = str[i - src.Size];
		}
		temp[Size + src.Size] = '\0';
		str = NULL;
		delete[]str;
		str = temp;
		Size = Size + src.Size;
	}
	else
	{
		char* temp = new char[Size + src.Size];
		for (int  i = 0; i < Size; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i < src.Size; i++)
		{
			temp[Size + i] = src.str[i];
		}
		temp[Size + src.Size] = '\0';
		str = NULL;
		delete[] str;
		str = temp;
		Size = Size + src.Size;
	}
	return *this;
}
MyString& MyString::insert(int pos, const MyString&src, int subpos, int length)
{
	if (pos <= Size - 1)
	{
		char* temp = new char[Size + length];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i < length; i++)
		{
			temp[i + pos] = src.str[i+subpos];
		}
		for (int i = pos + length; i < Size + length; i++)
		{
			temp[i] = str[i - length];
		}
		temp[Size + length] = '\0';
		str = NULL;
		delete[]str;
		str = temp;
		Size = Size + length;
	}
	else
	{
		char* temp = new char[Size + length];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i < length; i++)
		{
			temp[Size + i] = src.str[i+subpos];
		}
		temp[Size + length] = '\0';
		str = NULL;
		delete[] str;
		str = temp;
		Size = Size + length ;
	}
	return *this;
}
MyString& MyString::insert(int pos, const char* src)
{
	if (pos <= Size - 1)
	{
		char* temp = new char[Size + strlen(src)];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i < strlen(src); i++)
		{
			temp[i + pos] = src[i];
		}
		for (int i = pos + strlen(src); i < Size + strlen(src); i++)
		{
			temp[i] = str[i - strlen(src)];
		}
		temp[Size + strlen(src)] = '\0';
		str = NULL;
		delete[]str;
		str = temp;
		Size = Size + strlen(src);
	}
	else
	{
		char* temp = new char[Size + strlen(src)];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i < strlen(src); i++)
		{
			temp[Size + i] = src[i];
		}
		temp[Size + strlen(src)] = '\0';
		str = NULL;
		delete[] str;
		str = temp;
		Size = Size + strlen(src);
	}
	return *this;
}
MyString& MyString::insert(int pos, const char* src,int n)
{
	if (pos <= Size - 1)
	{
		char* temp = new char[Size + n];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i < n; i++)
		{
			temp[i + pos] = src[i];
		}
		for (int i = pos + n; i < Size + n; i++)
		{
			temp[i] = str[i - n];
		}
		temp[Size + n] = '\0';
		str = NULL;
		delete[]str;
		str = temp;
		Size = Size + n ;
	}
	else
	{
		char* temp = new char[Size + n];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i < n; i++)
		{
			temp[Size + i] = src[i];
		}
		temp[Size + n] = '\0';
		str = NULL;
		delete[] str;
		str = temp;
		Size = Size + n;
	}
	return *this;
}
MyString &MyString::insert(int pos, int n, char c)
{
	if (pos <= Size - 1)
	{
		char* temp = new char[Size + n];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i < n; i++)
		{
			temp[i + pos] = c;
		}
		for (int i = pos + n; i < Size + n; i++)
		{
			temp[i] = str[i - n];
		}
		temp[Size + n] = '\0';
		str = NULL;
		delete[]str;
		str = temp;
		Size = Size + n;
	}
	else
	{
		char* temp = new char[Size + n];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = str[i];
		}
		for (int i = 0; i < n; i++)
		{
			temp[Size + i] = c;
		}
		temp[Size + n] = '\0';
		str = NULL;
		delete[] str;
		str = temp;
		Size = Size + n ;
	}
	return *this;
}
MyString::iterator MyString::insert(iterator p, char c)
{
	insert(p.getIndex(), 1, c);
	p.getSize()++;
	iterator i = begin();
	return i;
}
void MyString::insert(iterator p, int n, char c)
{
	insert(p.getIndex(), n, c);
	p.getSize()++;
}
void MyString::insert(iterator p, iterator first, iterator last)
{
	int j = 0;
	for (iterator i = first; i != last; i++)
	{
		insert(p.getIndex()+j, 1, *i);
		j++;
		p.getSize()++;
	}
}
MyString& MyString::clear()
{
	str = NULL;
	delete[] str;
	Size = 0;
	return *this;
}
long long int MyString::max_size()
{
	return pow(2,32)-1 ;
}
MyString& MyString::resize(int n,char c)
{
	if (n < Size)
	{
		Size = n;
		str[Size] = '\0';
	}
	else if(n > Size)
	{
		char* temp = new char[n];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = str[i];
		}
		for (int i = Size; i < n; i++)
		{
			temp[i] = c;
		}
		temp[n] = '\0';
		str = NULL;
		delete[] str;
		str = temp;
		Size = n;
	}
	return *this;
}
void MyString::swap(MyString& src)
{
	char* tempstr1 = new char[Size];
	char* tempstr2 = new char[src.Size];
	int tempSize1 = Size;
	int tempSize2 = src.Size;
	for (int i = 0; i < Size; i++)
	{
		tempstr1[i] = str[i];
	}
	tempstr1[Size] = '\0';
	for (int i = 0; i < src.Size; i++)
	{
		tempstr2[i] = src.str[i];
	}
	tempstr2[src.Size] = '\0';
	str = NULL; delete[] str;
	src.str = NULL; delete[] src.str;
	str = tempstr2;
	Size = tempSize2;
	src.str = tempstr1;
	src.Size = tempSize1;
}
int MyString::capacity()
{
	int i = 4;
	int capacity = pow(2,i)-1;
	if (Size < capacity)
	{
		return capacity;
	}
	else
	{
		while (Size > capacity)
		{
			i++;
			capacity = pow(2, i) - 1;
		}
		return capacity;
	}
}
char& MyString::at(int pos)
{
	return str[pos];
}
const char& MyString::at(int pos) const
{
	return str[pos];
}
char& MyString::back()
{
	if (Size != 0)
	{
		return str[Size - 1];
	}
}
const char& MyString::back() const
{
	if (Size != 0)
	{
		return str[Size - 1];
	}
}
const char& MyString::front() const
{
	if (Size != 0)
	{
		return str[0];
	}
}
char& MyString::front()
{
	if (Size != 0)
	{
		return str[0];
	}
}
int MyString::size()
{
	int index = 0;
	while (str[index] != NULL)
	{
		index++;
	}
	return index;
}
void MyString::push_back(char c)
{
	Size++;
	char *temp = new char[Size];
	for (int i = 0; i < Size; i++)
	{
		if (i != Size - 1)
		{
			temp[i] = str[i];
		}
		else temp[i] = c;
	}
	temp[Size] = '\0';
	str = NULL;
	delete[] str;
	str = temp;
}
void MyString::pop_back()
{
	Size--;
	str[Size] = '\0';
}
istream& operator >>(istream& indev,MyString& src)
{
	int maxsize = 1;
	int index = 0;
	char* Str = new char[maxsize];
	while (isspace(indev.peek()))
	{
		indev.ignore();
	}
	while ((!isspace(indev.peek())) && (!indev.eof()))
	{
		char* tempstring = new char[maxsize + 1];
		indev >> Str[index];
		for (int i = 0; i < maxsize; i++)
		{
			tempstring[i] = Str[i];
		}
		index++;
		maxsize++;
		delete[] Str;
		Str = tempstring;
	}

	Str[index] = '\0';
	src.str = NULL;
	delete[] src.str;
	src.str = Str;
	return indev;
}
istream& getline(istream& indev, MyString& src )
{
	int index = 0;
	int Strsize = 10;
	char* Str = new char[Strsize];

	do
	{
		if (!indev.eof())
		{
			if (index < Strsize - 1)
			{
				Str[index] = indev.get();
				index++;
			}
			else
			{
				Strsize++;
				char* temp = new char[Strsize];
				for (int i = 0; i < index; i++)
					temp[i] = Str[i];

				temp[index] = indev.get();
				index++;
				delete[] Str;
				Str = temp;
			}
		}
	} while ((indev.peek() != '\n') && (!indev.eof()));
	indev.ignore();
	Strsize = index + 1;
	Str[index] = '\0';
	src.str = NULL;
	delete[] src.str;
	src.str = Str;
	src.Size = Strsize;
	return indev;
}
istream& getline(istream& indev, MyString& src, char c)
{
	int index = 0;
	int Strsize = 10;
	char* Str = new char[Strsize];

	do
	{
		if (!indev.eof())
		{
			if (index < Strsize - 1)
			{
				Str[index] = indev.get();
				index++;
			}
			else
			{
				Strsize++;
				char* temp = new char[Strsize];
				for (int i = 0; i < index; i++)
					temp[i] = Str[i];

				temp[index] = indev.get();
				index++;
				delete[] Str;
				Str = temp;
			}
		}
	} while ((indev.peek() != c) && (!indev.eof()));
	indev.ignore();
	Strsize = index + 1;
	Str[index] = '\0';
	src.str = NULL;
	delete[] src.str;
	src.str = Str;
	src.Size = Strsize;
	return indev;
}
char*MyString::c_str()
{
	return str;
}
const char* MyString::data()
{
	return str;
}
void MyString::copy(char*& src, int length, int pos)
{
	src = new char[length];
	for (int i = 0; i < length; i++)
	{
		src[i] = str[pos+i];
	}
	src[length] = '\0';
}
MyString& MyString::append(const MyString& src)
{
	if (Size != 0)
	{
		*this += src;
		return *this;
	}
	else
	{
		*this = src;
		return *this;
	}
	
}
MyString& MyString::append(const MyString& src, int pos, int length)
{
	char* temp = new char[length];
	for (int i = 0; i < length; i++)
	{
		temp[i] = src.str[pos + i];
	}
	temp[length] = '\0';
	*this += temp;
	temp = NULL;
	delete[] temp;
	return *this;
}
MyString& MyString::append(const char* src)
{
	if (Size != 0)
	{
		str = NULL;
		delete[] str;
		Size = strlen(src);
		str = new char[Size];
		for (int i = 0; i < Size; i++)
		{
			str[i] = src[i];
		}
		str[Size] = '\0';
		return *this;
	}	
	else
	{
		Size = strlen(src);
		str = new char[Size];
		str = (char*)src;
		return *this;
	}
}
MyString& MyString::append(const char* src, int n)
{
	char* temp = new char[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = src[ i];
	}
	temp[n] = '\0';
	*this += temp;
	temp = NULL;
	delete[] temp;
	return *this;
}
MyString& MyString::append(int n, char c)
{
	
	char* temp = new char[Size+n];
	for (int i = 0; i < Size; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < n; i++)
	{
		temp[Size + i] = c;
	}
	Size = Size + n;
	temp[Size] = '\0';
	str = NULL;
	delete[] str;
	str = temp;
	return *this;
}
MyString& MyString::assign(const MyString& src)
{
	*this = src;
	return *this;
}
MyString& MyString::assign(const MyString& src, int pos, int length)
{
	
	char* temp = new char[length];
	for (int i = 0; i < length; i++)
	{
		temp[i] = src.str[pos+i];
	}
	temp[length] = '\0';
	str = NULL;
	delete[] str;
	str = temp;
	Size = length;
	return *this;
}
MyString& MyString::assign(const char* src)
{
	str = NULL;
	delete[] str;
	str = new char[strlen(src)];
	for (int i = 0;i < strlen(src); i++)
	{
		str[i] = src[i];
	}
	str[strlen(src)] = '\0';
	Size = strlen(src);
	return *this;
}
MyString& MyString::assign(const char*src, int n)
{
	str = NULL;
	delete[] str;
	str = new char[n];
	for (int i = 0; i < n; i++)
	{
		str[i] = src[i];
	}
	str[n] = '\0';
	Size = n;
	return *this;
}
MyString& MyString::assign(int n, char c)
{
	str = NULL;
	delete[] str;
	str = new char[n];
	for (int i = 0; i < n; i++)
	{
		str[i] = c;
	}
	str[n] = '\0';
	Size = n;
	return *this;
}
MyString& MyString::erase(int pos, int length)
{
	char *temp = new char[Size - length];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < Size-length-pos ; i++)
	{
		temp[pos+i] = str[pos + length + i];
	}
	temp[Size - length] = '\0';
	str = NULL;
	delete[] str;
	str = temp;
	Size = Size - length;
	return *this;
	// 0 1 2 3 4 5 6 7 8 9
	// A n h   u   u   e m
}
MyString& MyString::replace(int pos, int length, const MyString &src)
{
	int tempsize = src.Size + Size - length;
	char* temp = new char[tempsize];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < src.Size; i++)
	{
		temp[pos + i] = src.str[i];
	}
	for (int i = pos; i < Size - length; i++)
	{
		temp[i+src.Size] = str[i+length];
	}
	temp[tempsize] = '\0';
	str = NULL;
	delete[] str;
	str = temp;
	Size = tempsize;
	return *this;
}
MyString& MyString::replace(int pos, int length, const MyString &src, int subpos, int sublength)
{
	int tempsize = Size + sublength - length;
	char*temp = new char[tempsize];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < sublength; i++)
	{
		temp[pos + i] = src.str[subpos + i];
	}
	for (int i = pos; i < Size - length; i++)
	{
		temp[i + sublength] = str[i + length];
	}
	temp[tempsize] = '\0';
	str = NULL;
	delete[] str;
	str = temp;
	Size = tempsize;
	return *this;
}
MyString& MyString::replace(int pos, int length, const char* src)
{
	int tempsize = Size - length + strlen(src);
	char* temp = new char[tempsize];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < strlen(src); i++)
	{
		temp[pos + i] = src[i];
	}
	for (int i = pos; i < Size - length; i++)
	{
		temp[i + strlen(src)] = str[i + length];
	}
	temp[tempsize] = '\0';
	str = NULL;
	delete[] str;
	str = temp;
	Size = tempsize;
	return *this;
}
MyString& MyString::replace(int pos, int length, const char* src, int n)
{
	int tempsize = Size - length + n;
	char*temp = new char[tempsize];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < n; i++)
	{
		temp[pos + i] = src[i];
	}
	for (int i = pos; i < Size - length; i++)
	{
		temp[i + n] = str[i + length];
	}
	temp[tempsize] = '\0';
	str = NULL;
	delete[] str;
	str = temp;
	Size = tempsize;
	return *this;
}
MyString& MyString::replace(int pos, int length, int n, char c)
{
	int tempsize = Size - length + n;
	char* temp = new char[tempsize];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = str[i];
	}
	for (int i = 0; i < n; i++)
	{
		temp[pos + i] = c;
	}
	for (int i = pos; i < Size - length; i++)
	{
		temp[i + n] = str[i + length];
	}
	temp[tempsize] = '\0';
	str = NULL;
	delete[] str;
	str = temp;
	Size = tempsize;
	return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, const MyString& src)
{
	replace(i1.getIndex(), i2.getIndex() - i1.getIndex(), src);
	return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, const char* src)
{
	replace(i1.getIndex(), i2.getIndex() - i1.getIndex(), src);
	return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, const char* src,int n)
{
	replace(i1.getIndex(), i2.getIndex() - i1.getIndex(), src,n);
	return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, int n, char c)
{
	replace(i1.getIndex(), i2.getIndex() - i1.getIndex(), n,c);
	return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, iterator first, iterator last)
{
	MyString temp;
	int j = 0;
	for (iterator i = first; i != last; i++)
	{
		temp.push_back(static_cast<char>(*i));
	}
	replace(i1.getIndex(), i2.getIndex() - i1.getIndex(), temp, first.getIndex(), last.getIndex() - first.getIndex());;
	return *this;
}
const int MyString::find(const MyString& src)
{
	char* temp = new char[Size];
	int index = 0; 
	int i = 0;
	while (index <=Size)
	{
		while (str[index] == src.str[i] && src.str[i]!='\0')
		{
			temp[i] = str[index];
			index++;
			i++;
			
		}
		if (i != 0)
		{
			temp[i] = '\0';
			if (strcmp(temp, src.str) == 0)
			{
				return index - i;
			}
			else
			{
				i = 0;
			}
		}
		index++;
	}
	return -1;
}
const int MyString::find(const char*src)
{
	char* temp = new char[Size];
	int index = 0;
	int i = 0;
	while (index <= Size)
	{
		while (str[index] == src[i] && src[i] != '\0')
		{
			temp[i] = str[index];
			index++;
			i++;

		}
		if (i != 0)
		{
			temp[i] = '\0';
			if (strcmp(temp, src) == 0)
			{
				return index - i;
			}
			else
			{
				i = 0;
			}
		}
		index++;
	}
	return -1;
}
const int MyString::find(const char*src, int pos, int n)
{
	char* temp = new char[n];
	int i = 0;
	char* tempsrc = new char[n];
	for (int j = 0; j < n; j++)
	{
		tempsrc[j] = src[j];
	}
	tempsrc[n] = '\0';
	while (pos <= Size)
	{
		while (str[pos] == src[i] && i > 0)
		{
			temp[i] = str[pos];
			pos++;
			i++;

		}
		if (i != 0)
		{
			temp[i] = '\0';
			if (strcmp(temp, tempsrc) == 0)
			{
				return pos - i;
			}
			else
			{
				i = 0;
			}
		}
		pos++;
	}
	return -1;
}
const int MyString::find(char c)
{
	int index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
		{
			return index;
		}
		else index++;
	}
	return -1;
}
const int MyString::rfind(const MyString& src)
{
	char* temp = new char[Size];
	int index = Size;
	int i = src.Size;
	while (index >=0 )
	{
		while (str[index-1] == src.str[i-1] && i > 0)
		{
			temp[i-1] = str[index-1];
			index--;
			i--;

		}
		if (i == 0)
		{
			temp[src.Size] = '\0';
			if (strcmp(temp, src.str) == 0)
			{
				return index - i;
			}
			else
			{
				i = 0;
			}
		}
		index--;
	}
	return -1;
}
const int MyString::rfind(const char*src)
{
	char* temp = new char[Size];
	int index = Size;
	int i = strlen(src);
	while (index >= 0)
	{
		while (str[index - 1] == src[i - 1] && i > 0)
		{
			temp[i - 1] = str[index - 1];
			index--;
			i--;

		}
		if (i == 0)
		{
			temp[strlen(src)] = '\0';
			if (strcmp(temp, src) == 0)
			{
				return index - i;
			}
			else
			{
				i = 0;
			}
		}
		index--;
	}
	return -1;
}
const int MyString::rfind(const char* src, int pos, int n)
{
	char* temp = new char[n];
	int i = n;
	char* tempsrc = new char[n];
	for (int j = n; j >= 0; j--)
	{
		tempsrc[j-1] = src[j-1];
	}
	tempsrc[n] = '\0';
	while (pos >= 0)
	{
		while (str[pos] == src[i-1] && i <= n)
		{
			temp[i-1] = str[pos];
			pos--;
			i--;

		}
		if (i == 0)
		{
			temp[n] = '\0';
			if (strcmp(temp, tempsrc) == 0)
			{
				return pos - i +1;
			}
			else
			{
				i = 0;
			}
		}
		pos--;
	}
	return -1;
}
const int MyString::rfind(char c)
{
	int index = Size;
	while (index >=0)
	{
		if (str[index-1] == c)
		{
			return index-1;
		}
		else index--;
	}
	return -1;
}
MyString& MyString::substr(int pos, int length)
{
	char* temp = new char[length];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[pos+i];
	}
	temp[length] = '\0';
	str = NULL;
	delete[] str;
	str = temp;
	Size = length;
	return *this;
}
const int MyString::compare(const MyString& src)
{
	if (strcmp(str,src.str)==0)
	{
		return 0;
	}
	else return 1;
}
const int MyString::compare(int pos, int length,const MyString& src)
{
	char* temp = new char[length];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[pos+i];
	}
	temp[length] = '\0';
	if (strcmp(temp, src.str) == 0)
	{
		return 0;
	}
	else return 1;
}
const int MyString::compare(int pos, int length, const MyString& src, int subpos, int sublength)
{
	char* temp1 = new char[length];
	char* temp2 = new char[sublength];
	for (int i = 0; i < length; i++)
	{
		temp1[i] = str[pos + i];
	}
	temp1[length] = '\0';
	for (int i = 0; i < sublength; i++)
	{
		temp2[i] = src.str[subpos + i];
	}
	temp2[sublength] = '\0';
	if (strcmp(temp1, temp2) == 0)
	{
		return 0;
	}
	else return 1;
}
const int MyString::compare(const char* src)
{
	if (strcmp(str,src)==0)
	{
		return 0;
	}
	else return 1;
}
const int MyString::compare(int pos, int length, const char* src)
{
	char* temp = new char[length];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[pos + i];
	}
	temp[length] = '\0';
	if (strcmp(temp, src) == 0)
	{
		return 0;
	}
	else return 1;
}
const int MyString::compare(int pos, int length, const char* src, int n)
{
	char* temp1 = new char[length];
	char* temp2 = new char[n];
	for (int i = 0; i < length; i++)
	{
		temp1[i] = str[pos + i];
	}
	temp1[length] = '\0';
	for (int i = 0; i <n; i++)
	{
		temp2[i] = src[i];
	}
	temp2[n] = '\0';
	if (strcmp(temp1, temp2) == 0)
	{
		return 0;
	}
	else return 1;
}
const int MyString::find_first_of(const MyString& src)
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < src.Size; j++)
		{
			if (str[i] == src.str[j])
			{
				return i;
			}
		}
	}
	return -1;
}
const int MyString::find_first_of(const char* src)
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < strlen(src); j++)
		{
			if (str[i] == src[j])
			{
				return i;
			}
		}
	}
	return -1;
}
const int MyString::find_first_of(const char*src, int pos, int n)
{
	for (int i = pos; i < Size; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[i] == src[j])
			{
				return i;
			}
		}
	}
	return -1;
}
const int MyString::find_first_of(char c, int pos)
{
	for (int i = pos; i < Size; i++)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
}
const int MyString::find_last_of(const MyString& src)
{
	for (int i = Size - 1; i >= 0; i--)
	{
		for (int j = 0; j < src.Size; j++)
		{
			if (str[i] == src.str[j])
			{
				return i;
			}
		}
	}
	return -1;
}
const int MyString::find_last_of(const char* src)
{
	for (int i = Size - 1; i >= 0; i--)
	{
		for (int j = 0; j < strlen(src); j++)
		{
			if (str[i] == src[j])
			{
				return i;
			}
		}
	}
	return -1;
}
const int MyString::find_last_of(const char* src, int pos, int n)
{
	for (int i = Size - 1; i >= pos; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[i] == src[j])
			{
				return i;
			}
		}
	}
	return -1;
}
const int MyString::find_last_of(char c)
{
	for (int i = Size - 1; i >= 0; i--)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}
const int MyString::find_first_not_of(const MyString& src)
{
	int f = 0;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < src.Size; j++)
		{
			if (str[i] == src.str[j])
				f++;
		}
		if (f == 0) return i;
		f = 0;
	}
	return -1;
}
const int MyString::find_first_not_of(const char* src)
{
	int f = 0;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < strlen(src); j++)
		{
			if (str[i] == src[j])
				f++;
		}
		if (f == 0) return i;
		f = 0;
	}
	return -1;
}
const int MyString::find_first_not_of(const char* src, int pos, int n)
{
	int f = 0;
	for (int i = pos; i < Size; i++)
	{
		for (int j = 0; j <n; j++)
		{
			if (str[i] == src[j])
				f++;
		}
		if (f == 0) return i;
		f = 0;
	}
	return -1;
}
const int MyString::find_first_not_of(char c)
{
	int f = 0;
	for (int i = 0; i < Size; i++)
	{
		if (str[i] != c) return i;
	}
	return -1;
}
const int MyString::find_last_not_of(const MyString& src)
{
	int f = 0;
	for (int i = Size-1; i >=0 ; i--)
	{
		for (int j = 0; j < src.Size; j++)
		{
			if (str[i] == src.str[j])
				f++;
		}
		if (f == 0) return i;
		f = 0;
	}
	return -1;
}
const int MyString::find_last_not_of(const char* src)
{
	int f = 0;
	for (int i = Size - 1; i >= 0; i--)
	{
		for (int j = 0; j < strlen(src); j++)
		{
			if (str[i] == src[j])
				f++;
		}
		if (f == 0) return i;
		f = 0;
	}
	return -1;
}
const int MyString::find_last_not_of(const char* src,int pos,int n)
{
	int f = 0;
	for (int i = Size - 1; i >= pos; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[i] == src[j])
				f++;
		}
		if (f == 0) return i;
		f = 0;
	}
	return -1;
}
const int MyString::find_last_not_of(char c)
{
	int f = 0;
	for (int i = Size-1; i >=0 ; i--)
	{
		if (str[i] != c) return i;
	}
	return -1;
}
MyString::iterator MyString::begin()
{
	return {str,Size,0 };
}
MyString::iterator MyString::end()
{
	return {str,Size,Size};
}
MyString::reverse_iterator MyString::rbegin()
{
	return { str,Size,Size - 1 };
}
MyString::reverse_iterator MyString::rend()
{
	return { str,Size,-1 };
}
const MyString:: iterator MyString::cbegin()
{
	return { str,Size,0 };
}
const MyString::iterator MyString::cend()
{
	return { str,Size,Size };
}
const MyString::reverse_iterator MyString::crbegin()
{
	return { str,Size,Size - 1 };
}
const MyString::reverse_iterator MyString::crend()
{
	return { str,Size,-1 };
}
MyString& MyString::append(iterator first, iterator last)
{
	for (iterator i = first; i != last; i++)
	{
		push_back(static_cast<char>(*i));
	}
	return *this;
}
MyString& MyString::assign(iterator first, iterator last)
{
	clear();
	for (iterator i = first; i != last; i++)
	{
		push_back(static_cast<char>(*i));
	}
	return *this;
}
MyString& MyString::erase(iterator p)
{
	erase(p.getIndex(),1);
	return *this;
}
MyString& MyString::erase(iterator first, iterator last)
{
	erase(first.getIndex(), last.getIndex() - first.getIndex());
	return *this;
}
MyString& MyString::replace(iterator i1, iterator i2, reverse_iterator first, reverse_iterator last)
{
	MyString temp;
	int j = 0;
	for (reverse_iterator i = first; i != last; i++)
	{
		temp.push_back(static_cast<char>(*i));
	}
	replace(i1.getIndex(), i2.getIndex() - i1.getIndex(), temp, last.getIndex()+1, first.getIndex() - last.getIndex()+1);;
	return *this;
}
