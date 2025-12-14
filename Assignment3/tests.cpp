/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number three
*/

#include <gtest/gtest.h>
#include "Spark.h"
#include "Vehicle.h"
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"

TEST(CompositionTest, SparkCreation) {
    Spark spark(100, true, 60.5f);
    EXPECT_EQ(spark.getEnergyLevel(), 100);
    EXPECT_TRUE(spark.getIsActive());
}

TEST(AssociationTest, VehicleCreation) {
    Vehicle vehicle("Car", "Logan", 328);
    EXPECT_EQ(vehicle.getModel(), "Logan");
}

TEST(BaseClassTest, TransformerFieldsAndMethods) {
    Vehicle vehicle("Car", "Logan", 328);
    Transformer transformer("Ivan", "Green", 500, "Fisher", 1.0f, &vehicle);
    EXPECT_EQ(transformer.getName(), "Ivan");
    EXPECT_EQ(transformer.getEyeColor(), "Green");
    EXPECT_EQ(transformer.getAge(), 500);
    EXPECT_EQ(transformer.getRank(), "Fisher");
    EXPECT_FLOAT_EQ(transformer.getSize(), 1.0f);
    EXPECT_TRUE(transformer.attack());
    EXPECT_TRUE(transformer.transform());
    transformer.setName("Petro");
    EXPECT_EQ(transformer.getName(), "Petro");
}

TEST(CompositionInTransformerTest, SparkExists) {
    Vehicle vehicle("Truck", "Zil", 80);
    Transformer transformer("Muhamedjan", "Blue", 488, "Ordinary", 8.0f, &vehicle);
    Spark spark = transformer.getSpark();
    EXPECT_EQ(spark.getEnergyLevel(), 100);
}

TEST(AssociationInTransformerTest, VehiclePointer) {
    Vehicle vehicle("Car", "Lamborghini", 300);
    Transformer transformer("Vitaliy", "Blue", 21, "Arbitrageur", 2.0f, &vehicle);
    Vehicle newVehicle("Car", "Granta_sport", 380);
    transformer.setVehicle(&newVehicle);
    EXPECT_EQ(transformer.getVehicle()->getModel(), "Granta_sport");
}

TEST(InheritanceTest, AutobotCreation) {
    Vehicle vehicle("Truck", "Peterbilt", 120);
    Autobot autobot("Optimus", 1000, "Leader", 10.5f, &vehicle, 95, "Prime");
    EXPECT_EQ(autobot.getName(), "Optimus");
    EXPECT_EQ(autobot.getCourageLevel(), 95);
    EXPECT_EQ(autobot.getFaction(), "Prime");
    EXPECT_TRUE(autobot.protect());
}

TEST(InheritanceTest, DecepticonCreation) {
    Vehicle vehicle("Jet", "Kukuruznik", 2400);
    Decepticon decepticon("Megatron", 1500, "Leader", 11.0f, &vehicle, 99, "Cannon");
    EXPECT_EQ(decepticon.getName(), "Megatron");
    EXPECT_EQ(decepticon.getAggressionLevel(), 99);
    EXPECT_TRUE(decepticon.destroy());
}

TEST(InheritanceTest, DinobotCreation) {
    Vehicle vehicle("Dinosaur", "T-Rex", 40);
    Dinobot dinobot("Grimlock", 800, "Boss", 9.5f, &vehicle, 90, "T-Rex", false);
    EXPECT_EQ(dinobot.getName(), "Grimlock");
    EXPECT_EQ(dinobot.getRoarPower(), 90);
    EXPECT_TRUE(dinobot.roar());
}

TEST(LifecycleTest, ConstructorDestructor) {
    Vehicle vehicle("Car", "audi", 100);
    {Transformer transformer("Volodya", "Blue", 777, "Test", 1.87f, &vehicle);}
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}