﻿#include"MyString.h"
int main()
{
	MyString Str = "Test tring";
	MyString Src = "I like Code";
	MyString B;
	MyString test;
	MyString A = "Test";
	B = Str;                 // Gán 
	cout << "Gan: ";
	cout << B << endl;
	B = B +  'a'; // phép cộng chuỗi
	cout << Src << endl;
	cout << "Cong chuoi: "<<B<<endl;
	Src += "++";         // phép cộng bằng
	cout << "Cong bang: " << Src << endl;
	Src.insert(4, "Love");  // chèn chuỗi Str vào vị trí thứ 4
	cout << "Da chen chuoi: " << Src << endl;;
	Str.insert(Str.begin(),4,'c');     // chèn 4 kí tự c vào đầu chuỗi
	cout << Str << endl;
	Str.clear();				// xóa chuỗi Str
	cout << Str << endl;
	Str.resize(4, 'P');  // Thay đổi kích thước Str và gán bằng 4 chữ P
	cout << Src.length() << endl;
	Str.swap(Src);				// Hóa đổi nội dung Src và Str
	cout <<"Str: "<<Str<<endl;  
	cout << "Src: " << Src << endl;
	cout << "Ki tu o vi tri thu 5 cua Str: " << Str.at(5) << endl;  // kí tự ở vị trí thứ 5 của Str
	cout << "Ki tu dau tien cua Str: " << Str.front() << endl;
	cout << "Ki tu cuoi cung cua Str: " << Str.back() << endl;
	Str.push_back('A');    // thêm kí tự A vào cuối chuỗi Str
	cout <<"Da them ki tu vao cuoi chuoi: "<<Str << endl;
	Str.pop_back();     // Xóa kí tự cuối chuỗi
	cout << "Da xoa ki tu cuoi chuoi: " << Str << endl;
	cout << "Xuat du lieu dang luu tru: "<<Str.data() << endl;
	cout << "Nhap chuoi : ";
	getline(cin, test);
	cout <<"Xuat chuoi vua nhap: "<< test << endl;
	cout << "Nhap chuoi an phim x de ket thuc: ";
	getline(cin, test, 'x');
	cout << "Xuat chuoi vua nhap: " << test << endl;
	A.append(" String ");      // copy nội dung chuỗi String vào chuỗi A
	cout << "A da duoc copy noi dung: " << A << endl;
	A.append("I live in HCM", 4);        // copy 4 kí tự đầu tiên của chuỗi vào A
	cout << "A da duoc copy: " << A << endl;
	A.assign("I am Ngoc Trung",4,6);    // copy 6 kí tự từ vị trí thứ 4 từ chuỗi vào A
	cout <<"A da duoc copy: "<<A << endl;
	A.erase(A.begin() + 3);         // xóa kí tự thứ 3 trong chuỗi A
	cout << "A da duoc xoa: " << A << endl;
	Str.replace(Str.begin() +4, Str.end()-3, A.begin() + 1, A.end());  // thay thế chuỗi Str từ vị trí thứ 4 đến vị trị cuối chuỗi -3
	// bằng chuỗi A từ vị trí 1 đến hết chuỗi
	cout << Str << endl;
	MyString C = "i want to become Developer and want to rich";
	MyString D = "want";
	cout << "Vi tri dau tien xuat hien ki tu b trong C la: " << C.find('b') << endl;
	cout << "Vi tri cuoi cung xuat hien ki tu e la: " << C.rfind('e') << endl;
	if (D.compare("want") == 0) cout << "Bang nhau" << endl; // So sánh nội dung chuỗi D và "want"
	if (D.compare(C) != 0) cout << "Khac Nhau " << endl; // so sánh D và C
	cout << "Vi tri dau tien xuat hien chuoi D trong C la:" << C.find_first_of(D) << endl;
	cout << "Vi tri dau tien cuoi cung chuoi D trong C la:" << C.find_last_of(D) << endl;
	MyString E = "auoie whi";
	cout << "Vi tri dau tien khac cac ki tu trong E la: " << C.find_first_not_of(E) << endl;
	cout << "Vi tri cuoi cung khac cac ki tu trong E la: " << C.find_last_not_of(E) << endl;
	cout << "Test iterator: ";
	for (MyString::iterator i = C.begin(); i != C.end(); i++)
	{
		cout << *i;
	}
	cout << endl;
	cout << "Test reverse iterator: ";
	for (MyString::reverse_iterator i = C.rbegin(); i != C.rend(); i++)
	{
		cout << *i;
	}
	cout << endl;
	cout <<"HOAN THANH" << endl;
	system("pause");
	return 0;
}                                                                                                                                                                                                                                                                                            