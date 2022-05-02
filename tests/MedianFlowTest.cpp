//
// Created by Rodion Shyshkin on 29.04.2022.
//

#include <gtest/gtest.h>
#include <core/trackers/medianflow.h>

class MedianFlowTest : public ::testing::Test {

};

TEST_F(MedianFlowTest, MFCreation) {
    EXPECT_NO_THROW(auto mf = MedianFlow());
}

TEST_F(MedianFlowTest, MFinitialization) {
    auto mf = MedianFlow();
    cv::Rect2d rect = cv::Rect2d(1, 1, 600, 500);
    cv::Mat frame = cv::Mat(300, 400, CV_64F);
    EXPECT_THROW(mf.init(rect, cv::Mat(400, 300, CV_64F)), std::invalid_argument);
    EXPECT_THROW(mf.init(rect, cv::Mat(400, 602, CV_64F)), std::invalid_argument);
    EXPECT_THROW(mf.init(rect, cv::Mat(502, 300, CV_64F)), std::invalid_argument);
    EXPECT_NO_THROW(mf.init(rect, cv::Mat(502, 602, CV_64F)));
}

TEST_F(MedianFlowTest, MFupdating) {
    auto mf = MedianFlow();
    cv::Rect2d rect = cv::Rect2d(1, 1, 600, 500);
    cv::Mat frame = cv::Mat(800, 900, CV_64FC1);
    mf.init(rect, frame);
}