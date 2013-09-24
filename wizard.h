#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>
#include <QProcess>
#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QDir>

#include <QTextCursor>

#include "intropage.h"
#include "netcardpage.h"

#include "startcfgpage.h"
//#include "tcpipinfopage.h"
#include "tcpipcfgpage.h"
#include "dnscfgpage.h"
#include "rootlesspage.h"
#include "bootactivatepage.h"
#include "conclusionpage.h"
#include "thankspage.h"
class QWidget;

class Wizard : public QWizard
{
    Q_OBJECT
    public:
        Wizard( QWidget* parent = 0 );
        void accept();
        static int currentNetcard;
        static QStringList netcardList;
        static QMap<int, QString> netcardDeviceMap;
private:
        ThanksPage             *thanksPage;
        void initialize();
    public slots:
        void slot_finishProcess(bool);
signals:
        void sig_runProcess();

};

#endif // WIZARD_H
