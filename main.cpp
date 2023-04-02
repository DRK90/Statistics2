#include "class.hpp"

int main(){

    Event event1 = Event(.47);
    Event event2 = Event(.666666666);
    Event event3 = Event(1);

    //Testing & both events occuring
    event3.setProbability(event1 & event2);    
    std::cout<< event1.getProbability() << " & "<<event2.getProbability()<<" = "<< event3.getProbability() << "\n";

    //Testing | either event occuring
    event3.setProbability(event1 | event2);    
    std::cout<< event1.getProbability() << " | "<<event2.getProbability()<<" = "<< event3.getProbability() << "\n";

    //Testing ^ either but not both events occuring 
    event3.setProbability(event1 ^ event2);    
    std::cout<< event1.getProbability() << " ^ "<<event2.getProbability()<<" = "<< event3.getProbability() << "\n";

    //Testing A - B event A occuring but not B 
    event3.setProbability(event1 - event2);    
    std::cout<< event1.getProbability() << " - "<<event2.getProbability()<<" = "<< event3.getProbability() << "\n";

    //Testing B - A event B occuring but not A 
    event3.setProbability(event2 - event1);    
    std::cout<< event2.getProbability() << " - "<<event1.getProbability()<<" = "<< event3.getProbability() << "\n";

    //Testing ~A event A NOT occuring 
    event3.setProbability(~event1);    
    std::cout<<  " ~ "<<event1.getProbability()<<" = "<< event3.getProbability() << "\n";

    //Testing ~B event B NOT occuring 
    event3.setProbability(~event2);    
    std::cout<<  " ~ "<<event2.getProbability()<<" = "<< event3.getProbability() << "\n";




}