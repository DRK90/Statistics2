#include <iostream>

class Event
{
public:
    Event(double probability)
    {
        if (probability >= 0 && probability <= 1)
        {
            eventProbability = probability;
        }
        else
        {
            double x = -1;
            while (probability < 0 || probability > 1)
            {
                std::cout << "Probability must be between 0 and 1\n Enter it again: ";
                std::cin >> x;
                probability = x;
                eventProbability = probability;
            }
        }
    }

    Event operator&(Event newEvent)
    {
        double newProbability;
        newProbability = this->getProbability() * newEvent.getProbability();
        Event returnEvent(newProbability);
        return returnEvent;
    }

    Event operator|(Event newEvent)
    {
        double newProbability;
        newProbability = this->getProbability() + newEvent.getProbability() - (this->getProbability() * newEvent.getProbability());
        Event returnEvent(newProbability);
        return returnEvent;
    }

    Event operator^(Event newEvent)
    {
        double newProbability;
        newProbability = this->getProbability() + newEvent.getProbability() - 2*(this->getProbability() * newEvent.getProbability());
        Event returnEvent(newProbability);
        return returnEvent;
    }

    Event operator-(Event newEvent)
    {
        double newProbability;
        newProbability = this->getProbability() * (1 - newEvent.getProbability());
        Event returnEvent(newProbability);
        return returnEvent;
    }

    Event operator~()
    {
        double newProbability;
        newProbability = 1 - this->getProbability();
        Event returnEvent(newProbability);
        return returnEvent;
    }

    double getProbability()
    {
        return eventProbability;
    }

    void setProbability(Event probability)
    {
        eventProbability = probability.getProbability();
    }

private:
    double eventProbability;
};

