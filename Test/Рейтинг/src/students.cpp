#include "../lib/students.h"
#include <algorithm>

Students::Students(std::string name, float mtiu, float os, float ppsu, float avp1,
                   float ptc1, float psa, float avp2, float km, float ls, float ptc2)
    : name(name), Modeluvanna_ta_identificatia_obyectiv_upr(mtiu), Obrpbka_sugnaliv(os),
      Proyectuvanna_prustroiv_system_uprl(ppsu), AVP1(avp1),
      Progr_ta_nalagodzhenna_controllerov1(ptc1), Proyectuvanna_system_avtomatuku(psa),
      AVP2(avp2), Komp_merezhi(km), Localny_sustemu(ls), 
      Progr_ta_nalagodzhenna_controllerov2(ptc2), reyting(0.0f) {}

Students::~Students() {}

void Students::calculateRating() {
    reyting = (Modeluvanna_ta_identificatia_obyectiv_upr + Obrpbka_sugnaliv +
               Proyectuvanna_prustroiv_system_uprl + AVP1 +
               Progr_ta_nalagodzhenna_controllerov1 + Proyectuvanna_system_avtomatuku +
               AVP2 + Komp_merezhi + Localny_sustemu +
               Progr_ta_nalagodzhenna_controllerov2) / 10.0f;
}

float Students::getRating() const {
    return reyting;
}

std::string Students::getName() const {
    return name;
}

void Students::sortAndDisplay(std::vector<Students>& students) {
    std::sort(students.begin(), students.end(), [](const Students& a, const Students& b) {
        return a.getRating() > b.getRating();
    });

    for (const auto& student : students) {
        std::cout << "Student: " << student.getName()
                  << " | Rating: " << student.getRating() << "\n";
    }
}
