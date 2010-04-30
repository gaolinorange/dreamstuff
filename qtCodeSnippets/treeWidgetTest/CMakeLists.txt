project(treeWidgetTest)

cmake_minimum_required(VERSION 2.6)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

set(headers
  Ui_tree_widget_window.h
  TreeWidgetWindow.h
  )

set(sources
  main.cpp
  TreeWidgetWindow.cpp
  )

add_executable(treeWidgetTest ${sources} ${headers})
target_link_libraries(treeWidgetTest ${QT_LIBRARIES})
