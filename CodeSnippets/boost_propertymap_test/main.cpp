//#include <boost/property_map.hpp>
#include <string>
#include <iostream>
#include <map>
#include <boost/property_map.hpp>
using namespace boost;

#include "TestGraph.h"

int main()
{
  TestGraph* g = new TestGraph();

  typedef std::map<int,float> IdValueMap;
  IdValueMap idValues;

  boost::associative_property_map<IdValueMap> idValuePropertyMap(idValues);

   idValues.insert(std::make_pair(1,1.0f));
   idValues.insert(std::make_pair(2,2.0f));

   float old_value,new_value;

   old_value = boost::get(idValuePropertyMap,1);
   std::cout<<"old_value is : "<<old_value<<std::endl;

   new_value = 30.0f;
   boost::put(idValuePropertyMap,1,new_value);

   for(std::map<int,float>::iterator i = idValues.begin();
       i != idValues.end(); i++){
     std::cout<<i->first<<": "<<i->second<<std::endl;
   }
  

  return 0;
}

