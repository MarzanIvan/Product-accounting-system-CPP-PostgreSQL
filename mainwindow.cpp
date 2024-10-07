#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    auto fileName = QFileDialog::getOpenFileName(this,
        tr("Open docx"), "", tr("Docx Files (*.docx)"));
    duckx::Document doc(fileName.toStdString());
    doc.open();

    if (!doc.is_open()) {
        this->ui->Text1->appendPlainText("File not founded!");
        return;
    }

    for (auto p = doc.paragraphs(); p.has_next(); p.next()) {
        for (auto r = p.runs(); r.has_next(); r.next()) {
            this->ui->Text1->appendPlainText(r.get_text().c_str());
            this->ui->Text1->appendPlainText("\n");
        }
    }
    doc.save();
}

