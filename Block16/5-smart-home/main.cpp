#include <iostream>
#include <sstream>

enum switches
{
    HOUSE_MAIN_POWER = 1,
    HOUSE_OUTLETS = 2,
    HOUSE_LIGHTS = 4,
    GARDEN_LIGHTS = 8,
    HOUSE_HEATING = 16,
    WATER_HEATING = 32,
    AIR_CONDITIONER = 64
};


int main() {

    int switchesStatus = 0;
    int time = 0;
    int colorTemperature = 5000;

    switchesStatus |= HOUSE_MAIN_POWER;
    switchesStatus |= HOUSE_OUTLETS;


    for (int i = 0; i < 2; ++i) {

        time = 15;
        colorTemperature = 5000;

        while (time < 24) {

            int tempOut, tempIn;
            bool motionOut, lightsIn;

            std::string input;
            std::stringstream stream;

            std::cout << "Order(int int bool bool): <tempOut> <tempIn> <motionOut> <lightsIn>" << std::endl;
            std::cout << "Current sensors states:" << std::endl;
            std::getline(std::cin, input);

            stream << input;
            stream >> tempOut >> tempIn >> motionOut >> lightsIn;

            /*

            std::cout << "------\n" << "TIME: " << time << ":00" << "\n------" << std::endl;
            
            std::cout << "Sensors status: " << "\n" << std::endl;
            std::cout << "TEMPERATURE OUTSIDE = " << tempOut << std::endl;
            std::cout << "TEMPERATURE INSIDE = " << tempIn << std::endl;
            std::cout << "MOTION OUTSIDE = ";
            if (motionOut) std::cout << "Yes" << std::endl;
            else std::cout << "No" << std::endl;
            std::cout << "LIGHTS INSIDE = ";
            if (lightsIn) std::cout << "Yes" << std::endl;
            else std::cout << "No" << std::endl;
            if (lightsIn) std::cout << "LIGHT COLOR TEMPERATURE = " << colorTemperature << std::endl;
            std::cout << "------" << std::endl;
             */

            std::cout << "Events:\n" << std::endl;

            if (lightsIn && !(switchesStatus & HOUSE_LIGHTS)) {
                switchesStatus |= HOUSE_LIGHTS;
                std::cout << "LIGHTS INSIDE TURNED ON" << std::endl;
            }
            if (!lightsIn && (switchesStatus & HOUSE_LIGHTS)) {
                switchesStatus &= (~HOUSE_LIGHTS);
                std::cout << "LIGHTS INSIDE TURNED OFF" << std::endl;
            }

            if ((time >= 16 && time <= 20) && (switchesStatus & HOUSE_LIGHTS)) {
                colorTemperature = 5000 - ((2300 / 4) * (time - 16));
                //std::cout << "NEW LIGHT TEMPERATURE: " << colorTemperature << std::endl;
            }

            if (switchesStatus & HOUSE_LIGHTS) {
                std::cout << "LIGHT COLOR TEMPERATURE = " << colorTemperature << std::endl;
            }

            if (motionOut && !(switchesStatus & GARDEN_LIGHTS) && (time > 16 || time < 5)) {
                switchesStatus |= GARDEN_LIGHTS;
                std::cout << "GARDEN LIGHTS TURNED ON" << std::endl;
            }

            if ((!motionOut || (time < 16 && time > 5)) && (switchesStatus & GARDEN_LIGHTS)) {
                switchesStatus &= (~GARDEN_LIGHTS);
                std::cout << "GARDEN LIGHTS TURNED OFF" << std::endl;
            }

            if (tempOut < 0 && !(switchesStatus & WATER_HEATING)) {
                switchesStatus |= WATER_HEATING;
                std::cout << "WATER HEATING TURNED ON" << std::endl;
            }

            if (tempOut > 5 && (switchesStatus & WATER_HEATING)) {
                switchesStatus &= (~WATER_HEATING);
                std::cout << "WATER HEATING TURNED OFF" << std::endl;
            }

            if (tempIn < 22 && !(switchesStatus & HOUSE_HEATING)) {
                switchesStatus |= HOUSE_HEATING;
                std::cout << "HOUSE HEATING TURNED ON" << std::endl;
            }
            if (tempIn > 25 && (switchesStatus & HOUSE_HEATING)) {
                switchesStatus &= (~HOUSE_HEATING);
                std::cout << "HOUSE HEATING TURNED OFF" << std::endl;
            }

            if (tempIn > 30 && !(switchesStatus & AIR_CONDITIONER)) {
                switchesStatus |= AIR_CONDITIONER;
                std::cout << "AIR CONDITIONER TURNED ON" << std::endl;
            }

            if (tempIn < 26 && (switchesStatus & AIR_CONDITIONER)) {
                switchesStatus &= (~AIR_CONDITIONER);
                std::cout << "AIR CONDITIONER TURNED OFF" << std::endl;
            }

            std::cout << std::endl;

            /*
            std::cout << "------\n" << "Switches status:\n" << std::endl;

            if (switchesStatus & HOUSE_MAIN_POWER) std::cout << "MAIN POWER: ON" << std::endl;
            else std::cout << "MAIN POWER: OFF" << std::endl;
            if (switchesStatus & HOUSE_OUTLETS) std::cout << "HOUSE OUTLETS: ON" << std::endl;
            else std::cout << "HOUSE OUTLETS: OFF" << std::endl;
            
            if (switchesStatus & HOUSE_LIGHTS) std::cout << "HOUSE LIGHTS: ON" << std::endl;
            else std::cout << "HOUSE LIGHTS: OFF" << std::endl;

            if (switchesStatus & GARDEN_LIGHTS) std::cout << "GARDEN LIGHTS: ON" << std::endl;
            else std::cout << "GARDEN LIGHTS: OFF" << std::endl;

            if (switchesStatus & HOUSE_HEATING) std::cout << "HOUSE HEATING: ON" << std::endl;
            else std::cout << "HOUSE HEATING: OFF" << std::endl;

            if (switchesStatus & WATER_HEATING) std::cout << "WATER HEATING: ON" << std::endl;
            else std::cout << "WATER HEATING: OFF" << std::endl;

            if (switchesStatus & AIR_CONDITIONER) std::cout << "AIR CONDITIONER: ON" << std::endl;
            else std::cout << "AIR CONDITIONER: OFF" << std::endl;

            std::cout << "------" << std::endl;
             */

            ++time;

        }

    }

}
