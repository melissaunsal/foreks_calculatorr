#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <math.h>
#include <QtCore/qmath.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>


double firstNum=0.0;
bool userIsTypingSecondNumber=false;
bool userIsTypingValueNumber=false;
bool add=false;

MainWindow::MainWindow(QWidget *parent):
 QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->lineEdit->setValidator( new QDoubleValidator(0, 100, 2, this) );
connect(ui->one_button, &QPushButton::clicked , this, &MainWindow::digit_pressed);
connect(ui->zero_button, &QPushButton::clicked , this, &MainWindow::digit_pressed);
connect(ui->two_button, &QPushButton::clicked , this, &MainWindow::digit_pressed);
connect(ui->tree_button, &QPushButton::clicked , this, &MainWindow::digit_pressed);
connect(ui->four_button, &QPushButton::clicked , this, &MainWindow::digit_pressed);
connect(ui->five_button, &QPushButton::clicked , this, &MainWindow::digit_pressed);
connect(ui->six_button, &QPushButton::clicked , this, &MainWindow::digit_pressed);
connect(ui->seven_button, &QPushButton::clicked , this, &MainWindow::digit_pressed);
connect(ui->eight_button, &QPushButton::clicked , this, &MainWindow::digit_pressed);
connect(ui->nine_button, &QPushButton::clicked , this, &MainWindow::digit_pressed);
connect (ui->arteksi_button, &QPushButton::clicked, this , &MainWindow::unary_operation_pressed);
connect(ui->collection_button,&QPushButton::clicked, this ,&MainWindow::binary_operation_pressed);
connect (ui->extraction_button,&QPushButton::clicked, this, &MainWindow::binary_operation_pressed);
connect (ui->yuzde_button, &QPushButton::clicked, this , &MainWindow::unary_operation_pressed);
connect(ui->impack_button, &QPushButton::clicked, this , &MainWindow::binary_operation_pressed);
connect(ui->divide_button, &QPushButton::clicked , this , &MainWindow::binary_operation_pressed);
connect(ui->delete_button, &QPushButton::clicked , this , &MainWindow::binary_operation_pressed);
connect(ui->sqrt_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->x2_button_2, &QPushButton::clicked , this , &MainWindow::on_x_button_clicked);
connect(ui->pi_button, &QPushButton::clicked , this , &MainWindow::on_pi_button_clicked);
connect(ui->treen_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->tan_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->sin_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->cos_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->tanA_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->sinA_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->cosA_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->exp_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->xf_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->x2_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->floor_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->log_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->lnx_button, &QPushButton::clicked , this , &MainWindow::on_tri_button_released);
connect(ui->collection_button, &QPushButton::clicked , this , &MainWindow::on_collection_button_clicked);
//connect(ui->ext_button, SIGNAL(clicked()), this, SLOT(close()));




ui->collection_button->setCheckable(true);
ui->impack_button->setCheckable(true);
ui->extraction_button->setCheckable(true);
ui->divide_button->setCheckable(true);
ui->sqrt_button->setCheckable(true);
ui->treen_button->setCheckable(true);
ui->tan_button->setCheckable(true);
ui->sin_button->setCheckable(true);
ui->tanA_button->setCheckable(true);
ui->sinA_button->setCheckable(true);
ui->cosA_button->setCheckable(true);
ui->cos_button->setCheckable(true);
ui->exp_button->setCheckable(true);
ui->xf_button->setCheckable(true);
ui->x2_button->setCheckable(true);
ui->floor_button->setCheckable(true);
ui->log_button->setCheckable(true);
ui->equal_button->setCheckable(true);
ui->lnx_button->setCheckable(true);
ui->frame_6->setVisible(false);
ui->frame_5->setVisible(false);
}

MainWindow::~MainWindow()
{
}

void MainWindow::digit_pressed()
{
 QPushButton*button=(QPushButton*)sender();
    double labelNumber;
    QString newLabel;

if((ui->equal_button->isChecked()||ui->collection_button->isChecked()||ui->extraction_button->isChecked()||ui->impack_button->isChecked()||ui->divide_button->isChecked())&& (!userIsTypingSecondNumber))
{
labelNumber= button ->text().toDouble();

  newLabel=QString::number(labelNumber);




    userIsTypingSecondNumber=true;

}
else{
if(ui->lineEdit->text().contains('.')&&button->text()=="0")
{
newLabel=ui->lineEdit->text()+button->text();
}
else {

    labelNumber=(ui->lineEdit->text() + button ->text()).toDouble();
newLabel=QString::number(labelNumber,'g',15);

    }

}


 ui->lineEdit->setText(newLabel);
}


void MainWindow::on_poin_button_released()
{

    if(!(ui->lineEdit->text().contains('.')))
      ui->lineEdit->setText(ui->lineEdit->text()+".");

    }
    void MainWindow::unary_operation_pressed(){
    QPushButton* button=(QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if (button->text()=="+/-"){
    labelNumber=ui-> lineEdit->text().toDouble();
    labelNumber=labelNumber* -1;
    newLabel=QString::number(labelNumber,'g', 15);
    ui->lineEdit->setText(newLabel);



    }
    if (button->text()=="%"){
    labelNumber=ui->lineEdit->text().toDouble();

    labelNumber=labelNumber*0.01;
    newLabel= QString ::number(labelNumber,'g', 15);
    ui->lineEdit->setText(newLabel);
   newLabel= QString::number(labelNumber)+"%";
    ui->label_field->setText(newLabel);

  }
    QFile file("C:/Users/ADMIN/Desktop/foreks_calculatorr/foreks_calculatorr/data.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text| QIODevice::Append ))
        return;

    QTextStream data(&file);

    data << newLabel << "\n";


    file.close();
     ui->listWidget->addItem( newLabel);

}



void MainWindow::on_clear_button_released()
{
ui->collection_button->setChecked(false);
ui->extraction_button->setChecked(false);
ui->divide_button->setChecked(false);
ui->impack_button->setChecked(false);
ui->lineEdit->setText("0");

userIsTypingSecondNumber=false;

}


void MainWindow::on_equal_button_released()
{
double labelNumber,secondNum ;
QString newLabel;
secondNum=ui->lineEdit->text().toDouble();
if(ui->collection_button->isChecked())
{
labelNumber=firstNum + secondNum;
newLabel= QString::number(labelNumber,'g',15);
ui->lineEdit->setText(newLabel);
newLabel= QString::number(firstNum)+"+"+QString::number(secondNum)+"="+QString::number(labelNumber);
ui->label_field->setText(newLabel);
ui->collection_button->setChecked(true);


}
else if(ui->impack_button->isChecked()){
    labelNumber=firstNum  * secondNum;
    newLabel= QString::number(labelNumber,'g',15);
    ui->lineEdit->setText(newLabel);
    newLabel= QString::number(firstNum)+"*"+QString::number(secondNum)+"="+QString::number(labelNumber);
    ui->label_field->setText(newLabel);
    ui->impack_button->setChecked(false);


}
else if(ui->equal_button->isChecked()){
   ui->equal_button->setChecked(true);
}

else if (ui->extraction_button->isChecked()){
    labelNumber=firstNum - secondNum;
    newLabel= QString::number(labelNumber,'g',15);
    ui->lineEdit->setText(newLabel);
    newLabel= QString::number(firstNum)+"-"+QString::number(secondNum)+"="+QString::number(labelNumber);
    ui->label_field->setText(newLabel);
    ui->extraction_button->setChecked(false);
}
else if (ui->divide_button->isChecked()){
   labelNumber =firstNum/secondNum;
    newLabel= QString::number(labelNumber,'g',15);
    ui->lineEdit->setText(newLabel);

newLabel= QString::number(firstNum)+"/"+QString::number(secondNum)+"="+QString::number(labelNumber);
    ui->label_field->setText(newLabel);
    ui->divide_button ->setChecked(false);
}

userIsTypingSecondNumber= false;

QFile file("C:/Users/ADMIN/Desktop/foreks_calculatorr/foreks_calculatorr/data.txt");
if (!file.open(QIODevice::ReadWrite | QIODevice::Text| QIODevice::Append ))
    return;

QTextStream data(&file);

data << newLabel << "\n";
QString widgetItem;
 widgetItem =ui->label_field->text() ;
 ui->listWidget->addItem(widgetItem);

file.close();

}

void MainWindow::binary_operation_pressed()
{
QPushButton* button= (QPushButton*) sender();
firstNum=ui->lineEdit->text().toDouble();
button->setChecked(true);


}

void MainWindow::on_delete_button_clicked()
{


    QString lineEdit = ui->lineEdit->text();


       if (lineEdit.length() == 1) {
           ui->lineEdit->setText("0");
           return ;
       }


       lineEdit.QString::chop(1);

       ui->lineEdit->setText(lineEdit);

}

void MainWindow::on_sqrt_button_clicked()
{


}

void MainWindow::on_x_button_clicked()
{
    QString currentValue = ui->lineEdit->text();
    double result = 1 / currentValue.toDouble();
    ui->lineEdit->setText(QString::number(result));
    currentValue="1/"+currentValue+"="+QString :: number (result);
     ui->label_field->setText(currentValue);


}


void MainWindow::on_pi_button_clicked()
{
     ui->lineEdit->setText("3.14");
}



void MainWindow::on_tri_button_released()
{
    double labelNumber,secondNum ;
    QString newLabel;
    QString pw;
    firstNum=ui->lineEdit->text().toDouble();
    if(ui->treen_button->isChecked()){
        labelNumber=firstNum * firstNum *firstNum;
        newLabel= QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
        ui->label_field->setText(QString::number(firstNum)+"^3="+newLabel);
        ui->treen_button->setChecked(false);}
    else if(ui->tan_button->isChecked()){
     labelNumber = qTan(firstNum);
     newLabel= QString::number(labelNumber,'g',15);
     ui->lineEdit->setText(newLabel);
        ui->label_field->setText("tan("+QString::number(firstNum)+")="+newLabel);
        ui->tan_button->setChecked(false);}
    else if(ui->sin_button->isChecked()){
     labelNumber = qSin(firstNum);
     newLabel= QString::number(labelNumber,'g',15);
     ui->lineEdit->setText(newLabel);
        ui->label_field->setText("sin("+QString::number(firstNum)+")="+newLabel);
        ui->sin_button->setChecked(false);}
    else if(ui->tanA_button->isChecked()){
     labelNumber = qAtan(firstNum);
     newLabel= QString::number(labelNumber,'g',15);
     ui->lineEdit->setText(newLabel);
      ui->label_field->setText("tanA("+QString::number(firstNum)+")="+newLabel);
        ui->tanA_button->setChecked(false);}
    else if(ui->sinA_button->isChecked()){
     labelNumber =qAsin(firstNum);
     newLabel= QString::number(labelNumber,'g',15);
     ui->lineEdit->setText(newLabel);
     ui->label_field->setText("sinA("+QString::number(firstNum)+")="+newLabel);
     ui->cos_button->setChecked(false);}
    else if(ui->cos_button->isChecked()){
     labelNumber = qCos(firstNum);

     newLabel= QString::number(labelNumber,'g',15);
     ui->lineEdit->setText(newLabel);
        ui->label_field->setText("cos("+QString::number(firstNum)+")="+newLabel);
      ui->cos_button->setChecked(false);}


    else if(ui->cosA_button->isChecked()){
     labelNumber =qAsin(firstNum);
     newLabel= QString::number(labelNumber,'g',15);
     ui->lineEdit->setText(newLabel);
      ui->label_field->setText("cosA("+QString::number(firstNum)+")="+newLabel);
       ui->cosA_button->setChecked(false);
    }
    else if(ui->exp_button->isChecked()){
     labelNumber =qExp(firstNum);
     newLabel= QString::number(labelNumber,'g',15);
     ui->lineEdit->setText(newLabel);
      ui->label_field->setText(QString::number(firstNum)+"exp="+newLabel);
      ui->exp_button->setChecked(false);}

    else if(ui->xf_button->isChecked()){
        int factorial=1;
        int i;
        for (i=1; i <=firstNum; i++)
           {
               factorial = factorial * i;
           }

        newLabel= QString::number(factorial,'g',15);
        ui->lineEdit->setText(newLabel);
         ui->label_field->setText(QString::number(firstNum)+"!="+newLabel);
        ui->xf_button->setChecked(false);

}
     else if(ui->x2_button->isChecked()){
        labelNumber=firstNum * firstNum ;
        newLabel= QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
        ui->label_field->setText(QString::number(firstNum)+"^2="+newLabel);
  ui->x2_button->setChecked(false);
    }

    else if (ui->log_button->isChecked()){
        labelNumber=log10(firstNum) ;
        newLabel= QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
        ui->label_field->setText("log("+QString::number(firstNum)+")="+newLabel);
          ui->log_button->setChecked(false);
    }
    else if (ui->lnx_button->isChecked()){
        labelNumber=qLn(firstNum) ;
        newLabel= QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
        ui->label_field->setText("lnx("+QString::number(firstNum)+")="+newLabel);
          ui->lnx_button->setChecked(false);
    }
    else if (ui->floor_button->isChecked()){
        labelNumber=qFloor(firstNum) ;
        newLabel= QString::number(labelNumber,'g',15);
        ui->lineEdit->setText(newLabel);
        ui->label_field->setText("floor("+QString::number(firstNum)+")="+newLabel);

          ui->floor_button->setChecked(false);

    }
    else if(ui->sqrt_button->isChecked()){
        QString currentValue = ui->lineEdit->text();
        double newLabel = sqrt(currentValue.toDouble());
        ui->lineEdit->setText(QString::number(newLabel));
        ui->label_field->setText("sqrt("+currentValue+")="+QString::number(newLabel));
        ui->sqrt_button->setChecked(false);
    }

    userIsTypingSecondNumber= false;
    QFile file("C:/Users/ADMIN/Desktop/foreks_calculatorr/foreks_calculatorr/data.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text| QIODevice::Append ))
        return;

    QTextStream data(&file);

    data << ui->label_field->text()<< "\n";

    QString widgetItem;
     widgetItem =ui->label_field->text() ;
     ui->listWidget->addItem(widgetItem);
    file.close();

}

void MainWindow::on_ext_button_clicked()
{

    ui->frame_6->setVisible(ui->ext_button->isChecked());
}

void MainWindow::on_list_delete_released()
{
    QModelIndexList selectedList = ui->listWidget->selectionModel()->selectedIndexes();
    std::sort(selectedList.begin(),selectedList.end(),[](const QModelIndex& a, const QModelIndex& b)->bool{return a.row()>b.row();});
    for(const QModelIndex& singleIndex : selectedList)
    ui->listWidget->model()->removeRow(singleIndex.row());
}

void MainWindow::on_collection_button_clicked()
{

}
