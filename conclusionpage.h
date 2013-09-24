#ifndef CONClUSIONPAGE_H
#define CONClUSIONPAGE_H

#include <QWizardPage>

class QWidget;
class QLabel;

class ConclusionPage : public QWizardPage
{
    Q_OBJECT
    public:
        ConclusionPage( QWidget* parent = 0 );
        virtual bool validatePage();
    protected:
        void initializePage();
    private:
        QLabel* label;
};

#endif // CONClUSIONPAGE_H
