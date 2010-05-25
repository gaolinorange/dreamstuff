// main.cpp --- 
// copyright (c) 2010 dreamway
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free Software Foundation;
//  Feel free to contact dreamway(jingwenlai@163.com)
// 
// website: cg.xplore.cn
// 
// 

// Commentary: 
// 
//

#include <iostream>
#include <vector>
using namespace std;

class Component
{
 public:
  virtual ~Component() {
    cout<<"Component destructor"<<endl;    
  }
  virtual void traverse( ) = 0;
};

class Primitive : public Component
{
 public:
  Primitive(int val)
  {
    value = val;
  }
  virtual ~Primitive() {
    cout<<"Primitive destructor"<<endl;
  }
  void traverse(  ) {
    cout<<value<<" ";
  }
 private:
  int value;
};

class Composite : public Component
{
 public:
  Composite(int val) {
    value = val;
  }
  virtual ~Composite() {
    
  }
  void add( Component* c ) {
    children.push_back( c );
  }
  void traverse(  ) {
    cout<<value<<" ";
    for (int i = 0; i < children.size(  ); ++i) {
      children[ i ]->traverse(  );
    }
  }

 private:
  vector<Component*> children;
  int value;
};

class Row : public Composite
{
 public:
  Row(int val) : Composite( val ) {
    
  }
  virtual ~Row() {
    cout<<"Row destructor"<<endl;    
  }

  void traverse(  ) {
    cout<<"Row"; //base class
    Composite::traverse(  );
  }
};

class Column : public Composite
{
 public:
  Column(int val) : Composite( val ) {
    
  }
  virtual ~Column() {
    cout<<"Column destructor"<<endl;
  }
  
  void traverse(  ) {
    cout<<"Col";
    Composite::traverse(  );
  }
};


int main(int argc, char *argv[])
{
  Row first( 1);
  Column second( 2 );
  Column third( 3 );
  Row fourth( 4 );
  Row fifth( 5 );
  first.add( &second );
  first.add( &third );
  third.add( &fourth );
  third.add( &fifth );
  Primitive * p6 = new Primitive( 6 );
  Primitive* p7 = new Primitive( 7 );
  Primitive* p8 = new Primitive( 8);
  Primitive* p9 = new Primitive(9);
  Primitive* p10 = new Primitive(10);
  
  first.add( p6 );
  second.add( p7 );
  third.add( p8 );
  fourth.add( p9 );
  fifth.add( p10 );
  
  first.traverse(  );
  cout<<endl;
  
  return 0;
}

//  
// 
// main.cpp ends here
