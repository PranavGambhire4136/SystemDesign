#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include "../model/Restaurant.h"

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std; 

class RestaurantManager {
private:
    vector<Restaurant*> restaurants;
    static RestaurantManager* instance;

    RestaurantManager() {}; //private constructor as it is a singleton class;

public:
    static RestaurantManager* getInstance() {
        if (!instance) { 
            instance = new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* res) {
        restaurants.push_back(res);
    }

    vector<Restaurant*> searchByLocation(string location) {
        vector<Restaurant*> result;


        transform(location.begin(), location.end(), location.begin(), ::tolower);
        for (auto r : restaurants) {
            string rl = r->getLocation();
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
            if (rl == location) {
                result.push_back(r);
            }
        }

        return result;
    }

};

RestaurantManager* RestaurantManager::instance = nullptr;

#endif