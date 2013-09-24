#ifndef THANKSPAGE_H
#define THANKSPAGE_H

#include <QWizardPage>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QProcess>
#include <QDebug>
#include <QStringList>
#include <QList>
#include <QTextEdit>
#include <QTextCodec>
#include <QLocale>

class QWidget;
class QLabel;

class ThanksPage : public QWizardPage
{
    Q_OBJECT
    public:
        ThanksPage( QWidget* parent = 0 );
    private:
        QLabel* label;
        QProgressBar *progressBar;
        QTextEdit *systemOutput;

        QProcess *process;
        int                           value;

        int netCardNum;
        bool processRet;
    public slots:
        void slot_runProcess();
    private slots:
        void slot_readyReadStandardOutput();
        void slot_readyReadStandardError();
        void slot_finished(int);
signals:
    void sig_finishProcess(bool);

};

#endif // THANKSPAGE_H
