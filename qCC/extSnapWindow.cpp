#include "extsnapwindow.h"
#include "ui_extsnapwindow.h"
#include <qtextedit.h>

extSnapWindow::extSnapWindow(ccGLWindow* glWin, QWidget *parent) :
    QWidget(parent),
    m_glWin(glWin),
    ui(new Ui::extSnapWindow)
{
    ui->setupUi(this);
    //ui->glwidget->setStyleSheet("background-color:black;");
    ui->horizontalLayout->setAlignment(Qt::AlignLeft);
    addGlView(m_glWin);
}

void extSnapWindow::addGlView(ccGLWindow* glWin) {
  assert(glWin);
  glWin->setParent(ui->glwidget);
  ui->glwidget->layout()->addWidget(glWin);
}

extSnapWindow::~extSnapWindow()
{
    delete ui;
}
