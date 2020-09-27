cmake_minimum_required(VERSION 3.8)
project (boilerplate)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ZETA2D_SRC Source/Zeta2D)

add_library(zeta2d
  "${ZETA2D_SRC}/App.cpp"
  "${ZETA2D_SRC}/Entity/Entity.cpp"
  "${ZETA2D_SRC}/Entity/EntityManager.cpp"
  )
target_include_directories(zeta2d PUBLIC Source)
target_link_libraries(zeta2d PUBLIC
  lua5.3 SDL2 SDL2_image SDL2_ttf SDL2_mixer)

add_executable(00
  Source/Samples/00/Main.cpp
  )
target_include_directories(00 PUBLIC Source/Samples/00)
target_link_libraries(00 PRIVATE zeta2d)
