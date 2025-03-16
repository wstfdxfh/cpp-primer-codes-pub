#include <iostream>

using namespace std;

class ZooAnimal {
 public:
  virtual void print() { cout << "ZooAnimal" << endl; }
  double max_weight() const {
    cout << "Animal Max Weight:" << max_w << endl;
    return max_w;
  }

 private:
  double max_w = 100;
};

class Bear : virtual public ZooAnimal {
 public:
  void print() override { cout << "Bear" << endl; }
};

class Raccoon : virtual public ZooAnimal {
 public:
  void print() override { cout << "Raccoon" << endl; }
};

class Endangered {
 public:
  virtual void print() { cout << "Endangered" << endl; }
  double max_weight() const {
    cout << "Endangered Max Weight:" << max_w << endl;
    return max_w;
  }

 private:
  double max_w = 100;
};

class Panda : public Bear, public Raccoon, public Endangered {
 public:
  void print() { cout << "Panda" << endl; }
};

int main() {
  Panda pd;
  pd.print();
  ZooAnimal *animal = &pd, animal2 = pd;
  animal->print();
  animal2.print();
  // 防止二义性，可以通过派生类定义新版本，或者显式指定调用版本
  pd.ZooAnimal::max_weight();
  pd.Endangered::max_weight();
  return 0;
}