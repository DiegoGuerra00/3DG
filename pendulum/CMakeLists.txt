project(pendulum)
add_executable(${PROJECT_NAME} main.cpp window.cpp sphere.cpp line.cpp)
enable_abcg(${PROJECT_NAME})