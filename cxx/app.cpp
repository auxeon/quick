#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, char** argv) {
  std::cout << "Hello World\n";
  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit())
    return -1;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  /* add this before invoking opengl functions like glClear */
  /* glad needs to assign addresses to these functions */
  gladLoadGL();

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw triangle
    glBegin(GL_TRIANGLES);
      glColor3f(1.0, 0.0, 0.0); // Red color
      glVertex2f(0.0, 1.0);    // Top
      glColor3f(0.0, 1.0, 0.0); // Green color
      glVertex2f(-1.0, -1.0);  // Bottom-left
      glColor3f(0.0, 0.0, 1.0); // Blue color
      glVertex2f(1.0, -1.0);   // Bottom-right
    glEnd();

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return EXIT_SUCCESS;
}
