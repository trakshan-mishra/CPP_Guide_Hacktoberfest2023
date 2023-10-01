// Function Overriding
#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
  void species()
  {
    cout << "It is an animal" << endl;
  }
};

class Dog : public Animal
{
public:
  // species function of Dog class overrides the species function of Animal class
  // the pointer to Dog class will print the species function of Dog class and not the Animal class
  void species()
  {
    cout << "It is a dog" << endl;
  }
  void sound()
  {
    cout << "Dogs Bark" << endl;
  }
};

int main()
{
  Animal a;
  a.species();
  Dog tommy;
  tommy.species();
  tommy.sound();
}