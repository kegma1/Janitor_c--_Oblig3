cmake_minimum_required(VERSION 3.5)

project(Oblig3_janitors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Oblig3_janitors main.cpp
    libs.h
    file_reader.h
    room_parser.h
)

include(GNUInstallDirs)
install(TARGETS Oblig3_janitors
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)