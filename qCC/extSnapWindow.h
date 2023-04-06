#ifndef EXTSNAPWINDOW_H
#define EXTSNAPWINDOW_H

#include <QWidget>
#include "ccGLWindow.h"

namespace Ui {
class extSnapWindow;
}

class extSnapWindow : public QWidget, public iGlWinInterface
{
    Q_OBJECT

public:
    explicit extSnapWindow(ccGLWindow *glWin, QWidget *parent = nullptr);
    ~extSnapWindow();
    ccGLWindow* getGlWindow() { return m_glWin; }

    virtual QWidget* getGlWin() final {
      return m_glWin;
    }

private:
  void addGlView(ccGLWindow* glWin);

private:
    Ui::extSnapWindow *ui;
    ccGLWindow  *m_glWin;
};

#endif // EXTSNAPWINDOW_H
