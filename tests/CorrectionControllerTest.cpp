//
// Created by Rodion Shyshkin on 29.04.2022.
//
#include <gtest/gtest.h>
#include <core/result_structures/correction_controller.h>

class CorrectionControllerTest : public ::testing::Test {

};

TEST_F(CorrectionControllerTest, ControllerCreation) {
    CorrectionController controller;
    EXPECT_NO_THROW(controller = CorrectionController(-1.0, -1.0));
    EXPECT_NO_THROW(controller = CorrectionController(-1.0, 0.0));
    EXPECT_NO_THROW(controller = CorrectionController(-1.0, 1.0));
    EXPECT_NO_THROW(controller = CorrectionController(0.0, -1.0));
    EXPECT_NO_THROW(controller = CorrectionController(0.0, 0.0));
    EXPECT_NO_THROW(controller = CorrectionController(0.0, 1.0));
    EXPECT_NO_THROW(controller = CorrectionController(1.0, -1.0));
    EXPECT_NO_THROW(controller = CorrectionController(1.0, 0.0));
    EXPECT_NO_THROW(controller = CorrectionController(1.0, 1.0));
}

TEST_F(CorrectionControllerTest, FieldAccess1) {
    CorrectionController controller;
    ASSERT_EQ(controller.dx(), 0.0);
    ASSERT_EQ(controller.dy(), 0.0);
}

TEST_F(CorrectionControllerTest, FieldAccess2) {
    CorrectionController controller{25.0, -27.0};
    ASSERT_EQ(controller.dx(), 25.0);
    ASSERT_EQ(controller.dy(), -27.0);
}