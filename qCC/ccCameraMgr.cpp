#include "ccCameraMgr.h"

QWidget* ViewDelegate::createView() {

	return nullptr;
}

void ViewDelegate::closeAllView() {}

bool DbDelegate::loadNew3DDataToView(QString path, QWidget* view, bool clear) {
	return true;
}


bool CameraMgr::init(ViewDelegate* viewDelegate, DbDelegate* dbDelegate) {
	assert(viewDelegate);
	assert(dbDelegate);
	m_viewDelegate = viewDelegate;
	m_dbDelegate = dbDelegate;

	m_viewDelegate->closeAllView();
	m_rView = m_viewDelegate->createView();
	m_lView = m_viewDelegate->createView();
	return true;
}

bool CameraMgr::start() {
	if (!m_isCapture) {
		runCaptrueThread(true);
		m_isCapture = true;
	}
	return true;
}

bool CameraMgr::stop() {
	if (m_isCapture) {
		runCaptrueThread(false);
		m_isCapture = false;
	}
	return true;
}

void CameraMgr::runCaptrueThread(bool run) {

}

bool CameraMgr::snap() {
	QString path = CaptureFileMgr::copyCurrentCaptureFile();
	m_dbDelegate->loadNew3DDataToView(path, m_lView, false);
	return true;
}

void CameraMgr::captureThread() {
	m_dbDelegate->loadNew3DDataToView(CaptureFileMgr::getCaptureFile(), m_rView);
}

QString CaptureFileMgr::getCaptureFile() {
	return QString();
}

QString CaptureFileMgr::copyCurrentCaptureFile() {
	return QString();
}