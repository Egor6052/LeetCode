#pragma once
#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
#include <string>
#include <vector> 

class Students{
private:
    std::string name;
    float reyting;

    float Modeluvanna_ta_identificatia_obyectiv_upr;
    float Obrpbka_sugnaliv;
    float Proyectuvanna_prustroiv_system_uprl;
    float AVP1;
    float Progr_ta_nalagodzhenna_controllerov1;
    float Proyectuvanna_system_avtomatuku;
    float AVP2;
    float Komp_merezhi;
    float Localny_sustemu;
    float Progr_ta_nalagodzhenna_controllerov2;

public:
	 Students(std::string name, float mtiu, float os, float ppsu, float avp1,
             float ptc1, float psa, float avp2, float km, float ls, float ptc2);
    ~Students();

    void calculateRating();
    float getRating() const;
    std::string getName() const;

    static void sortAndDisplay(std::vector<Students>& students);

};

#endif