#include "muonsach.h"
#include "phieumuon.h"
#include "ui_muonsach.h"
#include <QMessageBox>

MuonSach::MuonSach(int user,int id,QSqlDatabase *db, int mode,QWidget *parent) :book(id,db),
    QDialog(parent),
    ui(new Ui::MuonSach)
{
    this->user=user;
    ui->setupUi(this);
    this->db=db;
    this->mode=mode;
    DialogLoad(mode);
    connect(ui->dateLay,SIGNAL(dateChanged(QDate)),this,SLOT(on_DateChanged(QDate)));
}
void MuonSach::on_DateChanged(QDate Date)
{
    ui->dateTra->setMinimumDate(Date.addDays(1));
}

MuonSach::~MuonSach()
{
    delete ui;
}
void MuonSach::DialogLoad(int mode)
{
    ui->txtName->setText(book.getTenSach());
    ui->SoLuong->setMinimum(1);
    ui->SoLuong->setMaximum(5);
    ui->txtAuthor->setText(book.getTacGia());
    ui->txtCost->setText(QString::number(book.getGiaTien()));
    ui->txtNum->setText(QString::number(book.getSoLuong()));
    ui->dateLay->setMinimumDate(QDate::currentDate());
    ui->dateTra->setMinimumDate(ui->dateLay->date().addDays(1));
    PhieuMuon phieu(user,book.getID(),db);
    ui->SoLuong->setValue(phieu.getSoLuong());
    ui->txtType->setText(book.getLoaiSach());
    switch(mode)
    {
    case ADDTO:
    case UPDATE:
        ui->SoLuong->setEnabled(true);
        ui->dateLay->setEnabled(true);
        ui->dateTra->setEnabled(true);
        break;
    case VIEW:
        ui->SoLuong->setEnabled(false);
        ui->dateLay->setEnabled(false);
        ui->dateTra->setEnabled(false);
        break;

    }
}


void MuonSach::on_buttonBox_accepted()
{
    int res=PhieuMuon::SUCCESS;

    if(mode== ADDTO)
        res=PhieuMuon::Insert(user,book.getID(),ui->dateLay->date(),ui->dateTra->date(),ui->SoLuong->value(),db);
    else if(mode==UPDATE)
    {
        PhieuMuon phieu(user,book.getID(),db);
        phieu.setSoLuong(ui->SoLuong->value());
        phieu.setNgayTra(ui->dateTra->date());
        phieu.setNgayMuon(ui->dateLay->date());
        phieu.setDaMuon(0);
        phieu.Commit();
        res=phieu.getLastError();
    }
    else if(mode==VIEW)
        {
            res=PhieuMuon::SUCCESS;
            return;
        }

    if(res!=PhieuMuon::SUCCESS)
    {
        QMessageBox::critical(this,"Lỗi",PhieuMuon::ErrortoString((PhieuMuon::PMERROR)res));
    }
}

