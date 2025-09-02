#include <cstddef>
#include <gtest/gtest.h>
#include <miniaudio.h>

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
