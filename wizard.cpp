#include "wizard.h"
int Wizard::currentNetcard;
QStringList Wizard::netcardList;
QMap<int, QString> Wizard::netcardDeviceMap;
Wizard::Wizard( QWidget* parent )
    : QWizard( parent )
{
    initialize();
    thanksPage = new ThanksPage();
    int pagecount=1;
    setPage(pagecount, new IntroPage );pagecount++;
    setPage(pagecount, new NetCardPage );pagecount++;
    for(int i=0; i < netcardList.count(); ++i){
        setPage(pagecount, new StartCfgPage );pagecount++;
        //setPage(pagecount, new TCPIPInfoPage );pagecount++;
        setPage(pagecount, new TCPIPCfgPage );pagecount++;

        setPage(pagecount, new RootlessPage );pagecount++;
        setPage(pagecount, new BootActivatePage );pagecount++;
        setPage(pagecount, new ConclusionPage );pagecount++;
    }
    setPage(pagecount, new DNSCfgPage );pagecount++;
    setPage(pagecount, thanksPage );pagecount++;
    setStartId(1);
    connect(this, SIGNAL(sig_runProcess()), thanksPage, SLOT(slot_runProcess()));
    connect(thanksPage, SIGNAL(sig_finishProcess(bool)), this, SLOT(slot_finishProcess(bool)));
    setWindowTitle( tr(gtr( "magic linux Wizard" )) );
}
void Wizard::initialize(){
    currentNetcard=-1;
    netcardList = QDir( "/sys/class/net" ).entryList( QStringList( "eth*" ) );
    QStringList::const_iterator it = netcardList.begin();
    for(int i=0; it!= netcardList.end(); ++it, ++i){
        netcardDeviceMap[i] = *it;
    }
}
void Wizard::accept()
{
    // finish TODO:
    emit sig_runProcess();
}

void Wizard::slot_finishProcess(bool ret)
{
    QString retStr;
    if(ret){
        retStr = tr(gtr("Success!"));
        QMessageBox::information(this, tr(gtr("Result")), tr(gtr("Restart NetCard %1\nWill close the Wizard")).arg(retStr));
        QDialog::accept();
    }else{
        retStr = tr(gtr("Failed!"));
        QMessageBox::information(this, tr(gtr("Result")), tr(gtr("Restart NetCard %1\nPlease Check The netCard Infomation")).arg(retStr));
    }
}
