#include "Press.h"
/*
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
*/

Press::Press(int* Press_Param){
    this->d_Tablet = Press_Param[0];
    this->h_Tablet = Press_Param[1];
    this->n_Press = Press_Param[2];
    this->n_catch = Press_Param[3];
    this->n_install = Press_Param[4];
    this->v_in_Press = Press_Param[5];
    this->v_out_Press = Press_Param[6];
    this->f_Press0 = Press_Param[7];
    this->f_Press1 = Press_Param[8];
    this->t_in = Press_Param[9];
    this->t_out = Press_Param[10];
}

int* Press::Press_Param_Value(){
    int Press_Param[11];
    Press_Param[0] = this->d_Tablet;
    Press_Param[1] = this->h_Tablet;
    Press_Param[2] = this->n_Press;
    Press_Param[3] = this->n_catch;
    Press_Param[4] = this->n_install;
    Press_Param[5] = this->v_in_Press;
    Press_Param[6] = this->v_out_Press;
    Press_Param[7] =this->f_Press0;
    Press_Param[8] = this->f_Press1;
    Press_Param[9] = this->t_in;
    Press_Param[10] =this->t_out;
    return Press_Param;
}

bool Press::Start(){
    if (this->signal && this->status)
        return true;
    else
        return  false;
}

void Press::Risk(){
    ;
}

void Press::PPR_Time(){
    this->PPR ++;
}

bool Press::PPR_Status(){
    if (this->PPR > this->PPR_max)
        return true;
    else
        return false;
}

bool Press::PPR_Warning(){
    ;
}

void Press::PPR_Update(int PPR){
    this->PPR_max = PPR;
}
