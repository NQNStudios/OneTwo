project(${PROJECT_NAME})

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

file(GLOB SOURCES *.cpp)

add_library(source ${SOURCES})
target_link_libraries(source ${SDL2_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
