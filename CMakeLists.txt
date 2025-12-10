cmake_minimum_required(VERSION 4.0)
project(Prg_1)

set(CMAKE_CXX_STANDARD 26)

# Percorso alla cartella principale di wxWidgets
set(wxWidgets_ROOT_DIR "C:/Users/andre/Downloads/wxWidgets-3.3.1")
set(wxWidgets_LIB_DIR "${wxWidgets_ROOT_DIR}/lib/gcc_lib")
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})


add_executable(Prg_1 main.cpp
        Subject.h
        Observer.h
        Model.h
        View.h
        Controller.h
        "${wxWidgets_ROOT_DIR}/include/wx/msw/wx.rc")

target_link_libraries(Prg_1 ${wxWidgets_LIBRARIES})