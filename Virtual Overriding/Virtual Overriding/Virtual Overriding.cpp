using namespace std;


class ShoppingItem {
protected:
	int antal;
	int pris;
public:
	ShoppingItem() { }
	ShoppingItem(int antal, int pris) {
		this->antal = antal;
		this->pris = pris;
	}
	~ShoppingItem() {}
	void Add(int x) {
		antal = x + antal;
	}
	int getTotal() {
		int tot = antal * pris;
		return tot;
	}

};

class ShoppingList {
protected:
	vector<ShoppingItem*> items;
	int tot = 0;
public:
	ShoppingList() : items() { }
	ShoppingList(ShoppingList& copy) : items(copy.items) { }
	~ShoppingList() {
		items.clear();
	}
	void Add(ShoppingItem* objectsToBeAdded) {
		items.push_back(objectsToBeAdded);
	}
	int getTot() {
		for each (ShoppingItem * object in items) {
			tot = tot + object->getTotal();
		}
		return tot;
	}
	static void Reset(ShoppingList* temp) {
		temp->items.clear();
		temp->tot = 0;
	}
};

int main() {
	ShoppingItem* item1 = new ShoppingItem(2, 735);
	ShoppingItem* item2 = new ShoppingItem(1, 399);
	ShoppingItem* item3 = new ShoppingItem(4, 500);

	item1->Add(3);
	cout << item1->getTotal() << endl << endl;
	item2->Add(5);
	cout << item2->getTotal() << endl << endl;
	item3->Add(8);
	cout << item3->getTotal() << endl << endl;

	ShoppingList* list = new ShoppingList();
	list->Add(item1);
	list->Add(item2);
	list->Add(item3);

	cout << list->getTot();

	ShoppingList temp(*list);
	ShoppingList::Reset(list);
	return 0;
}

#include <iostream>

using namespace std;

class Rational
{
public:
	float num;
	int arr[10];
	Rational()
	{
		arr[0] = 10;
		arr[1] = 12;
	}
	Rational() {}
	Rational(float a)
	{
		num = a;
	}
	~Rational() {}
	Rational operator +(Rational& get)
	{
		num = num + get.num;
		return *this;
	}
	Rational operator -(Rational& get)
	{
		num = num - get.num;
		return *this;
	}
	Rational operator * (Rational& get)
	{
		num = num * get.num;
		return *this;
	}
	Rational operator / (Rational& get)
	{
		num = num / get.num;
		return *this;
	}
	bool operator <(const Rational& get)
	{
		num < get.num;
		return this;
	}
	int& operator[](int i)
	{
		return arr[i];
	}
	friend ostream& operator <<(ostream& os, Rational& get)
	{
		os << get.arr;
		return os;
	}
};

int main()
{
	Rational a(10);
	Rational b(21);
	Rational sum;
	sum = a + b;
	cout << "10 + 21 = " << sum.num << endl << endl;

	Rational c(89);
	Rational d(43);
	Rational substract;
	substract = c - d;
	cout << "89 - 43 = " << substract.num << endl << endl;

	Rational e(6);
	Rational f(7);
	Rational multiply;
	multiply = e * f;
	cout << "6 * 7 = " << multiply.num << endl << endl;

	Rational g(72);
	Rational h(8);
	Rational divide;
	divide = g / h;
	cout << "72 / 8 = " << divide.num << endl << endl;

	Rational j(29);
	Rational k(30);

	if (j < k)
		cout << "j:" << j.num << " is less than k = " << k.num << endl << endl;
	else
		cout << "k:" << k.num << " is less than j = " << j.num << endl << endl;

	Rational ar;
	cout << ar[0] << " < " << ar[1] << endl << endl;

	cout << endl;
	system("pause");

	return 0;
}