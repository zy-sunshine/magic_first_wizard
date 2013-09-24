#ifndef NETCARDPAGE_H
#define NETCARDPAGE_H

#include <QWizardPage>

class QWidget;
class QLabel;

class NetCardPage : public QWizardPage
{
    public:
        NetCardPage( QWidget* parent = 0 );
    private:
        QLabel* label;
};

#endif // NETCARDPAGE_H
