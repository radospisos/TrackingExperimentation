//
// Created by Rodion Shyshkin on 29.04.2022.
//
//
// Created by Rodion Shyshkin on 29.04.2022.
//
#include <gtest/gtest.h>
#include <core/result_structures/tracking_result.h>

class KCFTest : public ::testing::Test {

};

TEST_F(KCFTest, TrackingResultCreation) {
    /*CorrectionController controller = CorrectionController::create(false, false, false, false);
    cv::Rect2d rect2D = cv::Rect2d(1, 2, 10, 10);
    EXPECT_NO_THROW(auto result = TrackingResult::success(rect2D, controller));
    EXPECT_NO_THROW(auto result = TrackingResult::fail());*/
}

TEST_F(KCFTest, SuccessFieldAccess) {
    /*CorrectionController controller = CorrectionController::create(false, false, false, false);
    cv::Rect2d rect2D = cv::Rect2d(1, 2, 10, 10);
    auto result = TrackingResult::success(rect2D, controller);
    EXPECT_NO_THROW(auto controller = result.controller());
    EXPECT_NO_THROW(auto rect = result.bb());
    EXPECT_NO_THROW(auto up = result.up());
    EXPECT_NO_THROW(auto down = result.down());
    EXPECT_NO_THROW(auto left = result.left());
    EXPECT_NO_THROW(auto right = result.right());
    EXPECT_TRUE(result.success());*/
}

TEST_F(KCFTest, FailFieldAccess) {
    /*auto result = TrackingResult::fail();
    EXPECT_THROW(auto controller = result.controller(), std::domain_error);
    EXPECT_THROW(auto rect = result.bb(), std::domain_error);
    EXPECT_THROW(auto up = result.up(), std::domain_error);
    EXPECT_THROW(auto down = result.down(), std::domain_error);
    EXPECT_THROW(auto left = result.left(), std::domain_error);
    EXPECT_THROW(auto right = result.right(), std::domain_error);
    EXPECT_FALSE(result.success());*/
}