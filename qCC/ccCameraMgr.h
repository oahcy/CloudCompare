#ifndef CC_CAMERA_MGR_HEADER
#define CC_CAMERA_MGR_HEADER

//Qt
#include <QWindow>
#include <QTHREAD>
#include <qmutex>

#include <ccMainAppInterface.h>


class CaptureThread : public QThread {
    Q_OBJECT
public:
    CaptureThread() :mMutex() {}
    void run() override;
    std::function<void()> func;
    void triggerUpdate(void* ptr) {
        emit updateDb(ptr);
    }
    bool isExit = false;
    QMutex mMutex;

signals:
    void updateDb(void*);
};

class ViewDelegate {
private:
public:
    QWidget* createView();
    void closeAllView();
};

class DbDelegate {
public:
    bool loadNew3DDataToView(QString path, QWidget* view, bool clear = true);

};

class CaptureFileMgr {
public:
    static QString getCaptureFile();
    static QString copyCurrentCaptureFile();
};

class CameraMgr {
public:
    bool init(ViewDelegate* appPtr, DbDelegate* dbPtr);
    bool start();
    bool stop();
    bool snap();

private:
    void runCaptrueThread(bool run);
    void captureThread();

private:
    QWidget* m_rView = nullptr;
    QWidget* m_lView = nullptr;
    ViewDelegate* m_viewDelegate = nullptr;
    DbDelegate* m_dbDelegate = nullptr;
    bool m_isCapture = false;
};
#endif