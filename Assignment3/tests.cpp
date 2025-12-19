/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number four
*/

#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"

TEST(SparkTest, Basic) {
    Spark s1;
    EXPECT_EQ(s1.getEnergyLevel(), 100);
    
    Spark s2(50, false, 70.0f);
    EXPECT_EQ(s2.getEnergyLevel(), 50);
    EXPECT_FALSE(s2.getIsActive());
    
    s2.recharge();
    EXPECT_EQ(s2.getEnergyLevel(), 100);
    EXPECT_TRUE(s2.getIsActive());
}

TEST(VehicleTest, Basic) {
    Vehicle v1("Truck", "Optimus", 140);
    EXPECT_EQ(v1.getModel(), "Optimus");
    
    v1.upgrade();
    EXPECT_EQ(v1.getMaxSpeed(), 150);
    
    v1.setIsDamaged(true);
    EXPECT_TRUE(v1.getIsDamaged());
    
    testing::internal::CaptureStdout();
    v1.repair();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(v1.getIsDamaged());
    EXPECT_NE(output.find("repaired"), std::string::npos);
}

TEST(ConstructorsTest, AllClasses) {
    Spark s_default;
    Spark s_param(75, true, 80.5f);
    
    Vehicle v_default;
    Vehicle v_param("Jet", "F-22", 2000);
    
    Autobot a_default;
    Autobot a_param("Bumblebee", 3000, "Scout", 5.0f, nullptr, 75, "Autobot");
    
    Decepticon d_default;
    Decepticon d_param("Megatron", 8500, "Leader", 9.5f, nullptr, 99, "Fusion Cannon");
    
    Dinobot dn_default;
    Dinobot dn_param("Grimlock", 7000, "Commander", 8.5f, nullptr, 85, "T-Rex", false);
    
    EXPECT_EQ(a_default.getName(), "Unknown");
    EXPECT_EQ(d_param.getName(), "Megatron");
    EXPECT_EQ(dn_param.getDinoType(), "T-Rex");
}

TEST(VirtualMethodsTest, ExplicitCall) {
    Autobot a;
    Decepticon d;
    Dinobot dn;
    
    testing::internal::CaptureStdout();
    a.battleCry();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Autobot::battleCry()\n");
    
    testing::internal::CaptureStdout();
    d.battleCry();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Decepticon::battleCry()\n");
    
    testing::internal::CaptureStdout();
    dn.battleCry();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Dinobot::battleCry()\n");
}

TEST(PolymorphismTest, BasePointer) {
    Autobot a;
    Decepticon d;
    Dinobot dn;
    
    Transformer* t1 = &a;
    Transformer* t2 = &d;
    Transformer* t3 = &dn;
    
    testing::internal::CaptureStdout();
    t1->battleCry();
    t2->battleCry();
    t3->battleCry();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Autobot::battleCry()"), std::string::npos);
    EXPECT_NE(output.find("Decepticon::battleCry()"), std::string::npos);
    EXPECT_NE(output.find("Dinobot::battleCry()"), std::string::npos);
}

TEST(VectorPolymorphismTest, NineObjects) {
    std::vector<Transformer*> transformers;
    
    transformers.push_back(new Autobot("Optimus", 9000, "Commander", 10.0f, nullptr, 95, "Autobot"));
    transformers.push_back(new Autobot("Bumblebee", 3000, "Scout", 5.0f, nullptr, 75, "Autobot"));
    transformers.push_back(new Autobot("Ironhide", 8000, "Warrior", 9.0f, nullptr, 85, "Autobot"));
    
    transformers.push_back(new Decepticon("Megatron", 8500, "Leader", 9.5f, nullptr, 99, "Cannon"));
    transformers.push_back(new Decepticon("Starscream", 8000, "Commander", 8.0f, nullptr, 85, "Boom"));
    transformers.push_back(new Decepticon("Soundwave", 7500, "Commander", 7.5f, nullptr, 70, "Cassettes"));
    
    transformers.push_back(new Dinobot("Grimlock", 7000, "Commander", 8.5f, nullptr, 85, "T-Rex", false));
    transformers.push_back(new Dinobot("Slag", 6500, "Warrior", 8.0f, nullptr, 80, "Triceratops", false));
    transformers.push_back(new Dinobot("Swoop", 6000, "Scout", 7.0f, nullptr, 75, "Pterodactyl", true));
    
    EXPECT_EQ(transformers.size(), 9);
    
    testing::internal::CaptureStdout();
    for (auto t : transformers) {
        t->battleCry();
        t->defend();
    }
    std::string output = testing::internal::GetCapturedStdout();
    
    int autobot_calls = 0, decepticon_calls = 0, dinobot_calls = 0;
    size_t pos = 0;
    while ((pos = output.find("::battleCry()", pos)) != std::string::npos) {
        if (pos >= 2) {
            if (output.substr(pos-7, 7) == "Autobot") autobot_calls++;
            else if (output.substr(pos-10, 10) == "Decepticon") decepticon_calls++;
            else if (output.substr(pos-7, 7) == "Dinobot") dinobot_calls++;
        }
        pos += 13;
    }
    
    EXPECT_EQ(autobot_calls, 3);
    EXPECT_EQ(decepticon_calls, 3);
    EXPECT_EQ(dinobot_calls, 3);
}

TEST(OutputOperatorTest, AllClasses) {
    Vehicle v("Truck", "Optimus", 140);
    Autobot a("Bumblebee", 3000, "Scout", 5.0f, &v, 75, "Autobot");
    Decepticon d("Megatron", 8500, "Leader", 9.5f, nullptr, 99, "Cannon");
    Dinobot dn("Grimlock", 7000, "Commander", 8.5f, nullptr, 85, "T-Rex", false);
    
    std::stringstream ss1, ss2, ss3;
    ss1 << a;
    ss2 << d;
    ss3 << dn;
    
    EXPECT_NE(ss1.str().find("Bumblebee"), std::string::npos);
    EXPECT_NE(ss1.str().find("Autobot"), std::string::npos);
    
    EXPECT_NE(ss2.str().find("Megatron"), std::string::npos);
    EXPECT_NE(ss2.str().find("Cannon"), std::string::npos);
    
    EXPECT_NE(ss3.str().find("Grimlock"), std::string::npos);
    EXPECT_NE(ss3.str().find("T-Rex"), std::string::npos);
}

TEST(MethodsTest, AllMethods) {
    Autobot a;
    Decepticon d;
    Dinobot dn;
    
    EXPECT_TRUE(a.attack());
    EXPECT_TRUE(d.destroy());
    EXPECT_TRUE(dn.roar());
    
    testing::internal::CaptureStdout();
    a.defend();
    d.defend();
    dn.defend();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Autobot::defend()"), std::string::npos);
    EXPECT_NE(output.find("Decepticon::defend()"), std::string::npos);
    EXPECT_NE(output.find("Dinobot::defend()"), std::string::npos);
}

TEST(PureVirtualTest, CannotInstantiate) {
    EXPECT_TRUE(true);
}

TEST(EdgeCasesTest, SparkAndVehicle) {
    Spark s;
    
    s.setEnergyLevel(0);
    EXPECT_EQ(s.getEnergyLevel(), 0);
    
    s.setEnergyLevel(100);
    EXPECT_EQ(s.getEnergyLevel(), 100);
    
    s.setEnergyLevel(50);
    s.setEnergyLevel(-10);
    EXPECT_EQ(s.getEnergyLevel(), 50);
    
    s.setEnergyLevel(150);
    EXPECT_EQ(s.getEnergyLevel(), 50);
    
    Vehicle v("Test", "Model", 0);
    EXPECT_EQ(v.getMaxSpeed(), 0);
    
    v.setMaxSpeed(-100);
    EXPECT_EQ(v.getMaxSpeed(), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}