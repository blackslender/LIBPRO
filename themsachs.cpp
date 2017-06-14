#include "themsachs.h"
#include "ui_themsachs.h"
#include "book.h"
#include "messagebox.h"
#include <QVariant>
#include <QtWidgets>
ThemSachs::ThemSachs(QSqlDatabase *db, MODE mode,QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::ThemSachs)
{
    ui->setupUi(this);
    ui->spinSoLuong->setMinimum(1);
    ui->spinSoLuong->setMaximum(10000);
    ui->dateNhap->setDisplayFormat("dd/MM/yyyy");
    ui->dateNhap->setDate(QDate::currentDate());
    ui->txtGia->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,9}"),this));
    this->db=db;
    this->mode=mode;
    this->id=id;
    Init=false;
    if(mode==EDIT)
        {
            ui->btnAdd->setText("OK");
            book=new BOOK(id,db);
            Init=true;
            if(book->getLastError()!=BOOK::SUCCESS)
            {
                QMessageBox::critical(this,"Lỗi","Load dữ liệu thất bại");
                return;
            }
            ui->txtName->setText(book->getTenSach());
            ui->txtAuthor->setText(book->getTacGia());
            ui->txtContent->setText(book->getNoiDung());
            ui->txtGia->setText(QString::number(book->getGiaTien()));
            ui->txtNxb->setText(book->getNXB());
            ui->txtType->setText(book->getLoaiSach());
            ui->dateNhap->setDate(book->getNgayNhap());
            ui->checkBox->setChecked(book->isDuocMuon());
            ui->spinSoLuong->setValue(book->getSoLuong());
        }
}

ThemSachs::~ThemSachs()
{
    if(Init)
    delete book;
    delete ui;
}

void ThemSachs::Reset()
{
    ui->txtAuthor->clear();
    ui->txtContent->clear();
    ui->txtGia->clear();
    ui->txtName->clear();
    ui->txtNxb->clear();
    ui->txtType->clear();
    ui->spinSoLuong->setValue(1);
    ui->dateNhap->setDate(QDate::currentDate());
}


void ThemSachs::on_btnAdd_clicked()
{
    BOOK::BERROR error;
    if(mode==ADD)
    {
        book=new BOOK();
        Init=true;
    }
    book->setTenSach(ui->txtName->text());
    book->setTacGia(ui->txtAuthor->text());
    book->setSoLuong(ui->spinSoLuong->value());
    book->setDuocMuon(ui->checkBox->isChecked());
    book->setGiaTien(ui->txtGia->text().toInt());
    book->setLoaiSach(ui->txtType->text());
    book->setNgayNhap(ui->dateNhap->date());
    book->setNoiDung(ui->txtContent->toPlainText());
    book->setNXB(ui->txtNxb->text());
    if(mode==ADD) error=BOOK::Insert(db,*book);
    else
    {
        book->Commit();
        error=(BOOK::BERROR)book->getLastError();
    }
    if(error!=BOOK::SUCCESS)
    {
        QMessageBox::critical(this,"Lỗi","Không thể thêm/cập nhật sách");

    }
    else
    {
        if(mode==EDIT)
        {
            this->close();
            return;
        }
        MyMessageBox *msb=new MyMessageBox();
        msb->setWindowTitle("Thành công");
        msb->setText("Đã thêm sách vào cơ sở dữ liệu");
        msb->settimeout(1);
        msb->setautoClose(true);
        msb->show();
        Reset();
    }
}

void ThemSachs::on_btnExit_clicked()
{
    done(0);
}
