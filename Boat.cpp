#include "Boat.h"

Boat::Boat(int id_Boat)
{
    this->id_Boat = id_Boat;
}

void Boat::Mass_Boat(double m_Tablet){
    this->m_Boat = this->m_Boat + m_Tablet;
}

bool Boat::Mass_Boat_Check(){
    if (this->m_Boat <= this->m_Boat_max)
        return true;
    else
        return false;
}

void Boat::Tablet_In_Boat(){
    this->tablet_in_boat ++;
}

double Boat::Efficiency_Factor(){
    return (this->t_end - this->t_start)/this->tablet_in_boat;
}

bool Boat::Boat_Warning(){
    ;
    //
}
