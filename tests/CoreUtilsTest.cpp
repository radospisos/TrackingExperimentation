//
// Created by Rodion Shyshkin on 29.04.2022.
//
#include <gtest/gtest.h>
#include <core/trackers/core_utils/core_utils.h>

class CoreUtilsTest : public ::testing::Test {

};

TEST_F(CoreUtilsTest, GetControllerExceptionCheck1) {
    cv::Rect2d rect = cv::Rect2d(1, 2, 50, 60);
    double frameW = 100, frameH = 100;
    EXPECT_NO_THROW(core_utils::get_controller(rect, frameW, frameH));
}

TEST_F(CoreUtilsTest, GetControllerExceptionCheck2) {
    cv::Rect2d rect = cv::Rect2d(1, 2, 110, 110);
    double frameW = 100, frameH = 100;
    EXPECT_THROW(core_utils::get_controller(rect, frameW, frameH), std::invalid_argument);
}

TEST_F(CoreUtilsTest, GetControllerValuesCheck1) {
    cv::Rect2d rect = cv::Rect2d(0, 0, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_EQ(controller.dx(), -25.0);
    ASSERT_EQ(controller.dy(), -20.0);
}

TEST_F(CoreUtilsTest, GetControllerValuesCheck2) {
    cv::Rect2d rect = cv::Rect2d(50, 40, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_EQ(controller.dx(), 25.0);
    ASSERT_EQ(controller.dy(), 20.0);
}

TEST_F(CoreUtilsTest, GetControllerValuesCheck3) {
    cv::Rect2d rect = cv::Rect2d(0, 40, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_EQ(controller.dx(), -25.0);
    ASSERT_EQ(controller.dy(), 20.0);
}

TEST_F(CoreUtilsTest, GetControllerValuesCheck4) {
    cv::Rect2d rect = cv::Rect2d(50, 0, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_EQ(controller.dx(), 25.0);
    ASSERT_EQ(controller.dy(), -20.0);
}

TEST_F(CoreUtilsTest, GetControllerValuesCheck5) {
    cv::Rect2d rect = cv::Rect2d(0, 20, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_EQ(controller.dx(), -25.0);
    ASSERT_EQ(controller.dy(), 0.0);
}

TEST_F(CoreUtilsTest, GetControllerValuesCheck6) {
    cv::Rect2d rect = cv::Rect2d(50, 20, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_EQ(controller.dx(), 25.0);
    ASSERT_EQ(controller.dy(), 0.0);
}

TEST_F(CoreUtilsTest, GetControllerValuesCheck7) {
    cv::Rect2d rect = cv::Rect2d(25, 0, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_EQ(controller.dx(), 0.0);
    ASSERT_EQ(controller.dy(), -20.0);
}
TEST_F(CoreUtilsTest, GetControllerValuesCheck8) {
    cv::Rect2d rect = cv::Rect2d(25, 40, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_EQ(controller.dx(), 0.0);
    ASSERT_EQ(controller.dy(), 20.0);
}

TEST_F(CoreUtilsTest, GetControllerValuesCheck9) {
    cv::Rect2d rect = cv::Rect2d(25, 20, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_EQ(controller.dx(), 0.0);
    ASSERT_EQ(controller.dy(), 0.0);
}