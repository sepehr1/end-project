#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/M.sepehr/Desktop/5.jpg");
    ui->aks->setPixmap(pix);


    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/M.sepehr/Desktop/database.db");
    if(!db.open()){
        qDebug()<<db.lastError();
        return;
}
    model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM vahed",db);
    view = new QTableView(ui->stackedWidget->widget(1));
    view->setFixedWidth(300);
    view->setFixedHeight(200);
    view->setModel(model);

    view->show();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QSqlQuery qry;

    if(qry.exec("select * from student where password='"+ ui->lineEdit_2->text() +"'and username='" + ui->lineEdit->text()+"' "))
    {
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count==1) {
            ui->stackedWidget->setCurrentIndex(1);
            ui->label_5->hide();

        }
        if(count<1) {
            QMessageBox::information(this,"Error","گذرواژه غلط است");
        }
        if(count>1)
            QMessageBox::information(this,"Error","double");
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery qry;
    if(qry.exec("select * from vahed where code='"+ ui->lineEdit_11->text() +"'"))
        {
            int count=0;
            while(qry.next()){
                count++;
            }
        if(count==1){

        qry.prepare("update vahed set fill=fill+1 where code='"+ui->lineEdit_11->text()+"'");

              if(qry.exec()) {
                  ui->label_5->setText("انجام شد");
                  ui->label_5->show();
                  model->setQuery("SELECT * FROM vahed",db);
              }
              qry.prepare("insert into rabet (code,pass)values('"+ui->lineEdit_11->text()+"','"+ui->lineEdit_2->text()+"')");
              qry.exec();

           }
    else{
       ui->label_5->setText("انجام نشد");
       ui->label_5->show();
    }}
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_5_clicked()
{
    QSqlQuery qry;
    qry.prepare("insert into student (username,password,id)values('"+ui->lineEdit_3->text()+"','"+ ui->lineEdit_4->text()+"','"+ ui->lineEdit_5->text()+"')");
    qry.exec();

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    model1=new QSqlQueryModel;
    model1->setQuery("SELECT code FROM rabet where pass='"+ui->lineEdit_2->text()+"' ",db);
    view1 = new QTableView(ui->stackedWidget->widget(3));
    view1->setFixedWidth(300);
    view1->setFixedHeight(200);
    view1->setModel(model1);

    view1->show();
}

void MainWindow::on_pushButton_8_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}
