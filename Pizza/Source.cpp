#include<iostream>

using namespace std;

class Pizza {
public:
	virtual void CookPizza() const = 0;
};

class MilanPizza :public Pizza {
public:
	void CookPizza()  const override {
		cout << "Milan Pizza cooked." << endl;
	}
};
class GrekPizza :public Pizza {
public:
	void CookPizza()   const override {
		cout << "Grek Pizza cooked." << endl;
	}

};
class Souce {
public:
	virtual void CreateSouce() const = 0;
};
class MilanSauce :public Souce {
public:
	void CreateSouce() const  override {
		cout << "Milan souce prepared." << endl;
	}
};
class GrekSauce :public Souce {
public:
	void CreateSouce()  const override {
		cout << "Grek souce prepared." << endl;
	 }

};
class Factory {
public:
	virtual void CookPizza() const = 0;
	virtual void CreateSouce() const = 0;
};

class GrekFactory : public Factory {
public: 
	void CookPizza() const override {
		cout << "To Grek Pizza was added Grek Souce and after this pizza was baked on Grek Factory." << endl;
	}
	void CreateSouce() const override {
		cout << "Grek Souce was cooked on Grek Factory." << endl;
	}
};
class MilanFactory : public Factory {
public:
	void CookPizza() const override {
		cout << "To Milan Pizza was added Milan Souce and after this pizza was baked on Milan Factory." << endl;
	}
	void CreateSouce() const override {
		cout << "Milan Souce was cooked on Milan Factory." << endl;
	}
};

void main() {
	MilanPizza mp;
	MilanSauce ms;
	MilanFactory mf;
	mp.CookPizza();
	ms.CreateSouce();
	mf.CreateSouce();
	mf.CookPizza();
	cout << endl;

	GrekPizza gp;
	GrekSauce gs;
	GrekFactory gf;
	gp.CookPizza();
	gs.CreateSouce();
	gf.CreateSouce();
	gf.CookPizza();

}