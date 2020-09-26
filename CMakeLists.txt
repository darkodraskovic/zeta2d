cmake_minimum_required(VERSION 3.8)
project (boilerplate)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ZETA2D_SRC src/zeta2d)

add_library(zeta2d
  "${ZETA2D_SRC}/app.cpp"
  "${ZETA2D_SRC}/entity/entity.cpp"
  "${ZETA2D_SRC}/entity/entity_manager.cpp"
  )
target_include_directories(zeta2d PUBLIC src)
target_link_libraries(zeta2d PUBLIC
  lua5.3 SDL2 SDL2_image SDL2_ttf SDL2_mixer)

add_executable(00
  src/samples/00/main.cpp
  # src/samples/00/app.cpp
  )
target_include_directories(00 PUBLIC src/samples/00)
target_link_libraries(00 PRIVATE zeta2d)
