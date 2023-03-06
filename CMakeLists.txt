cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include_directories(include)

add_executable(main
  main.cpp
  include/Player.h
  include/Entity.h
  include/Game.h
)


find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(main PRIVATE sfml-system sfml-network sfml-graphics sfml-window)