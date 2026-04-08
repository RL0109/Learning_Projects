cmake_minimum_required(VERSION 3.16)
project(Pong)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendored/SDL_image)
add_subdirectory(vendored/SDL_ttf)
file (GLOB SRC_FILES *.cpp)

# Create your game executable target as usual
add_executable(Pong ${SRC_FILES})

target_include_directories(Pong PRIVATE 
    vendored/SDL/include
    vendored/SDL_image/include
    vendored/SDL_ttf/include        
)   

# Link to the actual SDL3 library.
target_link_libraries(Pong PRIVATE SDL3::SDL3 SDL3_image-shared SDL3_ttf-shared)
