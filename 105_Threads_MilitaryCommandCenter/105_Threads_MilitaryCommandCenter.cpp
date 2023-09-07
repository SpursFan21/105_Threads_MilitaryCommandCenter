#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex missileMutex;
std::mutex droneMutex;
std::mutex troopMutex;
std::mutex resourceMutex;

void MissileControlThread(int missileId) {
    // Lock the missile mutex to launch a missile
    std::unique_lock<std::mutex> lock(missileMutex);
    std::cout << "Missile " << missileId << " is launched.\n";

    // Simulate missile launch
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Release the missile mutex
    lock.unlock();
}

void DroneDeploymentThread(int droneId) {
    // Lock the drone mutex to deploy a drone
    std::unique_lock<std::mutex> lock(droneMutex);
    std::cout << "Drone " << droneId << " is deployed.\n";

    // Simulate drone deployment
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Release the drone mutex
    lock.unlock();
}

void TroopMovementThread(int troopId) {
    // Lock the troop mutex to coordinate troop movements
    std::unique_lock<std::mutex> lock(troopMutex);
    std::cout << "Troop " << troopId << " is moving.\n";

    // Simulate troop movement
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Release the troop mutex
    lock.unlock();
}

void ResourceAllocationThread() {
    // Lock the resource mutex to allocate resources
    std::unique_lock<std::mutex> lock(resourceMutex);
    std::cout << "Allocating resources (fuel and ammunition).\n";

    // Simulate resource allocation
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Release the resource mutex
    lock.unlock();
}

int main() {
    char choice;

    while (true) {
        std::cout << "Choose an operation:\n";
        std::cout << "1. Launch Missile\n";
        std::cout << "2. Deploy Drone\n";
        std::cout << "3. Move Troops\n";
        std::cout << "4. Allocate Resources\n";
        std::cout << "5. Exit\n";

        std::cin >> choice;

        switch (choice) {
        case '1':
            std::thread(MissileControlThread, 1).detach();
            break;
        case '2':
            std::thread(DroneDeploymentThread, 1).detach();
            break;
        case '3':
            std::thread(TroopMovementThread, 1).detach();
            break;
        case '4':
            std::thread(ResourceAllocationThread).detach();
            break;
        case '5':
            std::cout << "Exiting the program.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
