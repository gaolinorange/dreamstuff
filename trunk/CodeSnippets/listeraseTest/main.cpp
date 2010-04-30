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
#include <list>
#include <stdio.h>

int main(int argc, char *argv[])
{
  std::list<int> data;
  for( int i = 0; i < 10; i++ ){
    data.push_back( i );
  }

  //search and erase
  std::list<int>::iterator pSearch;
  for (std::list<int>::iterator pData = data.begin(  );
       pData != data.end(  ); pData++) {
    pSearch = pData;
    pSearch++;
    for( ; pSearch != data.end(  );  ){
      if( ( *pSearch )-( *pData ) == 2 )
        pSearch = data.erase( pSearch );
      else
        pSearch++;
    }
  }

  //print the result
  for( std::list<int>::iterator pData = data.begin(  );
       pData != data.end(  ); pData++) {
    printf( "%d\n",*pData );
  }
  return 0;
}

//  
// 
// main.cpp ends here
