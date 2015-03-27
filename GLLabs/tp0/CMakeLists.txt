### Creating an executable
add_executable(glfwMinimal glfwMinimal.cpp game.cpp gameObject.cpp gameSphere.cpp gameTorus.cpp stage.cpp error.cpp textures.cpp camera.cpp light.cpp)
target_link_libraries(glfwMinimal utils ${GL_LIBRARIES} ${APPLE_FRAMEWORKS} ${GLFW3_STATIC_LIBRARIES} ${ASSIMP_LIBRARIES})
