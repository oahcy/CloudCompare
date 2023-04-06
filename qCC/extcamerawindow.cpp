#include "extcamerawindow.h"
#include "ui_extcamerawindow.h"

extCameraWindow::extCameraWindow(ccGLWindow* glWin, QWidget* parent) :
  QWidget(parent),
  m_glWin(glWin),
  ui(new Ui::extCameraWindow)
{
  ui->setupUi(this);
  //ui->cameraWidget->setStyleSheet("background-color:black;");
  ui->horizontalLayout->setAlignment(Qt::AlignLeft);
  addGlView(m_glWin);
}

void extCameraWindow::addGlView(ccGLWindow* glWin) {
  assert(glWin);
  glWin->setParent(ui->cameraWidget);
  ui->cameraWidget->layout()->addWidget(glWin);
}

extCameraWindow::~extCameraWindow()
{
  delete ui;
}