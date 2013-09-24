#include <locale.h>
#include <libintl.h>
#define gtr(string) gettext(string)
#include "thankspage.h"
#include "wizard.h"
ThanksPage::ThanksPage( QWidget* parent )
    : QWizardPage( parent )
{
    setTitle( tr(gtr( "Thanks" )) );
//     setPixmap( QWizard::WatermarkPixmap, QPixmap( "magic.png" ) );//TODO
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout( layout );

    label = new QLabel(tr(gtr("The Network configuration complete.\nPlease continue to experience MagicLinux!\nThank you!\n\nNotice:\nPlease wait for your network restart when press the finish button, making your configuration to take effect.")));
    label->setWordWrap( true );
    layout->addWidget( label );
    progressBar = new QProgressBar();

    progressBar->setValue(0);
    layout->addWidget(progressBar);
    systemOutput = new QTextEdit;

    layout->addWidget(systemOutput);

    process = new QProcess(this);
    connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(slot_readyReadStandardOutput()));
    connect(process,SIGNAL(readyReadStandardError()),this,SLOT(slot_readyReadStandardError()));
    connect(process,SIGNAL(finished(int)),this, SLOT(slot_finished(int)));
}
void ThanksPage::slot_runProcess()
{
    processRet = true;
    QList<QString> netcardList;
    for(int i=0; i < netcardList.count(); ++i){
    }

    process->start("/etc/init.d/network", QStringList() << "restart");
    process->waitForStarted();
    progressBar->setValue(3);
    //process->waitForFinished();
}
void ThanksPage::slot_finished(int){
    progressBar->setValue(100);
    emit sig_finishProcess(processRet);
}
void ThanksPage::slot_readyReadStandardOutput(){
    netCardNum = Wizard::netcardList.count();

        static int count = 0;
        QString rc=process->readAll();

        if (rc.contains(QString("Ê§°Ü"), Qt::CaseInsensitive)){
                processRet = false;
        }
        if (rc.contains(QRegExp("eth\\d+"))){
            if(count < netCardNum*2){
                count ++;
            }

            if(count % 2 == 0){
                value = 98/(netCardNum*2) * count;
            }
        }
        progressBar->setValue(value);
        systemOutput->append(tr(rc.trimmed().toLatin1()));
        systemOutput->moveCursor(QTextCursor::End);
}

void ThanksPage::slot_readyReadStandardError(){

        QString rc=process->readAllStandardError();

        systemOutput->append(tr(rc.trimmed().toLatin1()));
        systemOutput->moveCursor(QTextCursor::End);
}
