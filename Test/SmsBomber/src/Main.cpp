#include <iostream>
#include <string>
#include "../lib/SmsBomber.h"


int main(){
	SmsBomber sms1;

  	sms1.setTo("Number");
    sms1.setFrom("+14158815646"); // Test number
    sms1.setBody("Не забывай дарить цветы! Лучшие цветы у нас в магазине: http://flowersacademyforyou.com/");

    for (int i = 0; i < 3; i++){

	    std::cout << "Massage is sanding..." << std::endl;
	    sms1.sendSMS(sms1.getTo(), sms1.getFrom(), sms1.getBody());
	    std::cout << "\nMassage is SAND!" << std::endl;
    }

	return 0;
};