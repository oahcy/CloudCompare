#ifndef EXTCAMERAWINDOW_H
#define EXTCAMERAWINDOW_H

#include <QWidget>
#include "ccGLWindow.h"

namespace Ui {
class extCameraWindow;
}

class extCameraWindow : public QWidget, public iGlWinInterface
{
  Q_OBJECT

public:
  explicit extCameraWindow(ccGLWindow* glWin, QWidget* parent = nullptr);
  ~extCameraWindow();
  ccGLWindow* getGlWindow() { return m_glWin; }

  virtual QWidget* getGlWin() final {
    return m_glWin;
  }

private:
  void addGlView(ccGLWindow* glWin);

private:
  Ui::extCameraWindow* ui;
  ccGLWindow* m_glWin;
};


#endif // EXTCAMERAWINDOW_H
