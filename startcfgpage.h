#ifndef STARTCFGPAGE_H
#define STARTCFGPAGE_H

#include <QWizardPage>

class QWidget;
class QLabel;

class StartCfgPage : public QWizardPage
{
    public:
        StartCfgPage( QWidget* parent = 0 );

    protected:
        virtual void initializePage();
        virtual void cleanupPage();
    private:
        QLabel* label;
};

#endif // STARTCFGPAGE_H
