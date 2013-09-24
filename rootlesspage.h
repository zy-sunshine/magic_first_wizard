#ifndef ROOTLESSPAGE_H
#define ROOTLESSPAGE_H

#include <QWizardPage>

class QWidget;
class QLabel;
class QCheckBox;
class QLineEdit;

class RootlessPage : public QWizardPage
{
    public:
        RootlessPage( QWidget* parent = 0 );
    private:
        QLabel* label;
        QCheckBox* allowrootless;
    protected:
        void initializePage();
};

#endif // ROOTLESSPAGE_H
