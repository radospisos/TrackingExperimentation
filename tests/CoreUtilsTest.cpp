//
// Created by Rodion Shyshkin on 29.04.2022.
//
#include <gtest/gtest.h>
#include <core/trackers/core_utils/core_utils.h>

class KCFTest : public ::testing::Test {

};

TEST_F(KCFTest, GetControllerExceptionCheck) {
    cv::Rect2d rect = cv::Rect2d(1, 2, 50, 60);
    double frameW = 100, frameH = 100;
    EXPECT_NO_THROW(core_utils::get_controller(rect, frameW, frameH));
}

TEST_F(KCFTest, GetControllerValuesCheck1) {
    cv::Rect2d rect = cv::Rect2d(1, 2, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_TRUE(controller.left());
    ASSERT_TRUE(controller.up());
    ASSERT_FALSE(controller.right());
    ASSERT_FALSE(controller.down());
}

TEST_F(KCFTest, GetControllerValuesCheck2) {
    cv::Rect2d rect = cv::Rect2d(30, 25, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_TRUE(controller.right());
    ASSERT_TRUE(controller.down());
    ASSERT_FALSE(controller.up());
    ASSERT_FALSE(controller.left());
}

TEST_F(KCFTest, GetControllerValuesCheck3) {
    cv::Rect2d rect = cv::Rect2d(1, 25, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_TRUE(controller.left());
    ASSERT_TRUE(controller.down());
    ASSERT_FALSE(controller.up());
    ASSERT_FALSE(controller.right());
}

TEST_F(KCFTest, GetControllerValuesCheck4) {
    cv::Rect2d rect = cv::Rect2d(30, 2, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_TRUE(controller.right());
    ASSERT_TRUE(controller.up());
    ASSERT_FALSE(controller.down());
    ASSERT_FALSE(controller.left());
}

TEST_F(KCFTest, GetControllerValuesCheck5) {
    cv::Rect2d rect = cv::Rect2d(25, 2, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_TRUE(controller.up());
    ASSERT_FALSE(controller.right());
    ASSERT_FALSE(controller.down());
    ASSERT_FALSE(controller.left());
}

TEST_F(KCFTest, GetControllerValuesCheck6) {
    cv::Rect2d rect = cv::Rect2d(25, 30, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_TRUE(controller.down());
    ASSERT_FALSE(controller.right());
    ASSERT_FALSE(controller.up());
    ASSERT_FALSE(controller.left());
}

TEST_F(KCFTest, GetControllerValuesCheck7) {
    cv::Rect2d rect = cv::Rect2d(1, 20, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_TRUE(controller.left());
    ASSERT_FALSE(controller.right());
    ASSERT_FALSE(controller.down());
    ASSERT_FALSE(controller.up());
}

TEST_F(KCFTest, GetControllerValuesCheck8) {
    cv::Rect2d rect = cv::Rect2d(30, 20, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_TRUE(controller.right());
    ASSERT_FALSE(controller.left());
    ASSERT_FALSE(controller.down());
    ASSERT_FALSE(controller.up());
}

TEST_F(KCFTest, GetControllerValuesCheck9) {
    cv::Rect2d rect = cv::Rect2d(25, 20, 50, 60);
    double frameW = 100, frameH = 100;
    auto controller = core_utils::get_controller(rect, frameW, frameH);
    ASSERT_FALSE(controller.right());
    ASSERT_FALSE(controller.left());
    ASSERT_FALSE(controller.down());
    ASSERT_FALSE(controller.up());
}