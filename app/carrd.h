#ifndef CARRD_H
#define CARRD_H
#include "QString"
class Carrd
{
public:
    QString name_of_city;
    char color;
    int owner,price_of_city,rent_without_house,rent_with_1_house,rent_with_2_house,rent_with_3_house;
    int rent_with_hotel,cost_of_house,cost_of_hotel,mortgage_val;
    int type_of_rent;
    Carrd();
    void set_val(QString ,char ,int ,int ,int ,
                 int ,int ,int ,int ,
                 int ,int ,int);
};

#endif // CARRD_H
