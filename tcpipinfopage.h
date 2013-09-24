#ifndef TCPIPINFOPAGE_H
#define TCPIPINFOPAGE_H

#include <QWizardPage>

class QWidget;
class QLabel;

class TCPIPInfoPage : public QWizardPage
{
    public:
        TCPIPInfoPage( QWidget* parent = 0 );
    private:
        QLabel* label;
};

#endif // TCPIPINFOPAGE_H
