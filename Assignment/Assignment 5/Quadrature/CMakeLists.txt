cmake_minimum_required(VERSION 3.15)
project(quadrature)

set(CMAKE_CXX_STANDARD 14)

add_executable(quadrature
        main.cpp
        Quadrature.cpp
        Quadrature.h
        LeftRiemann.cpp
        LeftRiemann.h RightRiemann.cpp RightRiemann.h Midpoint.cpp Midpoint.h Trapezoid.cpp Trapezoid.h Simpsons.cpp Simpsons.h)