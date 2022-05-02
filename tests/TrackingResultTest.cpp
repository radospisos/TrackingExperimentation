//
// Created by Rodion Shyshkin on 29.04.2022.
//
//
// Created by Rodion Shyshkin on 29.04.2022.
//
#include <gtest/gtest.h>
#include <core/result_structures/tracking_result.h>

class TrackingResultTest : public ::testing::Test {

};

TEST_F(TrackingResultTest, TrackingResultCreation) {
    CorrectionController controller;
    cv::Rect2d rect2D = cv::Rect2d(1, 2, 10, 10);
    EXPECT_NO_THROW(auto result = TrackingResult::success(rect2D, controller));
    EXPECT_NO_THROW(auto result = TrackingResult::fail());
}

TEST_F(TrackingResultTest, SuccessFieldAccess) {
    CorrectionController controller;
    cv::Rect2d rect2D = cv::Rect2d(1, 2, 10, 10);
    auto result = TrackingResult::success(rect2D, controller);
    EXPECT_NO_THROW(auto controller = result.controller());
    EXPECT_NO_THROW(auto rect = result.bb());
    EXPECT_NO_THROW(auto up = result.dx());
    EXPECT_NO_THROW(auto down = result.dy());
    EXPECT_TRUE(result.success());
}

TEST_F(TrackingResultTest, FailFieldAccess) {
    auto result = TrackingResult::fail();
    EXPECT_THROW(auto controller = result.controller(), std::domain_error);
    EXPECT_THROW(auto rect = result.bb(), std::domain_error);
    EXPECT_THROW(auto up = result.dx(), std::domain_error);
    EXPECT_THROW(auto down = result.dy(), std::domain_error);
    EXPECT_FALSE(result.success());
}