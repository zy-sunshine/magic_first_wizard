#ifndef DNSCFGPAGE_H
#define DNSCFGPAGE_H

#include <QWizardPage>

class QWidget;
class QLabel;
class QCheckBox;
class QLineEdit;

class DNSCfgPage : public QWizardPage
{
    public:
        DNSCfgPage( QWidget* parent = 0 );
        virtual bool validatePage();
    private:
        QLabel* label;
        QLabel* labelprimary;
        QLabel* labelsecondary;
        QCheckBox* primarybutton;
        QCheckBox* secondarybutton;
        QLineEdit* primarydns;
        QLineEdit* secondarydns;
};

#endif // DNSCFGPAGE_H
