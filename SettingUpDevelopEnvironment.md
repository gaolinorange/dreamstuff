Showing how to setup the developing environment of i-mesh in ubuntu.

# Introduction #
Ubuntu is a good choice for development. Everything you need to do is using apt-get
to retrieve the latest development libraries and it can tweek your development procedure.
At any time, the [tab](tab.md) will be your friend.[tab](tab.md) can show the candidate list of the library
you want.

# Details #
i-mesh needs some supporting tools, these tools includes the mesh libraries, rendering libraries and so on.

### Compiling Tools ###
> GCC:
> > sudo apt-get install gcc

> cmake:
> > i-mesh use cmake to configure the project settings.using this command to get cmake.
> > > sudo apt-get install cmake
### Support Tools ###

> doxygen:
> > doxygen is used to generated the document of project
> > > sudo apt-get install doxygen

> > valgrind:
> > > valgrind is used to check the memory leaks in i-mesh
> > > > sudo apt-get install valgrind
### Development Libraries ###

> Qt4:
> > i-mesh use Qt as the fundamental UI Framework
> > > sudo apt-get install libqt4[tab](tab.md), than choose the libraries you want

> boost:
> > if you want to compiling cgal, you need to install boost libraries first.
> > > sudo apt-get install libboost[tab](tab.md), or just use 'sudo apt-get install libboost-dev'

> opengl:
> > i-mesh using opengl for showing 3d meshes
> > > sudo apt-get install libgl1-mesa-dev

> libQGLViewer:
> > QGLViewer is used to simplify the viewing of meshes.
> > sudo apt-get install libqglviewer-qt4-dev

> PythonQt:
> > PythonQt add the support of Python Scripting in the Qt4 application. You can
> > download PythonQt form pythonqt.sf.net, and then compile it. This step must do first
> > because when you install cgal later, the default behavior of Qt4 will replace with qt3,
> > so you can compile this package first. Currently, I am using PythonQt1.1

> assimp:
> > assimp is used to load the different types of meshes. you can download assimp
> > form assimp.sourceforge.net

> cgal:
> > cgal is the core library for mesh processing. as you can use this command to download and install it:
> > sudo apt-get install libcgal-dev
    * But **using this command will install the unwanted qt3 library, so I download the  source code from www.cgal.org, and then manually install it.
> > Follow the INSTALL file to install the auxilary libraries and cgal
> > instead of download from the website, you can use
> > sudo apt-get install libblas-dev
> > sudo apt-get install liblaplack-dev

> google test:
> > googletest is used to add some unittest for i-mesh
> > links: googletest.googlecode.com

> google mock:
> > currently google mock is not used in the source code of i-mesh, but maybe i will use it.
> > links : googlemock.googlecode.com

> google-glog:
> > I use google-glog to add some logging messages.
> > links: google-glog.googlecode.com**



