#!/bin/sh
#
# build_and_run_test.sh --- a convience script for build the project and run the test during development
#
# copyright (c) 2010 dreamway
# 
#  This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by the Free Software Foundation;
#  Free free to contact dreamway(jingwenlai@163.com)
# 
# website: cg.xplore.cn
# 
# 



if [ ! -d "build" ]; then
	echo "build directory did not exists, create one...";
	mkdir build;  
fi

echo "cd build...";
cd build;
echo "running cmake...";
cmake ..;
echo "running make...";
make;
echo "running bin/test...";
bin/test;


# 
# build_and_run_test.sh ends here
