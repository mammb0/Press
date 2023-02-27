#pragma once

#include "Tablet.h"
#include <QList>

class Boat
{
private:
    int id_Boat;
    double m_Boat_max = 5000; //масса таблеток в 1 лодочке <= 5кг (ЧТЗ_Участок прессования таблеток, с.8)

public:
    double m_Boat = 0;
    int tablet_in_boat; //N_таблеток текущее
    double t_start;
    double t_end;
    QList<Tablet> Tablet_List_Boat;

    Boat(int id_Boat);

    void Mass_Boat(double m_Tablet); //увеличение массы лодочки при загрузке таблетоки (передавать массу таблетки так как таблетки разные)
    bool Mass_Boat_Check(); //проверить заполненность по массе
    void Tablet_In_Boat(); //инкрементация количества таблеток (для рассчета эффективности)
    double Efficiency_Factor(); //Расчёт удельного потребления ресурсов на эту лодочку ()
    bool Boat_Warning();
};

