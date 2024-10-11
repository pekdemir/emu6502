cmake_minimum_required(VERSION 3.5.0)
project(emu6502 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)


file(GLOB emu6502_cpp_src
    "*.cpp"
)


add_executable(emu6502 ${emu6502_cpp_src})

