#ifndef TCPIPCFGPAGE_H
#define TCPIPCFGPAGE_H

#include <QWizardPage>

class QWidget;
class QLabel;
class QRadioButton;
class QLineEdit;

class TCPIPCfgPage : public QWizardPage
{
    public:
        TCPIPCfgPage( QWidget* parent = 0 );
    private:
        QLabel* label;
        QLabel* labelip;
        QLabel* labelnetmask;
        QLabel* labelGateway;
        QRadioButton* dhcpbutton;
        QRadioButton* manualbutton;
        QLineEdit* ip;
        QLineEdit* netmask;
        QLineEdit* gateway;
    protected:
        void initializePage();
};

#endif // TCPIPCFGPAGE_H
