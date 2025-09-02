#include <gtest/gtest.h>
#include <miniaudio.h>
#include <GLFW/glfw3.h>

TEST(test, 0) {
  ASSERT_EQ(true, true);
}

TEST(test_miniaudio, 0)
{
  ma_result result;
  ma_engine engine;

  result = ma_engine_init(NULL, &engine);
  if (result != MA_SUCCESS)
  {
    ASSERT_NE(result, MA_SUCCESS);
  }

  result = ma_engine_play_sound(&engine, "resources/alarm_beep.wav", NULL);
  ASSERT_EQ(result, MA_SUCCESS);
  printf("Press Enter to quit...");
  getchar();
  ma_engine_uninit(&engine);
}

TEST(test_glfw, 0)
{
  int status = 0;
  status = glfwInit();
  ASSERT_NE(status, 0);
  GLFWwindow *win = glfwCreateWindow(600, 600, "Hello World", NULL, NULL);
  if (!win)
    glfwTerminate();
  ASSERT_NE(win, nullptr);
  
  glfwMakeContextCurrent(win);
  while (!glfwWindowShouldClose(win))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(win);
    glfwPollEvents();
  }
  glfwTerminate();
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
