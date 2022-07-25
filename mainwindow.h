#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "history.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;




public slots:
void digit_pressed();

private slots:
void on_poin_button_released();
void  unary_operation_pressed();
void on_clear_button_released();
void on_equal_button_released();
void binary_operation_pressed();
void on_delete_button_clicked();
void on_sqrt_button_clicked();
void on_x_button_clicked();
void on_pi_button_clicked();
void on_tri_button_released();
void on_ext_button_clicked();
void on_list_delete_released();
void on_collection_button_clicked();
};

#endif // MAINWINDOW_H
