#include <gtest/gtest.h>
#include <Class.h>



TEST(Cassini, Positive){
    Cassini l;
    l.set_parameters(34.65, 67.8);
    EXPECT_EQ(l.get_square_root(),34.65);
    EXPECT_NE(l.get_square_root(), 6.8);
    EXPECT_EQ(l.get_half_dist(),67.8);
    EXPECT_NE(l.get_half_dist(), 0.5);
};

TEST(Cassini_dist, Positive){
    Cassini l;
    l.set_parameters(1, 0.96);

    EXPECT_NEAR(find_dist(30,l),1.03116, 3);


    l.set_parameters(1, 1.17);
    EXPECT_NEAR(find_dist(15,l),1.38368,3);

};

//TEST(Cassini_dist, Negative){
//    Cassini l;
//    l.set_parameters(1, 0.96);
//
//    EXPECT_NEAR(l.find_dist(10),0.03116, 3);
//
//
//    l.set_parameters(1, 1.17);
//    EXPECT_NEAR(l.find_dist(50),1.38368,3);
//
//};

TEST(Cassini_R, Positive){
    Cassini l;
    l.set_parameters(1, 0.96);

    EXPECT_NEAR(print_R(15,l),0.522723, 3);


    l.set_parameters(1, 1.17);
    EXPECT_NEAR(print_R(15,l),0.4262,3);

};


TEST(Cassini_point, Positive){
    Cassini l;
    l.set_parameters(1, 0.96);

    EXPECT_NEAR(inflect_point(l),0.334734, 3);

};



